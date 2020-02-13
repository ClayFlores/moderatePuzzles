#include "thirdProblemSet.h"

void printString(std::vector<string>);
//
//
//
void mockXML(string strToConvert) {
	int i = 0;
	string temp;
	bool subFlag = 0; 
	std::vector<string> tokenized;
	if (strToConvert[0] == '<') { // need valid start char
		while (strToConvert[i] != '>') { // as long as it isn't the end char
			if (strToConvert[i] == '<' && subFlag == 1) { // means there is another string
				mockXML(strToConvert.substr(strToConvert[i])); // recursively calls from this pos onward
			}
			else if (strToConvert[i] != ' ' && strToConvert[i] != '=' && strToConvert[i] != '"' && strToConvert[i] != '<') {
				temp += strToConvert[i];
			}
			else if (temp != "") {
				tokenized.push_back(temp);
				temp = ""; // empties for reuse
			}
			subFlag = 1;
			i++;
		}
	}
	// should be tokenized at this point
	// only 6 options will just do if else block
	printString(tokenized);
}
void printString(std::vector<string> tokenized) {
	int i = 0;
	while (i < tokenized.size()) {
		if (tokenized[i] == "family")
			cout << " 1 ";
		else if (tokenized[i] == "person")
			cout << " 2 ";
		else if (tokenized[i] == "firstName")
			cout << " 3 ";
		else if (tokenized[i] == "lastName")
			cout << " 4 ";
		else if (tokenized[i] == "state")
			cout << " 5 ";
		else
			cout << tokenized[i];
		i++;
	}
}