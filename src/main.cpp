#include<iostream>
#include "lexer/lexer.h"
int main(int argc , char* argv[]){
    if(argc < 2){
        std::cerr << "need input file \n";
        return 1 ;
    }
    Lexer lexer(argv[1]);
    Token token  = lexer.getNextToken();

    while(token.type != TokenType::EOF_TOKEN){
        std::cout << "TokenType : " << (int)token.type << " text : " << token.text << std::endl;
        token = lexer.getNextToken();
    }

    return 0 ;
}