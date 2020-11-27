#include <iostream>
#include "../ParsSyn.h"
namespace Ow::Lexer
{
    class gettok{
        public:
        gettok(const char* str){
            str_peeks = str;
        }
        std::string str_peeks;
        int index = 0;
        int line = 1;
        int column = 1;
        std::string str;
            char peek();
            char next_peek(int advance);
            char to_next_peek(int advance){
                return advance;
            }

    };
    
    
} // namespace Ow::Lexer

int main(){
    Ow::Lexer::gettok a("test/print.ow");
    a.to_next_peek(3);
    return 0;
}