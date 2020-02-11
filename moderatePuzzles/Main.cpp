// This is a main funtion that will run various puzzles of moderate difficulty from 
// the book "Cracking the Coding Interview"
//


#include <iostream>

#include "firstProblemSet.h"
#include "secondProblemSet.h"

using std::cout;
using std::endl;

void printArray(std::array<int,5>);

int main() {

	std::array<int, 5> genArr = { 1,2,3,4,5 };
	std::array<int, 5> majArr = {20,14,8,16,32};

	int response = -1;
	int num1 = 22;
	int num2 = 44;
	string txt = "That, that is, is. That, that is not, is not.";
	coords coords1;
	coords coords2;
	
	coords1.x1 = 3;
	coords1.x2 = 1;
	coords1.y1 = 1;
	coords1.y2 = 3;

	coords2.x1 = 1;
	coords2.x2 = 3;
	coords2.y1 = 1;
	coords2.y2 = 3;

	std::vector<char> gameBoard = { 'O','X','O','O','X','X','O',' ','X' };

	lives person1, person2, person3;
	person1.name = "Simon";
	person1.born = 1902;
	person1.died = 1955;

	person2.name = "Alvin"; // this feels sad to write
	person2.born = 1912;
	person2.died = 1912;

	person3.name = "Theodore";
	person3.born = 1911;
	person3.died = 1963;

	std::vector<lives> lifeList = { person1, person2, person3 };

	while (response != 99) {
		cout << "Which example would you like to see?" << endl;
		cout << "1. Number Swapper" << endl;
		cout << "2. Word Frequency Finder" << endl;
		cout << "3. Point of intersection" << endl;
		cout << "4. check to see if tic tac toe is won" << endl;
		cout << "5. find number of trailing zeros for n!" << endl;
		cout << "6. Find the smallest difference of two arrays" << endl;
		cout << "7. Check to see which num is larger" << endl;
		cout << "8. Print an english version of an int" << endl;
		cout << "9. Use only add operator for mult / divide / subtract" << endl;
		cout << "10. find the year that most people in a list were alive" << endl;

		cout << "99. Exit" << endl;
		std::cin >> response;
		switch (response) {
		case 1:
			std::cout << "array: ";
			printArray(genArr);
			cout << "swapping first and last positions" << endl;
			numSwap(genArr, 4, 0);
			printArray(genArr);
			break;
		case 2:
			cout << txt << endl;
			cout << "found " << wordFreq(txt, "is") << " instances." << endl;
			break;
		case 3:
			intersect(coords1, coords2);
			break;
		case 4:
			isWinner(gameBoard);
			break;
		case 5:
			trailZero(10);
			trailZero(4);
			break;
		case 6:
			cout << "Smallest diff between General and Major " << smallDiff(genArr, majArr) << endl;
			break;
		case 7:
			cout << "Let's see if " << num1 << " is larger than " << num2 << endl;
			if (!largerNum(num1, num2)) { // since returning a 1 for this particular bit means neg
				cout << num1 << " is larger" << endl;
			}
			else
				cout << num2 << " is larger" << endl;
			break;
		case 8:
			intToEng(123456);
			break;
		case 9:
			addOnly(5, 3, 1); // 5, 3, sub
			addOnly(5, 3, 2); // 5, 3, mult
			addOnly(10, 5, 3); // 10, 5, div
			addOnly(23, 5, 3); // div
			break;
		case 10:
			mostAlive(lifeList);
			break;
		default:
			cout << "exiting" << endl;
			response = 99;
		}
		cout << endl;
	}
	return 0;
}


void printArray(std::array<int,5> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

