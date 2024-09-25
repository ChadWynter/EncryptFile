#include <iostream>
#include <string>
#include "encrypt.h"
#include <fstream>
#include <vector>
#include "AsciiCodes.h"
#include "check_prime.h"


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
	while (getline(myfile, line)) {
		//convert each char into ascii representation and store in A_Codes
		get_codes(line, &A_Codes);
	}

	
	//check if public key p and q valid
	int p, q, n, e;


	//generate private key
	choose_primes(&p, &q);

	//store n
	n = p * q;

	//Calculate f(n) = (p-1)(q-1)
	int func = (p - 1) * (q - 1);

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