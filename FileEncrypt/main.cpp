#include <iostream>
#include <string>
#include "encrypt.h"
#include <fstream>
#include <vector>
#include "AsciiCodes.h"
#include "check_prime.h"
#include "Get_GCD.h"


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

	//calculate n
	n = p * q;

	//Calculate f(n) = (p-1)(q-1)
	int func = (p - 1) * (q - 1);

	//choose "e" s.t. gcd(f(n),e) = 2; 1 < e < f(n)

	//store n, d, e

}
#else
void TestEGen();
int main(int argc, char* argv[])
{
	//TestAscii();
	TestEGen();

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

void TestEGen() {
	//testing if GCD of F(n) and e is 1

	//check if public key p and q valid
	int p, q, n, e;


	//generate private key
	choose_primes(&p, &q);

	//calculate n
	n = p * q;

	//Calculate f(n) = (p-1)(q-1)
	int func = (p - 1) * (q - 1);

	find_e(func, &e);

	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "f(n): " << func << endl;
	cout << "e " << e << endl;

}

#endif