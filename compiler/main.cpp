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
/*

*Ow 1.0,
*Byte-code functions translate.cpp,
*Lexer in toovm.cpp,
*Gmail: trimskydev@gmail.com,

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
enum Errors{
	NoneError = 0,
	SyntaxError = 1,
	LessThan3ArgsError,
	NoCorrectCommandError = 2,
	NoCorrectNameOfFileError = 3,
	RunTimeError = 4,
};
std::string errors[5] = {
	" ", 
	"Argc less than 3 ",
	"unknown command",
	"No correct name of file.",
	"RuntimeError. "
};
//Lexer functions
extern int readtall_src(FILE *output,FILE *input); 
static void bytecode_src(std::string outputf, std::string inputf, int *retcode){
	
	FILE *input = fopen(inputf.c_str(), "r");
	if(input == nullptr) {
		*retcode = NoCorrectNameOfFileError;
		return;
	}
	FILE *output = fopen(outputf.c_str() , "w");
	if(output == nullptr) {
		*retcode = NoCorrectNameOfFileError;
		return;
	}
	int res = readtall_src(output, input);
	fclose(input);
	fclose(output);
	if (res != 0) {
		*retcode = RunTimeError;
	}
	
}




int main(int argc, const char * argv[])
{
	int retcode = NoneError;
	if(argc < 3){
		retcode = LessThan3ArgsError;
		goto Error;
	}
	
	if (strcmp(argv[1], "build") == 0 ){
		if(argc >= 5 && strcmp(argv[3],"-o") == 0) {
			
			const char* bc_suffix = ".opc";
			char bytecode_name[256];
			bytecode_name [ 0 ] = '\0';
			strcat(bytecode_name, argv[4]);
			strcat(bytecode_name, bc_suffix);
			
			bytecode_src(bytecode_name, argv[2], &retcode);
		} else {
	    bytecode_src("main.opc",argv[2], &retcode);
		}
	}
	goto Error;
Error:
	if(retcode != NoneError){
		fprintf(stderr, "> %s\n", errors[retcode]);
	}

}
