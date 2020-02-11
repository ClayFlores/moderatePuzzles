#include "secondProblemSet.h"

void printIndVal(char);
// this function takes an int as an arg and returns and english version of it
// (100 would be one hundred) max int val is 2147483648 on this compiler (2^31)
// this is FAIRLY close, just need to add edge cases for numbers like thirty (english sucks sometimes)
void intToEng(int toChange) {
	string intAsStr = std::to_string(toChange); // string version of the int
	int i = 0; // iterator
	int size = intAsStr.length();

	for (int i = 0; i < size; i++) {
		printIndVal(intAsStr[i]);
		if (10 - i == 10)
			cout << " billion ";
		else if (10 - i == 9) {
			cout << " hundred ";
		}
		else if (10 - i == 8) {
			cout << "ty ";
		}
		else if (10 - i == 7) { // skip 7, not needed
			cout << " million ";
		}
		else if (10 - i == 6) {
			cout << " hundred ";
		}
		else if (10 - i == 5) {
			cout << "ty ";
		}
		else if (10 - i == 4) { // skip 7, not needed
			cout << " thousand ";
		}
		else if (10 - i == 3) {
			cout << " hundred ";
		}
		else if (10 - i == 2) {
			cout << "ty ";
		}

		}
}

void printIndVal(char num) {
	int temp = num - '0';
	switch (temp) {
	case 1:
		cout << "one";
		break;
	case 2:
		cout << "two";
		break;
	case 3:
		cout << "three";
		break;
	case 4:
		cout << "four";
		break;
	case 5:
		cout << "five";
		break;
	case 6:
		cout << "six";
		break;
	case 7:
		cout << "seven";
		break;
	case 8:
		cout << "eight";
		break;
	case 9:
		cout << "nine";
		break;
	default:
		break;
	}
}

// this function allows you to do math operations on integers
// it will only use addition to do these tasks
// op will be: 1 for sub, 2 for mult, 3 for div
void addOnly(int num1, int num2, int op) {
	int sum = 0;
	if (op == 1) { // sub
		cout << num1 << " - " << num2 << " = ";
		num1 += -num2;
		cout << num1 << endl;
	}
	else if (op == 2) { // mult
		cout << num1 << " * " << num2 << " = ";
		for (int i = 0; i < num2; i++) {
			sum += num1;
		}
		cout << sum << endl;
	}
	else if (op == 3) { // div
		if (num2 != 0) { // div by zero check
			cout << num1 << " / " << num2 << " = ";
			while (num1 + -num2 > 0) {
				num1 += -num2;
				sum++;
			}

			cout << sum << endl;
		}
		else
			cout << "cannot div by zero" << endl;
	}
	else
		cout << "no op specified" << endl;
}

// looks through a list of people and checks the year that most people were alive
// this would be really slow for long lists, i think a hash table would work better
// in that situation
void mostAlive(std::vector<lives> list) {
	int mostLive = 0;
	int i = 0;
	int year = 0;
	yrCount temp;
	std::vector<yrCount> yrTally;

	for (int j = 0; j < list.size(); j++) {
		year = list[i].born;
		while (i < (list[i].died - list[i].born))
		{
			if (yrTally.size() != NULL && (year == yrTally[i].year)) {// if in registry
				yrTally[i].count++; // inc count
				if (yrTally[i].count > mostLive)
					mostLive = yrTally[i].count; // new highest
			}
			else { // adds to registry
				temp.year = year;
				temp.count = 1;
				yrTally.push_back(temp);
			}

			i++;
		}
		i = 0;
	}
	cout << mostLive << endl;
}