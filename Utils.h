//============================================================================
// Name        : Utils.h
// Author      : Jonathan Vest
// Version     : 1.0
// Description : Advising assistant program
//============================================================================

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

using namespace std; 

vector<string> split(string str, char del);

void loadcourses(vector<Course>& courses, string csvPath);

Course* search(vector<Course> &courses, string courseNumber);

#endif