#include "../include/Token.hpp"

Token::Token(TokenType t) 
    : type(t), 
      text(""), 
      num(0) {}

Token::Token(double num)
    : type(TokenType::NUM),
      text(std::to_string(num)),
      num(num) {}

Token::Token(TokenType t, const std::string& txt) 
    : type(t),
      text(txt),
      num(0) {}

std::string Token::formatToken() const {
    switch (type) {
        case TokenType::NUM : return "[NUM : " + text + " ]";
        case TokenType::VAR : return "[VAR : " + text + " ]";
        case TokenType::ADD : return "[ADD : +]";
        case TokenType::SUB : return "[SUB : -]";
        case TokenType::MUL : return "[MUL : *]";
        case TokenType::DIV : return "[DIV : /]";
        case TokenType::LPAREN : return "[LPAREN]";
        case TokenType::RPAREN : return "[RPAREN]";
        case TokenType::END : return "[END]"; 
    }
    return "[UNKNOWN]";
}

std::ostream& operator<<(std::ostream& os, const Token& t) {
    os << t.formatToken();
    return os;
}