#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
void main(){
	string pyText;
	ifstream inFile;
	inFile.open("pyCode.txt");

	if (!inFile) {
		cout << "Unable to do that" << endl;
		exit(1);
	}

	while (getline(inFile, pyText)) {
		if (pyText.find('#') != string::npos){ // to skip the comments
			continue;
		}
		cout << pyText << endl;
		if (pyText.find(':')) // to incorporate the colon operator
		{
			int spaces; //if 0 function ends if more still under that function
		}
	}
	


	system("pause");
}
