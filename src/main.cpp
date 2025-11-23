#include <bits/stdc++.h>
#include "../include/Lexer.hpp"
using namespace std;

int main() {
    Lexer lexer("3 + (x * .10)");
    while(true) {
        Token t = lexer.next();
        cout << t << endl;
        if (t.type == TokenType::END) break;
    }
    return 0;
}