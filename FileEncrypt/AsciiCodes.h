#pragma once
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void get_codes(string line, vector<vector<int>>* A_Codes) {
	vector<int> temp;
	for (int i = 0; i, line.size() - 1; i++) {
		temp.push_back((int)line[i]);
	}
	A_Codes->push_back(temp);
}
