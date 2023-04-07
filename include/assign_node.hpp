#pragma once
#include "ast_node.hpp"
#include <string>

class AssignNode : public AstNode {
public:
    AssignNode(const std::string& identifier, int value)
        : identifier(identifier), value(value) {}

    std::string identifier;
    int value;
};
