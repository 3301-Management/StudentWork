#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

void debug(){
	return;
}
//
//void O1(string* in, int x, int y) {
//	int song_count = 0;
//	string buff[100];
//	string temp = in[;
//	regex pattern("[^\\t]+");
//
//	for (sregex_token_iterator i(temp.begin(), temp.end(), pattern); i != end; ++i) {
//		x++;
//	}
//
//
//	for (int i = 0; i < y; i++) {
//		if ()
//	}
//
//	return;
//}
//
//void O2(string* in, int x, int y) {
//	return;
//}
//
//void O3(string* in, int x, int y) {
//	return;
//}
//
//void O4(string* in, int x, int y) {
//	return;
//}

int prompt1(string* input, int x, int y) {
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

int prompt2(string* input, int x, int y) {
	int in = 0;
	cout << "\n\nPlese select an operation type:\n 1 - Frequency Search. This will generate a list of each distinct element in the feild, ordered by frequency."
		<< "\n 2 - Value Search. This will generate a list of each distinct element in the feild, ordered by the corasponding value of another feild.\n>";
	cin >> in;
	if (!(0 <= in && in <= 1)) {
		cout << "\n\nBad Input. Plese try agin.\n";
		in = prompt2(input, x, y);
	}
	if (in == 2) {
		cout << "Plese select a second feild to operate on (must be numerical).\n>";
		int i = 0;
		for (; i < x; i++) {
			cout << i << ":  " << input[i][0] << endl;
		}
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
	//cin >> file;
	
	// for debug function
	file = "/music/dys.txt";


	//declaring vars
	ifstream input(file.c_str());
	regex pattern("[^\\t]+");
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
		debug();
		getline(input2, temp);
	}

	////prints out the storage block
	//for (int i = 0; i < y; i++) {
	//	for (int ii = 0; ii < x; ii++) {
	//		 cout << f1[ii][i];
	//	}
	//}

	//operations

	string* p_f1 = &f1;
	int feild = prompt1(p_f1, x, y);
	int relitive_s = prompt2(p_f1, x, y);
	int count = 1;
	if (relitive_s = -1) {
		string p1 = f1[feild][1];
		for (int i = 0; i < y; i++) {
			if (f1[feild][i] != p1){
				for ()
				count++;
				p1 = f1[feild][i];
			}

		}
	}

	

	cout << "\nOperations done. Exit.";
		

}