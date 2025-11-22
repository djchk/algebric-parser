#include "../include/Lexer.hpp"
#include <cctype>
#include <stdexcept>
using namespace std;

Lexer::Lexer(const string& txt) 
    : src(txt), index(0), curr(txt.empty() ? '\0' : txt[0]) {}

void Lexer::advance() {
    index++;
    if (index < src.size()) curr = src[index];
    else curr = '\0';
}

void Lexer::skipWhiteSpace() {
    while (isspace(curr)) advance();
}

bool Lexer::isDigit(char c) const { 
    return isdigit(c);
}

bool Lexer::isAlpha(char c) const {
    return isalpha(c) || c == '_';
}

bool Lexer::peekIsDigit() const {
    if (index + 1 < src.size()) return isdigit(src[index + 1]);
    return false;
}

Token Lexer::numToken() {
    string s;
    int dots = 0;

    while (isDigit(curr) || curr == '.') {
        if (curr == '.') {
            dots++;
            if (dots > 1) throw runtime_error("Invalid Number format");
        }
        s += curr;
        advance();
    }
    return Token(stod(s));
}

Token Lexer::varToken() {
    string s;
    while (isAlpha(curr) || isDigit(curr)) {
        s += curr;
        advance();
    }
    if (isDigit(s[0])) throw runtime_error("Variable can't be strat with digit");
    return Token(TokenType::VAR, s);
}

Token Lexer::next() {
    skipWhiteSpace();
    if (curr == '\0') return Token(TokenType::END);

    if (isDigit(curr) || (curr == '.' && peekIsDigit())) return numToken();
    if (isAlpha(curr)) return varToken();

    char c = curr;
    advance();

    switch(c) {
        case '+' : return Token(TokenType::ADD, "+");
        case '-' : return Token(TokenType::SUB, "-");
        case '*' : return Token(TokenType::MUL, "*");
        case '/' : return Token(TokenType::DIV, "/");
        case '(' : return Token(TokenType::LPAREN, "(");
        case ')' : return Token(TokenType::RPAREN, ")");
        case ',' : return Token(TokenType::COMMA, ",");
        default:
            throw runtime_error("Invalid Operation or character");
    }
}