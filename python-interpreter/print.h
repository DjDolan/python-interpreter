#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

void print(string line, vector<char> var, vector<int> res, char* rm_ch) {

        //parse the line
        string new_line = line.substr(line.find('('), line.find(')'));

        for(int i = 0; i < sizeof(rm_ch)/sizeof(rm_ch[0]); i++)
            new_line.erase(remove(new_line.begin(), new_line.end(), rm_ch[i]), new_line.end());

        //case where there are variables called
        if(new_line.find(',') != string::npos) {

            //parse this line now using the ',' delimeter
            string print_line = new_line.substr(0, new_line.find(','));
            string var_line = new_line.substr(new_line.find(',')+1, new_line.size()-1);
            var_line.erase(remove(var_line.begin(), var_line.end(), ' '), var_line.end());

            //copy variable in the string to char array
            char arr[var_line.size()];
            strcpy(arr, var_line.c_str());

            //check if the variable is in the container
            //if yes, then find corresponding result in result container
            //if no, then print out and unexpected error
        }

        //case where there is no variable called
        else
            cout << new_line << endl;
}

#endif // PRINT_H_INCLUDED
