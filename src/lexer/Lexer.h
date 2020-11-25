#include <string>

class Lexer{
    private:
        //std::string str_peeks;
    public:
        std::string str_peeks;
        int index = 0;
        int line = 1;
        int column = 1;
        int i;

        
        std::string gettok();
        char peek();
        char next_peek(int distance = 1);
        void to_next_peek(int distance = 1);
        //True Or False Functions
        bool is_Ow_identifier(const int isOwString);
    Lexer(std::string str);
};