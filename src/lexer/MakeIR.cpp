#include <string>
#include <iostream>
#include "Lexer.h"

Lexer::Lexer(std::string str) {
    str_peeks = str;
}
enum class Token{
    Identifier = 1,
    Variable_ = 2,
    Import = 3,
    };

char Lexer::peek(){
    return str_peeks[i]; 
}
char Lexer::next_peek(int distance){
    return str_peeks[i + distance];
}
void Lexer::to_next_peek(int distance){
    i += distance;
}



std::string Lexer::gettok(std::string str){
   // Lexer str_peeks();
    std::string identifier;

    if(isalpha(peek())){
        to_next_peek();
        while(is_Ow_identifier(peek())) {
            identifier += peek();
            to_next_peek();
        }
    }
    return identifier;
}
std::string MakeIR(std::string str){
    Lexer Lexer(str);
    std::cout<<Lexer.gettok(str);
    //std::cout<<i;
    std::string str_IR;
    return str_IR;
}

int main(){
    MakeIR("Qe-_-sd fgxcf ghf dh");
    return 0;
}

bool Lexer::is_Ow_identifier(const int isOwString){
    
    if(isalpha(isOwString)) return true;
    if(isdigit(isOwString)) return true;

    switch(isOwString){ 
        case '_': return true;
        case '-': return true;
    }
    return false;
}
