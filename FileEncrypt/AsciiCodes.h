#pragma once
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void get_codes(string line, vector<vector<int>>* A_Codes) {
	vector<int> temp = {};
	for (int i = 0; i < line.size(); i++) {
		temp.push_back((int)line[i]);
	}
	/*
	for (int j = 0; j < temp.size(); j++) {
		cout << temp[j] << ", ";
	}
	*/
	A_Codes->push_back(temp);
}
