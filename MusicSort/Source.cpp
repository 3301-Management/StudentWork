#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <regex>
using namespace std;

string* filter(regex pattern, string in) {
	int count = 0;
	sregex_token_iterator end;
	for (sregex_token_iterator i(in.begin(), in.end(), pattern); i != end; ++i){
		count++;
	}
	string* out = new string[count];
	count = 0;
	sregex_token_iterator i(in.begin(), in.end(), pattern);
	do {
		count++;
		cout << *i << '\n';
		out[count] = *i;
		++i;
	} while (i != end);

		
	
	return out;
}

int main() {
	//init var setup.
	//11
	int count = 0;
	string temp;
	string file;
	regex pattern1("[^\\t]+");

	//seting up file input
	cout << "Plese specifiy abosolute path to input file. \n >";
	cin >> file;
	ifstream input(file.c_str());

	//counting file length
	while (getline(input, temp)) {
		count++;
	}

	//filter setup
	ifstream input2(file.c_str());
	string f1[count];
	for (int i = 0; i < count; i++) {
		getline(input2, f1[i]);
	}
	int ou = (filter(pattern1, f1[1]))->length();
	string f2[(filter(pattern1, f1[1])->length())][count];

	//filtering
	for (int i = 0; i < (f1->length()); i++) {
		for (int ii = 0; ii < (filter(pattern1, f1[i])->length()); ii++) {
			//string buff[(*(filter(pattern1, f1[i])))];
			//buff = ;
			f2[ii][i] = (filter(pattern1, f1[i]))[ii];
		}
	}


	cout << "!\n";
}




