#pragma once

#include <string>
#include <vector>
#include <math.h> // signbit
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// 8.) given an int print out an english text version of it
void intToEng(int);

// 9.) use only add operator to do mult/div/sub
void addOnly(int, int, int);

// 10.) given list of birth/death find year with most people alive
struct lives{
	string name;
	int born;
	int died;
};
struct yrCount {
	int year, count;
};
void mostAlive(std::vector<lives>);

//11.) wooden diving board
void dBoard(int);
