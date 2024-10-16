#pragma once
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

//vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91 };

int find_e(int fn, int* e){
	//generate list of possible factors of fn
	vector<int> gcd_list_first = { 1 };
	//vector<int> gcd_list_second = { 1 };
	for (int i = 2; i < (fn / 2); i++) {
		if (fn % i == 0) {
			gcd_list_first.push_back(i);
		}
	}
	int gcd = 0;
	//get all factors of random e. If shared gcd other than 1 with F(N), choose another e
	while (gcd != 1){
		*e = rand() % (fn - 1);
		for (int i = 2; i < (*e / 2); i++) {
			if (*e % i == 0){
				//if statement to check if i is in first list already
				if ((find(gcd_list_first.begin(), gcd_list_first.end(), i) != gcd_list_first.end())) {
					//exit for loop if true
					break;
				}
			}
			gcd = 1;
		}
	}
	
	//e is now a number less than f(n) with a gcd of 1
}