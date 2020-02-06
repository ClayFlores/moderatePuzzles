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