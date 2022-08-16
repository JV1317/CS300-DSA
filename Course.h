//============================================================================
// Name        : Course.h
// Author      : Jonathan Vest
// Version     : 1.0
// Description : Advising assistant program
//============================================================================

#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

using namespace std; 

//Define Course Structure
class Course {

public:
	string courseNumber;
	string courseName;
	vector <string> prerequisite;

	void parse(string str, char del);
	void print();


};

#endif