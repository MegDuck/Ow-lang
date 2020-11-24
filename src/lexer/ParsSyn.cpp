#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "ParsSyn.h"
/*#include "Object.h"*/
std::string GetInStr(const char* youTrue) {
    std::ifstream ss(youTrue);
    std::vector<std::string> vecPushA; //std::copy(vecPushA.begin(), vecPushA.end(), std::ostream_iterator<std::string>(std::cout,"\n") );
    std::string strh;
    std::string str;
    if (!ss.is_open()) {
        throw std::runtime_error("Такого файла не существует");
    } 
    else {
        while(!ss.eof()){
            getline(ss, strh);
            str += strh;
            if (!ss.eof()){
                str += '\n';
            }
        }
        //std::cout<< str;
    } 
    ss.close();
    return str;
}
/*int main() {
    SyntaxParsing("test.txt");
	return 0;
}*/