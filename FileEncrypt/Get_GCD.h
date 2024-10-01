#pragma once
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91 };

int find_e(int fn, int* e){
	//generate list of possible factors of fn
	vector<int> gcd_list_first = { 1 };
	vector<int> gcd_list_second = { 1 };
	for (int i = 2; i < (fn / 2); i++) {
		if (fn % i == 0) {
			gcd_list_first.push_back(i);
		}
	}
	int gcd = 0;
	while (gcd != 1){
		*e = rand() % (fn / 2);
		for (int i = 2; i < (*e / 2); i++) {
			if (*e % i == 0) {
				//if statement to check if i is in first list already
					//exit for loop if true
			}
		}
	}
	
	//generate list of possible factors of random e while e < (gcd_list / 2)

	//ensure only shared factor is 1
}