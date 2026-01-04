#include "lexer.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;  

class LexerImpl {
public:
    ifstream file;
    char curr;

    LexerImpl(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            cerr << "Error opening file\n";
            exit(1);
        }
        advance();
    }

    void advance() {
        curr = file.get();
    }

    void skipSpace() {
        while (isspace(curr)) {
            advance();
        }
    }

    Token nextToken() {
        skipSpace();

        if (!file || curr == EOF) {
            return {TokenType::EOF_TOKEN, ""};
        }

        if (isalpha(curr)) {
            string value;
            while (isalnum(curr)) {
                value += curr;
                advance();
            }

            if (value == "int")
                return {TokenType::INT, value};

            if (value == "if")
                return {TokenType::IF, value};

            return {TokenType::IDENTIFIER, value};
        }

        if (isdigit(curr)) {
            string value;
            while (isdigit(curr)) {
                value += curr;
                advance();
            }
            return {TokenType::NUMBER, value};
        }

        char ch = curr;
        advance();

        switch (ch) {
            case '=':
                if (curr == '=') {
                    advance();
                    return {TokenType::EQUAL, "=="};
                }
                return {TokenType::ASSIGN, "="};
            case '+': return {TokenType::PLUS, "+"};
            case '-': return {TokenType::MINUS, "-"};
            case ';': return {TokenType::SEMICOLON, ";"};
            case '(': return {TokenType::LPAREN, "("};
            case ')': return {TokenType::RPAREN, ")"};
            case '{': return {TokenType::LBRACE, "{"};
            case '}': return {TokenType::RBRACE, "}"};
            default:
                return {TokenType::UNKNOWN, string(1, ch)};
        }
    }
};

static LexerImpl* impl = nullptr;

Lexer::Lexer(const string& file) {
    impl = new LexerImpl(file);
}

Token Lexer::getNextToken() {
    return impl->nextToken();
}
