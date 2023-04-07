#pragma once
#include "token.hpp"
#include <string>

class Lexer {
public:
    Lexer(const std::string &input) : input(input), position(0) {}

    Token getNextToken();

private:
    std::string input;
    size_t position;

    char currentChar();
    void advance();
    void skipWhitespace();
};
