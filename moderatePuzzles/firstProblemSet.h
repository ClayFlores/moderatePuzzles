#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <math.h> // for signbit

using std::string;
using std::cout;
using std::endl;
using std::array;

// declaration for problem 3
struct coords {
	int x1, x2, y1, y2;
};

// 1.) swap two numbers in place
void numSwap(array<int,5>, int, int);

// 2.) find freq of occurrences of word
int wordFreq(string, string);

// 3.) find intersection of two lines given start and end point
void intersect(coords, coords);

// 4.) check to see if someone has won tic tac toe
void isWinner(std::vector<char>);

// 5.) find number of trailing zeros of n!
int trailZero(int);

// 6.) find the smallest diff between two arrays
int smallDiff(array<int, 5>, array<int, 5>);

// 7.) find the max of two numbers without if-else or other comparison operators
bool largerNum(int, int);