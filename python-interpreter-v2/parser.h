#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void parser(string exp, vector<string>& variables, vector<int>& values) {
    string ins = exp; //temporary container for manipulation

    ins.erase(remove(ins.begin(), ins.end(), ' '), ins.end()); //cleans line

    string var = ins.substr(0, ins.find("="));
    string val = ins.substr(ins.find("="), ins.size()-1);


}

#endif // PARSER_H_INCLUDED
