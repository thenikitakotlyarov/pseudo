#pragma once
#include <string>

enum class TokenType {
    END_OF_FILE,
    IDENTIFIER,
    KEYWORD,
    LITERAL,
    OPERATOR,
    PUNCTUATION
};

class Token {
public:
    Token(TokenType type, const std::string& value) : type(type), value(value) {}

    TokenType type;
    std::string value;
};
