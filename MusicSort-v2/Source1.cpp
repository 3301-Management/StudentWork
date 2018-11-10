#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

//User input functions

int prompt1(string** input, int x, int y) {
	int in = 0;
	cout << "\n\nHere are the data feilds that were parsed from the file:\n";
	int i = 0;
	for (; i < x; i++) {
		cout << i << ":  " << input[i][0] << endl;
	}
	cout << "Plese select a feild to operate on.\n>";
	cin >> in;
	if (!(0 <= in && in <= i)) {
		cout << "\n\nBad Input. Plese try agin.\n";
		in = prompt1(input, x, y);
	}
	else {
		return in;
	}

}

int prompt2(string** input, int x, int y) {
	int in = 0;
	cout << "\n\nPlese select an operation type:\n 1 - Frequency Search. This will generate a list of each distinct element in the feild, ordered by frequency."
		<< "\n 2 - Value Search. This will generate a list of each distinct element in the feild, ordered by the corasponding value of another feild.\n>";
	cin >> in;
	if (!(0 <= in && in <= 2)) {
		cout << "\n\nBad Input. Plese try agin.\n";
		in = prompt2(input, x, y);
	}
	if (in == 2) {
		cout << "Plese select a second feild to operate on (must be numerical).\n";
		int i = 0;
		for (; i < x; i++) {
			cout << i << ":  " << input[i][0] << endl;
		}
		cout << "\n>";
		cin >> in;
		if (!(0 <= in && in <= i)) {
			cout << "\n\nBad Input. Plese try agin.\n";
			in = prompt1(input, x, y);
		}
	}
	else {
		in = -1;
	}

	return in;


}


int main() {
	//get input
	string file;
	cout << "Plese specifiy abosolute path to input file. \n>";
	cin >> file;

	// for debug function
	//file = "/music/dis.tsv";


	//declaring vars
	ifstream input(file.c_str());
	regex pattern("[^\\t]+|\\t\\t");
	static const sregex_token_iterator end;
	string temp = "";
	int y = 0;
	int x = 0;

	//defining x and y
	while (getline(input, temp)) {
		y++;
	}

	ifstream input2(file.c_str());
	getline(input2, temp);


	for (sregex_token_iterator i(temp.begin(), temp.end(), pattern); i != end; ++i) {
		x++;
	}

	//gen. of storage arr
	string f1[x][y];

	//filling storage

	for (int ii = 0; ii < y; ii++) {
		int x_count = 0;
		for (sregex_token_iterator i(temp.begin(), temp.end(), pattern); i != end; ++i) {
			f1[x_count][ii] = *i;
			x_count++;
		}
		getline(input2, temp);	
	}

	////prints out the storage block
	//for (int i = 0; i < y; i++) {
	//	for (int ii = 0; ii < x; ii++) {
	//		 cout << f1[ii][i];
	//	}
	//}

	//operations

	// sets up a pointer and propts usr on what they want to do
	string** _f1 = new string*[x];
	for (int i = 0; i < x; i++) {
		_f1[i] = f1[i];
	}

	int feild = prompt1(_f1, x, y);
	int relitive_s = prompt2(_f1, x, y);
	string buff[1000];
	int buffp = 0;


	//Frequency Search
	if (relitive_s == -1) {
		int sbuff[1000];
		for (int i = 0; i < 1000; i++) {
			sbuff[i] = 0;
		}
		for (int i = 0; i < y; i++) {
			temp = f1[feild][i];
			bool is_new = false;
			int b = 0;
			for (; (b <= buffp) && (temp != buff[b]); b++) {
				is_new = (b == buffp) ? true : false;
			}
			if (is_new) {
				buff[b - 1] = temp;
				sbuff[b - 1] = 0;
				buffp++;
			}
			else {
				sbuff[b]++;
			}
		}
		//prints out results 
		cout << "\nHere is your sorted data:\n\n";
		for (int i = 0; i <= buffp; i++) {
			int t1 = 0;
			for (int ii = 0; ii <= buffp; ii++) {
				t1 = (sbuff[t1] <= sbuff[ii]) ? ii : t1;
			}
			if (sbuff[t1] != 0 && buff[t1] != "" && buff[t1] != "\t\t"){
				cout << buff[t1] << " : " << sbuff[t1] + 1 << endl;
			}
			buff[t1] = "Found";
			sbuff[t1] = -1;

		}
	}
	//Relative search
	else {
		//sets up vars and $ parsing 
		double sbuff[1000];
		for (int i = 0; i < 1000; i++) {
			sbuff[i] = 0;
		}
		double stemp = 0;
		regex dclean("\\$");

		//moves through arr and generates a list of entries for "feild"
		for (int i = 0; i < y; i++) {
			temp = f1[feild][i];
			bool is_new = false;
			int b = 0;
			for (; (b <= buffp) && (temp != buff[b]); b++) {
				is_new = (b == buffp) ? true : false;
			}
			if (is_new) {
				buff[b - 1] = temp;
				buffp++;
			}

		}
		//moves through arr and adds up data in "relitive_s" for each item in buff
		for (int i = 0; i < y; i++) {
			temp = f1[feild][i];
			string test = regex_replace(f1[relitive_s][i], dclean, "").c_str();
			stemp = atof((regex_replace(f1[relitive_s][i], dclean, "").c_str()));
			int b = 0;
			for (; b <= buffp && temp != buff[b]; b++) {}
			sbuff[b] += stemp;

		}
		//prints out results 
		cout << "\nHere is your sorted data:\n\n";
		for (int i = 0; i <= buffp; i++) {
			int t1 = 0;
			for (int ii = 0; ii <= buffp; ii++) {
				t1 = (sbuff[t1] <= sbuff[ii]) ? ii : t1;
			}
			if (sbuff[t1] != 0 && buff[t1] != "" && buff[t1] != "\t\t") {
				cout << buff[t1] << " : " << sbuff[t1] << endl;
			}
			buff[t1] = "Found";
			sbuff[t1] = -1.3;

		}





	}
	cout << "\nOperations done. Exit.";


}