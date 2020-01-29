#include "firstProblemSet.h"

bool isParallel(double, double, double, double);

// this is a function to swap numbers in place
void numSwap(int arr[], int a, int b) {
	arr[a] = arr[a] - arr[b]; // arr[a] stores 5 - 1 = 4
	arr[b] = arr[a] + arr[b]; // arr[b] stores 4 + 1 = 5
	arr[a] = arr[b] - arr[a]; // arr[a] stores 5 - 4 = 1
}


// this function parses a string and counts how many times
// a word reoccurs. The plan is to break the Text into words
// and check. ideally would make all lower / uppercase

int wordFreq(string Text, string wordToFind) {
	string currentWord;

	int i = 0; 
	int count = 0;
	
	// this breaks the string into indiv words
	while (Text[i] != NULL) { // while there is still text to parse
		if (Text[i] != ' ' && Text[i] != '.' && Text[i] != ',') // if still the same word
			currentWord += Text[i];
		else if (currentWord == wordToFind) {
			count++;
			currentWord = "";
		}
		else
			currentWord = "";
		i++;
	}
	return count;
}


// this finds whether two lines intersect or not and where
// we are only given the start and end point for each line
// assumes slope is defined
void intersect(coords lineOne,coords lineTwo) {
	double slopeOne, slopeTwo;
	double yInt1, yInt2;
	double x, y;

	// get slope 
	if (lineOne.x2 - lineOne.x1 != 0) // check for div by 0
		slopeOne = (lineOne.y2 - lineOne.y1) / (lineOne.x2 - lineOne.x1);
	if (lineTwo.x2 - lineTwo.x1 != 0) // check for div by 0
		slopeTwo = (lineTwo.y2 - lineTwo.y1) / (lineTwo.x2 - lineTwo.x1);
	
	// y intercepts
	// assume y intercept is point (0,y) and do slope formula with a point from earlier, y1 is intercept
	// slopeOne = lineOne.y2 - y1 / lineTwo.x2 - 0
	// slopeOne * lineTwo.x2 = lineOne.y2 - y1
	// slopeOne * lineTwo.x2 - lineOne.y2 = -y1
	yInt1 = -1 * (slopeOne * lineOne.x2 - lineOne.y2);
	yInt2 = -1 * (slopeTwo * lineTwo.x2 - lineTwo.y2);

	// y = mx + b == y1 = slopeOne * x1 + yInt1
	// since intersection means x1 == x2 and y1 == y2
	// slopeOne * x1 + yInt1 = slopeTwo * x1 + yInt2
	// slopeOne * x1 - slopeTwo * x1 = yInt2 - yInt1
	// x1 * (slopeOne - slopeTwo) = yInt2 - yInt1
	// x1 = ( yInt2 - yInt1 ) / (slopeOne - slopeTwo)

	// logic time
	if (isParallel(slopeOne, slopeTwo, yInt1, yInt2)) { // if not parallel
		cout << "Parallel, no intercept" << endl;
	}
	else {
		x = (yInt2 - yInt1) / (slopeOne - slopeTwo);
		y = x * slopeOne + yInt1;
		cout << "intercepts at (" << x << "," << y << ")" << endl;
	}
}

bool isParallel(double slope1, double slope2, double yInt1, double yInt2) {
	if (slope1 != NULL && slope2 != NULL) { // final step of checking for undefined lines
		if (slope1 == slope2) { // means lines are parallel or overlapping	
			if (yInt1 != yInt2) {// check y intercept? if diff then parallel
				return false; // same line, all points parallel
			}
			else
				return true;
		}
		return false;
	}
}