#include "../include/Parser.hpp"

Parser::Parser(Lexer l) 
    : lex(l)
{
    this->curr = lex.next();
}

void Parser::eat(TokenType t) {
    if (this->curr.type == t) {
        this->curr = lex.next();
    }
    else throw std::runtime_error("Error while matching types");
}

std::shared_ptr<ASTNode> Parser::parsePrimary() {
    if (this->curr.type == TokenType::NUM) {
        auto node = std::make_shared<NumNode>(curr.num);
        eat(TokenType::NUM);
        return node;
    }
    else if (this->curr.type == TokenType::VAR) {
        auto node = std::make_shared<VarNode>(curr.text);
        eat(TokenType::VAR);
        return node;
    }
    else if (this->curr.type == TokenType::LPAREN) {
        eat(TokenType::LPAREN);
        auto node = parseExp();
        eat(TokenType::RPAREN);
        return node;
    } 
    else {
        throw std::runtime_error("unexpected token in parsePrimary functiom");
    }
}

std::shared_ptr<ASTNode> Parser::parseUnary() {
    if (this->curr.type == TokenType::ADD) {
        eat(TokenType::ADD);
        auto node = std::make_shared<UnaryOpsNode>("+", parseUnary());
        return node;
    }
    else if (this->curr.type == TokenType::SUB) {
        eat(TokenType::SUB);
        auto node = std::make_shared<UnaryOpsNode>("-", parseUnary());
        return node;
    }
    return parsePrimary();
}

std::shared_ptr<ASTNode> Parser::parseFactor() {
    // keeping this to extend the exponents in future
    return parseUnary();
}

std::shared_ptr<ASTNode> Parser::parseTerm() {
    auto node = parseFactor();
    while((this->curr.type == TokenType::MUL) || (this->curr.type == TokenType::DIV)) {
        if (this->curr.type == TokenType::MUL) {
            eat(TokenType::MUL);
            node = std::make_shared<BinaryOpsNode>("*", node, parseFactor());
        }
        else {
            eat(TokenType::DIV);
            node = std::make_shared<BinaryOpsNode>("/", node, parseFactor());
        }
    }
    return node;
}

std::shared_ptr<ASTNode> Parser::parseExp() {
    auto node = parseTerm();
    while((this->curr.type == TokenType::ADD) || (this->curr.type == TokenType::SUB)) {
        if (this->curr.type == TokenType::ADD) {
            eat(TokenType::ADD);
            node = std::make_shared<BinaryOpsNode>("+", node, parseTerm());
        }
        else {
            eat(TokenType::SUB);
            node = std::make_shared<BinaryOpsNode>("-", node, parseTerm());
        }
    }
    return node;
}

std::shared_ptr<ASTNode> Parser::parse() {
    auto node = parseExp();
    if (curr.type != TokenType::END) {
        throw std::runtime_error("Unexpected token at the end");
    }
    return node;
}