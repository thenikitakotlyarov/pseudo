#include "lexer.hpp"
#include <cctype>

Token Lexer::getNextToken() {
    if (position >= input.size()) {
        return Token(TokenType::END_OF_FILE, "");
    }

    char current = currentChar();

    if (std::isspace(current)) {
        skipWhitespace();
        current = currentChar();
    }

    if (std::isalpha(current)) {
        std::string identifier;
        while (std::isalnum(current) || current == '_') {
            identifier += current;
            advance();
            current = currentChar();
        }
        return Token(TokenType::IDENTIFIER, identifier);
    }

    if (std::isdigit(current)) {
        std::string number;
        while (std::isdigit(current)) {
            number += current;
            advance();
            current = currentChar();
        }
        return Token(TokenType::LITERAL, number);
    }

    advance();

    // Add this line to skip unrecognized characters
    return getNextToken();
}

char Lexer::currentChar() {
    if (position >= input.size()) {
        return '\0';
    }
    return input[position];
}

void Lexer::advance() {
    position++;
}

void Lexer::skipWhitespace() {
    while (position < input.size() && std::isspace(currentChar())) {
        advance();
    }
}
