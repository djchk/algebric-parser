#pragma once
#include<string>
using namespace std;

// future plan to handle functional calls & power 
enum class TokenType {
    END,
    NUM,
    VAR,
    ADD,
    SUB,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    COMMA
};

class Token {
public:
    TokenType type;
    string text;
    double num;

    Token(TokenType t = TokenType::END);
    Token (double num);
    Token(TokenType t, const string& txt);

    string formatToken() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Token& t);
};

/*
Here I am defining the token class which have theree methods which can do 
1. handle the EOF
2. handle the nums
3. handle the tokens with variable, binary operations, Parenthesis, commas
*/