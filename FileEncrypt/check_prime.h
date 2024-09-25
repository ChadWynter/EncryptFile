#pragma once
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91 };

void choose_primes(int* p, int* q) {
	*p = primes[rand() % primes.size()];
	*q = primes[rand() % primes.size()];
}




