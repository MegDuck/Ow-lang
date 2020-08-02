#include <typeinfo>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <fstream>
static int digit(char ch){
	switch(ch) {
		case '1': return 1;
	    case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1;
	}
	
}

static std::string test = 
" def Main(){}; 2+2";

class Token {
	public:
		int tag;
		Token(int t) { tag = t; }
};
class Tag
{
	public:
	enum Token
	{
    tDef = -1,
    tBlockBegin= -2,
    tBlockEnd = -3,
    tTypeInt = -4,
    tTypeChar = -5,
    tTypeString = -6,
    tTypeVoid = -7,
    tTypeBool = -8,
    tTrue = -9,
    tFalse = -10,
    tNumber = -11,
    tIdentifier = -12,
    tSemicolon = -13,
    tEOF = 1,
	};
};
class Lexer {
	int NumVal;
	
	Tag tag;
	static std::string IdentifierStr;
	int Word(int id, std::string lexeme )
	{
		 if(IdentifierStr == lexeme){
		 	return (int)id;
		 }
		 return tag.tEOF;
    }
    private:
    	char peek = ' ';
	public:
		Lexer() {
			Word(tag.tTrue, "true");
			Word(tag.tFalse, "false");
		}
		int line = 1;
		Token scan() {
			int i = 0;
			for( ; ; peek = test[i++]) {
				if(peek == ' ' || peek == '\t') continue;
				else if (peek == '\n') line  = line + 1;
				else break;
			 }
			 
			if(isdigit(peek)){
				int v = 0;
				do {
					v = 10*v + digit(peek);
					peek = test[i++];
				} while( isdigit(peek));
				NumVal = v;
			}
			if(isalpha(peek)){
				
			}
			
		}
};

/*
static std::string test = 
" def Main(){}; 2+2";

static int gettok()
{
	// Главные переменные
	static int line = 1;
	static int peek = ' ';
	static std::string IdentifierStr;
	static int num;
	// Обработка и получение значение peek.
for(int i = 0; i < sizeof(test[i]); peek = test[i++])
	{
		if(peek == ' ' && peek == '\t' && peek == '\r')
			continue;
		else if(peek == '\n') line += 1;
		else break;
	}
} */
/*
import std.io.*;

def Main()
{
	io.print("Hello world!");
};
*/
/*
enum Token
{
    tDef = -1,
    tBlockBegin= -2,
    tBlockEnd = -3,
    tTypeInt = -4,
    tTypeChar = -5,
    tTypeString = -6,
    tTypeVoid = -7,
    tTypeBool = -8,
    tNumber = -9,
    tIdentifier = -10,
    tSemicolon = -11,
    tEOF = 1,
};
static std::string test = 
" def Main(){}; 2+2";
	
static std::string Identifier; //Заполниться если будет команда. 
static int NumVal;

static int gettok() {
  static int i = 0;
  static int peek = ' ';

  // Пропускаем пробелы.
  while (isspace(peek))
    peek = test[i++];
   while(peek == '(') 
  	peek = test[i++];  
  while (peek == ')') 
  	peek = test[i++];  
  while(peek == ':') 
  	peek = test [i++]; 
  if (isalpha(peek)) { // идентификатор: [a-zA-Z][a-zA-Z0-9]*
    Identifier= peek;
    while (isalnum((peek = test[i++])))
      Identifier += peek;

    if (Identifier == "def"){
    	 std::cout<<Identifier;
    	 peek = test[i++];
    	 return tDef;
    }
    if (Identifier == "void"){
    	 std::cout<<Identifier;
    	 peek = test[i++];
    	 return tTypeVoid;
    }
    if (Identifier == "string"){
    	 std::cout<<Identifier;
    	 peek = test[i++];
    	 return tTypeString;
    }
    if (Identifier == "int"){
    	 std::cout<<Identifier;
    	 peek = test[i++];
    	 return tTypeInt;
    }
    if (Identifier == "char"){
    	 std::cout<<Identifier;
    	 peek = test[i++];
    	 return tTypeChar;
    }
    if (Identifier == "bool"){
    std::cout<<Identifier;
    peek = test[i++];
    return tTypeBool;
    }
   //if (Identifier == "extern") return tok_extern;
    else{
    	peek = test[i++];
    	std::cout<<Identifier;
    	return tIdentifier;
    }
  }
  


    if (isdigit(peek) || peek == '.') {   // Число: [0-9.]+
    std::string NumStr;
    do {
      NumStr += peek;
      peek = test[i++];
    } while (isdigit(peek) || peek == '.');
    

    NumVal = strtod(NumStr.c_str(), 0);
    std::cout<<NumVal;
    return tNumber;
  }

  if (peek== '#') {
    // Комментарий до конца строки
    do peek= test[i++];
    while (peek != EOF && peek != '\n' && peek != '\r');
    
    if (peek != EOF)
      return gettok();
  }
  
  // Проверка конца файла.
  if (peek == EOF)
    return tEOF;

  // В противном случае просто возвращаем символ как значение ASCII
  int ThisChar = peek;
  peek = test[i++];
  return ThisChar;
}
*/

int main()
{
  std::cout<<' '<<digit('3');
  char a = 'a';
  std::string ab = a;
    //std::cout<<()'11'
    /*std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
    std::cout<<gettok();
*/
    return 0;
}
