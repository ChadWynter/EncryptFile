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
	TestAscii();

}
void TestAscii() {
	//getCodes test
	string line = "Testing";
	vector<vector<int>> A_Codes;

	get_codes(line, &A_Codes);

	for (const auto& i : A_Codes) {
		for (const auto& j : i) {
			cout << j << ", ";
		}
	}
}

#endif