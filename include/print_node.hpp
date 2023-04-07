#pragma once
#include "ast_node.hpp"
#include <string>

class PrintNode : public AstNode {
public:
    explicit PrintNode(const std::string& identifier) : identifier(identifier) {}

    std::string identifier;
};
