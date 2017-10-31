// Lab3.cpp : Version 0.1.1
//
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

double parseString(char* sub, int f, int t) {
	int subPar = 0;
	vector<char> operations;
	vector<double> nums;
	bool operationLast = true;
	for (int i = f; i < t; i++) {
		if (sub[i] == '(') {
			operationLast = false;
			int braccount = 0;
			for (int j = i; j <= t; j++) {
				if (sub[j] == '(')
					braccount++;
				if (sub[j] == ')') {
					if (--braccount == 0) {
						if (i + 1 != j)
							nums.push_back(parseString(sub, i + 1, j));
						i = j;
						break;
					}
				}
				if (j == t) {
					cout << "Error: A bracket was opened but not closed." << endl;
					system("pause");
					exit(1);
				}
			}
		}
		else if (sub[i] == ')') {
			operationLast = false;
			cout << "Error: A bracket was closed but not opened." << endl;
			system("pause");
			exit(1);
		}
	}
	return 1;
}

int main()
{
	char* s = "(9)";
	cout << s << " = " << parseString(s, 0, strlen(s)) << endl;
	system("pause");
	return 0;
}
