#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include "parser.h"
#include "algorithm"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream file_in;
    string line;
    vector<string> instructions;
    vector<string> variables;
    vector<int> values;

    file_in.open(argv[1]);

    while(getline(file_in, line))
        instructions.push_back(line);

    file_in.close();

    for(int i = 0; i != instructions.size(); i++) {
        //if contains "#" or line is empty then ignore
        if(instructions[i].find("#") != string::npos) { continue; }

        //if '=' then its an assignment operator
        if(instructions[i].find("=") != string::npos) {
            //clean and parse the line
            parser(instructions[i], variables, values);
        }
    }


    return 0;
}
