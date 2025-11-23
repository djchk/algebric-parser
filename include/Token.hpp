#pragma once
#include<string>

// future plan to handle functional calls & power 
enum class TokenType {
    END,
    NUM,
    VAR,
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    LPAREN,
    RPAREN
};

class Token {
public:
    TokenType type;
    std::string text;
    double num;

    Token(TokenType t = TokenType::END);
    Token (double num);
    Token(TokenType t, const std::string& txt);

    std::string formatToken() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Token& t);
};

/*
Here I am defining the token class which have theree methods which can do 
1. handle the EOF
2. handle the nums
3. handle the tokens with variable, binary operations, Parenthesis, commas
*/