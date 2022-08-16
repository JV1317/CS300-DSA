//============================================================================
// Name        : Main.cpp
// Author      : Jonathan Vest
// Date        : 8/14/2022
// Version     : 1.0
// Description : Advising assistant program
//============================================================================

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Course.h"
#include "Utils.h"


using namespace std; 

//function to compare Course Objects
bool compareCourses(Course &courseOne, Course &courseTwo)
{
    return (courseOne.courseNumber < courseTwo.courseNumber);
}


int main(int argc, char* argv[]) {

    string csvPath;
   
    vector<Course> courses;
    string courseNumber = "";
    Course* course = nullptr;

    cout << "Welcome to The Advising Assistant!\n" << endl; 

    int choice = 0;
    while (choice != 9) {
        cout << "  <<<<<<Menu>>>>>>" << endl;
        cout << "  1. Load Courses" << endl;      //Load the file data into the data structure. Note that before you can print the course information or the sorted list of courses, you must load the data into the data structure.
        cout << "  2. Print Course List" << endl; //This will print an alphanumeric list of all the courses in the Computer Science department.
        cout << "  3. Print Course " << endl;    //This will print the course title and the prerequisites for any individual course.
        cout << "  9. Exit" << endl;              //Exit program
        cout << "\nWhat would you like to do? " << endl;
        cin >> choice;

        switch (choice) {

        case 1:
            // Complete the method call to load the courses
            cout << "\nPlease enter file name or path of file to load." << endl;
            cin >> csvPath; 
            loadcourses(courses, csvPath);
            cout << "\n" << courses.size() << " Courses loaded.\n" << endl;
            break;

        case 2:
            // Loop and display the courses
            if (courses.size() > 0) {
                std::sort(courses.begin(), courses.end(), compareCourses);  //Sort courses vector 
                cout << "\nHere is a list of available computer sciance courses and their prerequisites:\n" << endl;
                for (unsigned int i = 0; i < courses.size(); ++i) {
                    courses[i].print();
                }
                cout << endl;
            }
            else {
                cout << "\nSorry, no courses to display.\n" << endl; 
            }
            break;


        case 3:
            //Search list for course
            
            
            cout << "\nEnter course ID to search: " << endl;
            cin >> courseNumber;
            course = search(courses, courseNumber);
            
            if (course != NULL) {
                cout << "\nCourse Found:" << endl; 
                course->print();
                cout << endl; 
            }
            else {
                cout << "\nCourse not found.\n" << endl; 
            }
            break;

        default:
            cout << "\nNot a valid selection. Please make a selection from the menu.\n" << endl; 
            cin.clear(); 
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << "\nThank you for using The Advising Assistant! Good bye." << endl;

	return 0; 
}