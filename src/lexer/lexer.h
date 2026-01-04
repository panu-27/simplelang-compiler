#pragma once 
#include <string>

enum class TokenType{
    INT,
    IDENTIFIER ,
    NUMBER,
    ASSIGN ,
    PLUS ,
    MINUS ,
    SEMICOLON , 
    LPAREN ,
    RPAREN ,
    LBRACE ,
    RBRACE ,
    IF ,
    EQUAL ,
    EOF_TOKEN ,
    UNKNOWN
};

struct Token {
    TokenType type ;
    std::string text ;
};

class Lexer {
    public:
        Lexer(const std::string& file);
        Token getNextToken();
};