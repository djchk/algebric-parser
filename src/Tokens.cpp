#include "../include/Token.hpp"
using namespace std;

Token::Token(TokenType t) 
    : type(t), 
      text(""), 
      num(0) {}

Token::Token(double num)
    : type(TokenType::NUM),
      text(to_string(num)),
      num(num) {}

Token::Token(TokenType t, const string& txt) 
    : type(t),
      text(txt),
      num(0) {}

string Token::formatToken() const {
    switch (type) {
        case TokenType::NUM : return "[NUM : " + text + " ]";
        case TokenType::VAR : return "[VAR : " + text + " ]";
        case TokenType::ADD : return "[ADD : +]";
        case TokenType::SUB : return "[SUB : -]";
        case TokenType::MUL : return "[MUL : *]";
        case TokenType::DIV : return "[DIV : /]";
        case TokenType::COMMA : return "[COMMA : ,]";
        case TokenType::LPAREN : return "[LPAREN]";
        case TokenType::RPAREN : return "[RPAREN]";
        case TokenType::END : return "[END]"; 
    }
    return "[UNKNOWN]";
}

ostream& operator<<(ostream& os, const Token& t) {
    os << t.formatToken();
    return os;
}