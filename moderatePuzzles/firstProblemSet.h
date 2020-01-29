#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::endl;

// declaration for problem 3
struct coords {
	int x1, x2, y1, y2;
};

// 1.) swap two numbers in place
void numSwap(int[], int, int);

// 2.) find freq of occurrences of word
int wordFreq(string, string);

// 3.) find intersection of two lines given start and end point
void intersect(coords, coords);
