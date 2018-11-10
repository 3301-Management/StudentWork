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
#include <aio.h>
#include <vector>
#include <regex>


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
	//cin >> file;
	
	// for debug function
	file = "/music/dis.tsv";
	
	//fill head and data
	fstream input(file.c_str());
	getline(input, temp);
	for (sregex_token_iterator i(temp.begin(), temp.end(), pattern); i != end; ++i) {
		head.push_back(*i);
	}

	while (!(input.eof())) {
		getline(input, temp);
		vector<string> vtemp;
		for (sregex_token_iterator i(temp.begin(), temp.end(), pattern); i != end; ++i) {
			vtemp.push_back(*i);
		}
		data.push_back(vtemp);
	}

	//ask usr for operations

	do {
		itemp = 0;
		cout << "\n\nHere are the data feilds that were parsed from the file:\n";
		for (auto i : head) {
			cout << itemp << " : " << i << endl;
			itemp++;
		}
		cout << "Plese select a feild to operate on.\n>";
		cin >> feild1;
	} while (!(0 <= feild1 && feild1 <= head.size()));
	do {
		cout << "\n\nPlese select an operation type:\n 1 - Frequency Search. This will generate a list of each distinct element in the feild, ordered by frequency."
			<< "\n 2 - Value Search. This will generate a list of each distinct element in the feild, ordered by the corasponding value of another feild.\n>";
		cin >> feild2;
	} while (!(0 <= feild2 && feild2 <= 2));



	//frequency search
	if (feild2 == 1) {
		
		//var set up
		vector<string> buff;
		vector<int> sbuff;

		//parse and search
		for (auto i : data) {
			temp = i[feild1];
			auto sbuff_change = sbuff;
			for (int b = 0; b < buff.size(); b++) {
				sbuff[b] = (buff[b] == temp) ? sbuff[b]++ : sbuff[b];
			}
			if (sbuff == sbuff_change) {
				buff.push_back(temp);
				sbuff.push_back(1);
			}

		}

		//print data
		cout << "\nHere is your sorted data:\n\n";
		for (int i = 0; i < buff.size(); i++) {
			int outp = 0;
			for (int ii = 0; ii < buff.size(); ii++) {
				outp = (sbuff[outp] <= sbuff[ii]) ? ii : outp;
			}
			cout << buff[outp] << " : " << sbuff[outp] + 1 << endl;
			sbuff[outp] = -1;
			buff[outp] = "Found";
		}


	}
	else {
		//Relitive search
		
		//set up vars
		vector<string> buff;
		vector<double> sbuff;
		regex dclean("\\$");

		//ask for second input
		do {
			itemp = 0;
			cout << "Plese select a second feild to operate on (must be numerical).\n";
			for (auto i : head) {
				cout << itemp << " : " << i << endl;
				itemp++;
			}
			cout << "Plese select a feild to operate on.\n>";
			cin >> feild2;
		} while (!(0 <= feild2 && feild2 <= head.size()));

		//parse and search
		for (auto i : data) {
			temp = i[feild1];
			auto sbuff_change = sbuff;
			for (int b = 0; b < buff.size(); b++) {
				sbuff[b] = (buff[b] == temp) ? sbuff[b] += atof(regex_replace (i[feild2], dclean, "").c_str()) : sbuff[b];
			}
			if (sbuff == sbuff_change) {
				buff.push_back(temp);
				sbuff.push_back(atof(regex_replace(i[feild2], dclean, "").c_str()));
			}


		}

		//print out data
		cout << "\nHere is your sorted data:\n\n";
		for (int i = 0; i < buff.size(); i++) {
			int outp = 0;
			for (int ii = 0; ii < buff.size(); ii++) {
				outp = (sbuff[outp] <= sbuff[ii]) ? ii : outp;
			}
			cout << buff[outp] << " : " << sbuff[outp] + 1 << endl;
			sbuff[outp] = -1;
			buff[outp] = "Found";
		}

	}

	cout << "\nOperations done. Exit.";
	
	//note fix missing data with null input
	


}