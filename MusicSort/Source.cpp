#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
	//init var setup.
	//11
	int count = 0;
	string temp;
	regex pattern1("[^\\t]+");


	regex txt_regex("");
	smatch cat;

	//seting up file input
	cout << "Plese specifiy abosolute path to input file. \n >";
	cin >> temp;
	char tempc[temp.length() + 1];
	strcpy(tempc, temp.c_str());
	ifstream input(tempc);

	//coping the file in to a buffer
	while (getline(input, temp)) {
		count++;
	}

	//filter setup
	string f1[count];
	for (int i = 0; i < count; i++) {
		getline(input, f1[i]);
	}


	

	string f2[11];

	cout << "Hello World!\n";
}


string* filter(regex pattern, string in) {
	int count = 0;
	sregex_token_iterator end;
	for (sregex_token_iterator i(in.begin(), in.end(), pattern); i != end; ++i){
		count++;
	}
	string out[count];
	count = 0;
	for (sregex_token_iterator i(in.begin(), in.end(), pattern); i != end; ++i) {
		count++;
		out[count] = *i;
		
	}
	return out;
}

