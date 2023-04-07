#pragma once
#include "lexer.hpp"
#include "ast_node.hpp"
#include <vector>
#include <memory>

class Parser {
public:
    Parser(Lexer &lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}

    std::vector<std::unique_ptr<AstNode>> parse();

private:
    Lexer &lexer;
    Token currentToken;

    void eat(TokenType tokenType);
    std::unique_ptr<AstNode> statement();
};
