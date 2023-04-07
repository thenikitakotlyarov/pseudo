#pragma once
#include "parser.hpp"
#include <unordered_map>

class Interpreter {
public:
    Interpreter(Parser &parser) : parser(parser) {}

    void interpret();

private:
    Parser &parser;
    std::unordered_map<std::string, int> symbolTable;

    void visit(const AstNode *node);
};
