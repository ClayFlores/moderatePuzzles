// This is a main funtion that will run various puzzles of medium difficulty from 
// the book "Cracking the Coding Interview"
//


#include <iostream>
#include "firstProblemSet.h"
using std::cout;
using std::endl;

void printArray(int[]);
int main() {

	int genArr[5] = { 1,2,3,4,5 };
	int response = -1;
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

	while (response != 99) {
		cout << "Which example would you like to see?" << endl;
		cout << "1. Number Swapper" << endl;
		cout << "2. Word Frequency Finder" << endl;
		cout << "3. Point of intersection" << endl;
		cout << "4. check to see if tic tac toe is won" << endl;

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
		default:
			cout << "exiting" << endl;
			response = 99;
		}
		cout << endl;
	}
	return 0;
}


void printArray(int arr[]) {
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

