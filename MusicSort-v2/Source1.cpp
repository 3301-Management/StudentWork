#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main() {
	//get input
	string file;
	cout << "Plese specifiy abosolute path to input file. \n >";
	//cin >> file;
	
	// for debug function
	file = "/music/dys.txt";


	//declaring vars
	ifstream input(file.c_str());
	regex pattern("[^\\t]+");
	sregex_token_iterator end;
	string temp = "";
	int y = 0;
	int x = 0;
	
	//defining x and y
	while (getline(input, temp)) {
		y++;
	}

	ifstream input2(file.c_str());
	string l1 = "";
	getline(input2, l1);
	

	for (sregex_token_iterator i(l1.begin(), l1.end(), pattern); i != end; ++i) {
		x++;
	}

	//gen. of storage arr
	string f1[x][y];

	//filling storage

	for (int ii = 0; ii < y; ii++) {
		ifstream input3(file.c_str());
		getline(input, temp);
		int x_count = 0;
		for (sregex_token_iterator i(l1.begin(), l1.end(), pattern); i != end; ++i) {
			f1[x_count][ii] = *i;
			x_count++;
		}
	}

	//prints out the storage block
	for (int i = 0; i < y; i++) {
		for (int ii = 0; ii < x; ii++) {
			temp = f1[x][y];
		}
	}

	cout << "test";

}