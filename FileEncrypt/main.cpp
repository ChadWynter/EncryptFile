#include <iostream>
#include <string>
#include "encrypt.h"
#include <fstream>
#include <vector>
#include "AsciiCodes.h"
#include "check_prime.h"
#include "Get_GCD.h"
#include <time.h>
#include <map>
#include "Convert_Password.h"


using namespace std;
#ifdef _DEBUG
int main(int argc, char* argv[]) {
	string password;
	//retreive password from user
	cin >> password;
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
	int p, q, n, e, d;


	//generate private key
	choose_primes(&p, &q);

	//calculate n
	n = p * q;

	//Calculate f(n) = (p-1)(q-1)
	int func = (p - 1) * (q - 1);

	//choose "e" s.t. gcd(f(n),e) = 2; 1 < e < f(n)
	e = find_e(func, &e);

	//store n, d, e (encrypt by multiplying each number by user password converted to ascii and added together)
	int password_conversion = Convert_PW(password);

	ofstream out("metadata.txt");
	out << n * password_conversion << endl;
	out << d * password_conversion << endl;
	out << e * password_conversion << endl;
	out.close();



}
#else
void TestEGen();
int GetGCD(int fn, int e);
int TestConvertPassword();
int main(int argc, char* argv[])
{
	srand(time(NULL));
	//TestAscii();
	//TestEGen();
	TestConvertPassword();

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
	cout << "GCD of F(n) and e: " << GetGCD(func, e) << endl;

}

int GetGCD(int fn, int e) {
	int GCD = 1;
	unordered_map<int, int> occurances;
	for (int i = 1; i < fn / 2; i++) {
		if (fn % i == 0) {
			occurances[i]++;
		}
	}
	for (int j = 1; j < e / 2; j++) {
		//if map key != 0, GCD != 1
		if (e % j == 0) {
			auto search = occurances.find(j);
			if (search != occurances.end()) {
				//cout << "common number found, j = " << j << endl;
				GCD = j;
			}
		}
	}
	return GCD;
}

int TestConvertPassword() {
	string password;
	cout << "enter password: "  ;
	cin >> password;

	cout<<"value converted: "<<Convert_PW(password);

}

#endif