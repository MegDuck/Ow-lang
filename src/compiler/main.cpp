#include <typeinfo>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype> 
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include "translate.cpp"
//Errors
#define SUCCESS 0
#define NO_SUCCESS -1
#define EXIT -1
#define SYNTAX_ERROR 1
#define NOCORRECTCOMMAND_ERROR 2
#define NCNF_ERROR 3
#define RUNTIME_ERROR 4
//#define LTTHREE_ERROR 6
#define ERROR -2
#define LTT_ERROR 6

const char * errors[5] = {
	"Success exit with 0", 
	"Argc less than 3 ",
	"unknown command",
	"No correct name of file.",
	"RuntimeError. "
};

int Error(int &retcode) {
	if(retcode != SUCCESS){
		std::cerr << errors[retcode]);
		return NO_SUCCESS;
	}
	return SUCCESS;
	
}
/*
*
*Ow 1.0,
*Byte-code functions translate.cpp,
*Lexer in toovm.cpp,
*Gmail: trimskydev@gmail.com,
*
*/
//All Identifiers
enum Tokens{
	//Object = 3
	tDef = 256,
	tVal = 257,
	tVar = 258,
	//"Pure" Types = 6
	tObject = 259,
	tVoid = 260,
	tNull = 261,
	tString = 262,
	tInt = 263,
	tFloat = 264,
	//is no a Objects and Types
	tIdentifier = -1,
	//End of file
	tEOF = -2
};


//Lexer functions
extern int readtall_src(FILE *output,FILE *input); 
static void bytecode_src(std::string outputf, std::string inputf, int *ret){

	
	FILE *input = fopen(inputf.c_str(), "r");
	if(input == nullptr) {
		*ret = NCNF_ERROR;
		
		return;
	}
	FILE *output = fopen(outputf.c_str() , "w");
	if(output == nullptr) {
		*ret = NCNF_ERROR;
		
		return;
	}
	*ret = SUCCESS;
	if(ret != SUCCESS) {
		Error(*ret);
	}
	int res = readtall_src(output, input);
	fclose(input);
	fclose(output);
	if (res != 0) {
		*ret = RUNTIME_ERROR;
		Error(*ret);
	}

	
}




int main(int argc, const char * argv[])
{
	int *ret = SUCCESS;
	int Error(int &retcode);
	if(argc < 3){
		*ret = LTT_ERROR;
		Error(*ret);
	}

	
	if (strcmp(argv[1],"build") == 0 ){
		if(argc =< 5 && strcmp(argv[3], "-o" ) == 0) {
			
			std::string full_str = argv[4];
			std::string str = ".opc";

			full_str.append(str);
			
			bytecode_src(full_str, argv[2], ret);
		} 
		else {
		std::cout<<"Hello, world!";
	    bytecode_src("main.opc",argv[2], ret);
		}
	}
    else{
		*ret = LTT_ERROR;
	}
	Error(*ret);
	
}
