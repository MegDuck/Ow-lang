#include <iostream>
#include "../ParsSyn.h"
namespace Ow::Lexer
{
    class ToPeek{
        public:
        ToPeek(const char* str){
            str_peeks = GetInStr(str);
        }
        std::string str_peeks;
        int index = 0;
        int line = 1;
        std::string str;
            char peek(){
                return str_peeks[index];
            }
            char next_peek(int advance = 1){
                return str_peeks[index+advance];
            }
            void to_next_peek(int advance = 1){
                while(advance){
                    if(str_peeks[index] == '\n') line++;
                    
                    index++;
                    advance--;
                };
            }
            
        
    };
    class ParseSyntax {
        //Logic Functions
        bool GoSkip(const char _True){
            return _True == ' ' || _True == '\t' || _True == '\r';
        }
        bool is_digit(const char _True){
            return _True >= '0' && _True <= '9';        }
        bool _String(const char _True){
            return isalpha(_True) || _True == '_';
        }
        bool is_startorend_str(const char _True){
            return _True == '"' || _True == '\'' || _True == '`';
        }
    };
    
} // namespace Ow::Lexer
