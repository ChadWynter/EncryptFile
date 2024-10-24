#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int Convert_PW(string pw) {
	int output = 0;
	for (int i = 0; i < pw.size(); i++) {
		//cout << pw[i] << endl;
		output += (int)pw[i];
	}
	return output;
}
