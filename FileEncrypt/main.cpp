#include <iostream>
#include <string>
#include "encrypt.h"
#include <fstream>
#include <vector>


using namespace std;
int main(int argc, char* argv[]) {
	//convert file to ascii codes
	string line;
	string file;
	vector<string> lines;

	ifstream myfile;
	myfile.open(file);

	while (getline(myfile, line)) {
		for (int i = 0; i < line.size(); i++) {

		}
	}

	
	//check if public key p and q valid


	//generate private key


}