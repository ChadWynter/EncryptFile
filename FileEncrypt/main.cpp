#include <iostream>
#include <string>
#include "encrypt.h"
#include <fstream>
#include <vector>
#include "AsciiCodes.h"


using namespace std;
#ifdef _DEBUG
int main(int argc, char* argv[]) {
	//convert file to ascii codes
	string line;
	string file;
	vector<string> lines;
	vector<vector<int>> A_Codes;

	ifstream myfile;
	myfile.open(file);
	int line_number = 0;
	while (getline(myfile, line)) {
		//convert each char into ascii representation and store in A_Codes
		get_codes(line, &A_Codes);

		line_number++;
	}

	
	//check if public key p and q valid


	//generate private key


}
#else
int main(int argc, char* argv[])
{
	//getCodes test
	string line = "Testing";
	vector<vector<int>> convert;

	get_codes(line, &convert);

	for (int i = 0; i < convert.size() - 1; i++) {
		for (int j = 0; j < convert[i].size() - 1; j++) {
			cout << convert[i][j] << ", ";
		}
	}

}

#endif