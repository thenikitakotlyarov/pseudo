#include "parser.hpp"
#include "assign_node.hpp"
#include "print_node.hpp"
#include <stdexcept>
#include <iostream>

std::vector<std::unique_ptr<AstNode>> Parser::parse() {
    std::vector<std::unique_ptr<AstNode>> ast_nodes;
    while (currentToken.type != TokenType::END_OF_FILE) {
        std::cout << "Current token: " << currentToken.value << std::endl;

        auto node = statement();
        if (node) {
            ast_nodes.push_back(std::move(node));
        }
    }
    return ast_nodes;
}


void Parser::eat(TokenType tokenType) {
    if (currentToken.type == tokenType) {
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Unexpected token type");
        std::cout << "Unexpected token type: " << currentToken.value << std::endl;
        currentToken = lexer.getNextToken();
    }
}

std::unique_ptr<AstNode> Parser::statement() {
    std::unique_ptr<AstNode> node;

    if (currentToken.type == TokenType::IDENTIFIER && currentToken.value == "the") {
        eat(TokenType::IDENTIFIER);  // eat "the"

        if (currentToken.type == TokenType::IDENTIFIER) {
            std::string identifier = currentToken.value;
            eat(TokenType::IDENTIFIER);

            if (currentToken.type == TokenType::IDENTIFIER && currentToken.value == "is") {
                eat(TokenType::IDENTIFIER);  // eat "is"
                int value = std::stoi(currentToken.value);
                eat(TokenType::LITERAL);

                node = std::make_unique<AssignNode>(identifier, value);
            } else {
                // Add this else block to handle incomplete assignment statements
                while (currentToken.type != TokenType::END_OF_FILE && currentToken.type != TokenType::PUNCTUATION) {
                    eat(currentToken.type);
                }
            }
        }
    }
    if (currentToken.type == TokenType::IDENTIFIER && currentToken.value == "say") {
        eat(TokenType::IDENTIFIER);  // eat "say"

        std::string identifier = currentToken.value;
        eat(TokenType::IDENTIFIER);

        node = std::make_unique<PrintNode>(identifier);
    }

    if (!node) {
        std::cout << "Unrecognized token: '" << currentToken.value << "'" << std::endl;
        eat(TokenType::IDENTIFIER); // Consume the unrecognized token
    }

    return node;
}

