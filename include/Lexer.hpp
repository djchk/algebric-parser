#pragma once

#include <string>
#include "Token.hpp"

class Lexer {
private:
    std::string src;
    size_t index;
    char curr;

public: 
    Lexer (const std::string& txt);
    Token next();

private: 
    void advance();
    void skipWhiteSpace();
    bool isDigit(char c) const;
    bool isAlpha(char c) const;
    Token numToken();
    Token varToken();
    bool peekIsDigit() const;
};

/*
    here numToken implements read a full number & varToken method helps to read the full variable name, others are essential helper functions
*/