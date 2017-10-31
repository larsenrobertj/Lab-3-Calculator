// Lab3.cpp : Version 0.1.6
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
		else if (!operationLast && (sub[i] == '+' || sub[i] == '-' || sub[i] == '*' || sub[i] == '/' || sub[i] == '^')) {
			operationLast = true;
			operations.push_back(sub[i]);
		}
		else if (operationLast && (sub[i] == '+' || sub[i] == '-')) {
			operationLast == false;
			nums.push_back((sub[i] == '+' ? 1 : -1));
			operations.push_back('*');
		}
		else if (isdigit(sub[i]) || sub[i] == '.') {
			operationLast = false;
			ostringstream s;
			if (sub[i] == '.')
				s << '0';
			s << sub[i];
			while (i + 1 < t && (isdigit(sub[i + 1]) || sub[i + 1] == '.'))
				s << sub[++i];
			nums.push_back(stod(s.str()));
			s.clear();
		}
		else {
			cout << "Error: A character could not be interpreted: " << sub[i] << endl;
			system("pause");
			exit(1);
		}
	}
	while (operations.size() > 0 && nums.size() >= 2) {
		int i = 0;
		char c;
		double a, b;
		char ops[] = { '^','*','/','+','-' };
		int j = 0;
		if (operations.size() > 1)
			for (i = 0; i < operations.size(); i++) {
				if (operations.at(i) == ops[j])
					break;
				if (i + 1 >= operations.size() && j < strlen(ops)) {
					j++;
					i = 0;
				}
			}
		c = operations.at(i);
		operations.erase(operations.begin() + i, operations.begin() + i + 1);
		a = nums.at(i);
		b = nums.at(i + 1);
		nums.erase(nums.begin() + i + 1, nums.begin() + i + 2);
		switch (c) {
		case '+':
			nums.at(i) = a + b;
			break;
		case '-':
			nums.at(i) = a - b;
			break;
		case '*':
			nums.at(i) = a * b;
			break;
		case '/':
			nums.at(i) = (double)(a / b);
			break;
		case '^':
			nums.at(i) = pow(a, b);
			break;
		default:
			break;
		}
	}
	if (operations.size() > 0) {
		cout << "Error: There are more operations than numbers." << endl;
		system("pause");
		exit(1);
	}
	return nums.front();
}

int main()
{
	char* s = "(9)";
	cout << s << " = " << parseString(s, 0, strlen(s)) << endl;
	system("pause");
	return 0;
}
