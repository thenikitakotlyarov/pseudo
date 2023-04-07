#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "lexer.hpp"
#include "parser.hpp"
#include "interpreter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::stringstream inputBuffer;
    inputBuffer << inputFile.rdbuf();
    std::string input = inputBuffer.str();

    std::cout << "Input:\n" << input << std::endl;

    Lexer lexer(input);
    Parser parser(lexer);
    Interpreter interpreter(parser);

    // Print AST nodes
    auto ast_nodes = parser.parse();
    for (const auto &node : ast_nodes) {
        std::cout << "Node: " << typeid(*node).name() << std::endl;
    }

    interpreter.interpret();

    return 0;
}
