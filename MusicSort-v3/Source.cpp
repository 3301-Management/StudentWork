//Get input
//Gen. vect for feilds
//Gen. gen an arr of vectors (if noncong fill vall)
//ask usr for opp
//make sure to bounbd by ALL vals

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <regex>
#include <vector>
#include <aio.h>


using namespace std;

int main() {
	// Set up vars
	string file, temp = "";
	int feild1, feild2, itemp = 0;
	regex pattern("[^\\t]+|\\t\\t");
	vector<string> head;
	vector<vector<string>> data;
	static const sregex_token_iterator end;

	//get input
	cout << "Plese specifiy abosolute path to input file. \n>";
	cin >> file;

	//fill head and body
	fstream input(file.c_str());
	getline(input, temp);
	


}