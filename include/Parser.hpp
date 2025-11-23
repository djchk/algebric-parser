#pragma once
#include "AST.hpp"
#include "Lexer.hpp"

class Parser {
    Lexer lex;
    Token curr;

public:
    Parser(Lexer l);
    void eat(TokenType type);
    std::shared_ptr<ASTNode> parse();

private:
    std::shared_ptr<ASTNode> parseExp();
    std::shared_ptr<ASTNode> parseTerm();
    std::shared_ptr<ASTNode> parseFactor();
    std::shared_ptr<ASTNode> parseUnary();
    std::shared_ptr<ASTNode> parsePrimary();
};