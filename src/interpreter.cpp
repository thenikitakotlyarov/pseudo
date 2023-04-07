#include "interpreter.hpp"
#include "assign_node.hpp"
#include "print_node.hpp"
#include <iostream>

void Interpreter::interpret() {
    std::vector<std::unique_ptr<AstNode>> ast_nodes = parser.parse();
    for (const auto &node : ast_nodes) {
        visit(node.get());
    }
}

void Interpreter::visit(const AstNode *node) {
    if (const AssignNode *assignNode = dynamic_cast<const AssignNode *>(node)) {
        symbolTable[assignNode->identifier] = assignNode->value;
    } else if (const PrintNode *printNode = dynamic_cast<const PrintNode *>(node)) {
        std::cout << symbolTable[printNode->identifier] << std::endl;
    }
}
