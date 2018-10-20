#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <vector>
#include "expressions.h"
#include "print.h"

using namespace std;

void FunctionScanner(vector<string> func, vector<string> func_ins, vector<int>& func_res, vector<char> var, vector<int> res) {
    for(int i = 0; i != func.size(); i++) {
        cout << func[i] << endl;
    }
}

#endif // FUNCTIONS_H_INCLUDED
