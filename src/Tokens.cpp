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