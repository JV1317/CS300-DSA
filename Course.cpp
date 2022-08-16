//============================================================================
// Name        : Course.cpp
// Author      : Jonathan Vest
// Version     : 1.0
// Description : Advising assistant program
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Course.h"
#include "Utils.h"

using namespace std;


//Define parse
void Course::parse(string str, char del) {
	vector<string> tempVect = split(str, del);			//call split and store in tempVect

	for (unsigned int i = 0; i < tempVect.size(); i++) { //loop thourhg tempVect
		if (i == 0) {									 //If first token set token to CourseNumber
			this->courseNumber = tempVect[i];
		}
		else if (i == 1) {                               //Else If second token set token to courseName
			this->courseName = tempVect[i];
		}
		else {
			prerequisite.push_back(tempVect[i]);		//Anything greater than 2nd token add to prerequisite vector
		}
	}
}

void Course::print() {
	sort(prerequisite.begin(), prerequisite.end());				//Sort the course prereqs in acending order	
	cout << courseNumber << " | " << courseName << " | ";		//Output the Course ID and name
	if (prerequisite.size() > 0) {
		cout << " Prerequisites:";
		for (unsigned int i = 0; i < prerequisite.size(); i++) {	//loop though list of prereqs for course and output		
			cout << " " << prerequisite[i];
			if (i < prerequisite.size() -1) {
				cout << ","; 
			}
		}
	}
	cout << endl;
}