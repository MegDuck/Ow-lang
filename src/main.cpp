//Main file of Ow compiler

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
//#include "Object.h"
#include "ParsSyn.h"
#include "Lexer.cpp"
//extern std::string MakeBytecode(const char* input, const char* output);
//extern std::string SyntaxParsing(const char* youTrue);
int main(int argc, const char* argv[]) {
	std::cout<<"ОТЛАДКА:" << "\n" << "\n";
	std::cout<<argc;
	
	if(argc < 2) {
		throw std::runtime_error("fatal error: no input files");
		return 1;
	}
	
	else{
		std::string FileInStr = GetInStr(argv[1]);
		std::cout<<FileInStr<<std::endl;
		
		if(strcmp(argv[1], "-o") == 0 ) {
			std::cout<<"if";
		}
		else{
			
			std::cout<<"else";
		}
	}
	return 0;
}
