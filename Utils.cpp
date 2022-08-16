//============================================================================
// Name        : Utils.cpp
// Author      : Jonathan Vest
// Version     : 1.0
// Description : Advising assistant program
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Course.h"

using namespace std;

//Define function to split a vector
vector<string> split(string str, char del) {
    string temp = "";
    vector<string> retval;

    string::size_type i = 0;                //initalize i for beginning of substring
    string::size_type j = str.find(del);    //initalize j for end pos of substring
   
    while (j != string::npos) {             //loop while not end of string
        temp = str.substr(i, j-i);          //temp holds the value of substring
        retval.push_back(temp);             //push temp on retVal
        i = ++j;                            //increment j and assign to i
        j = str.find(del, j);               //set j to next del positon
        

        if (j == string::npos) {            //j is the end of the sting
            retval.push_back(str.substr(i, str.length()));  //push final substring on retval
        }
    }
    return retval;                          //return vector holding split string 
}


/**
 * Load a CSV file containing courses into a container
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the courses read
 */
//vector<Course>* loadcourses(vector<Course> &courses, string csvPath)
void loadcourses(vector<Course> &courses, string csvPath) {
   // vector<Course>* courses = new vector<Course>();
    ifstream inFS;
    string line;

    //Open File
    inFS.open(csvPath);

    //Check if file is open
    if (!inFS.is_open()) {
        cout << "\nCould not open file " << csvPath << endl;
        return;
    }

    do {
        getline(inFS, line); //Get the first line from the file and place it in line
        if (line.size() > 0) {
            Course* course = new Course();
            course->parse(line, ',');   //call parse passing line and delimiter creating course object
            courses.push_back(*course); //place course object in courses vector
        }

    } while (!inFS.eof());
    inFS.close();

    /*This block of code loops through the courses vector
    * and the prerequisite vector checking if each course number 
    * placed in the prereq vector is also contained in the courses vector
    */
    for (unsigned int i = 0; i < courses.size(); i++) {
        for (unsigned int j = 0; j < courses[i].prerequisite.size(); j++) {
            bool courseFound = false;
            for (unsigned int k = 0; k < courses.size(); k++) {
                if (courses[k].courseNumber == courses[i].prerequisite[j]) {
                    courseFound = true;

                }
            }
            if (!courseFound) { 
                cout << "Error Prerequisite " << courses[i].prerequisite[j] << " not found in Courses list " << endl;
            }

        }

    }
   
    //return courses;
}

//Search function returning Course pointer
Course* search(vector<Course> &courses, string courseNumber) {
    Course* retCourse = nullptr;
    for (unsigned int i = 0; i < courses.size(); i++) {
        if (courseNumber == courses[i].courseNumber) {
            retCourse = &courses[i];
        }
    }
    return retCourse;
}


