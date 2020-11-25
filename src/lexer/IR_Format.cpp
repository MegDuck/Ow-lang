#include <string>
#include "Lexer.h"
std::string MakeIR(std::string str){
    Lexer Lexer(str);
    std::cout<<Lexer.gettok();
    //std::cout<<i;
    std::string str_IR;
    return str_IR;
}