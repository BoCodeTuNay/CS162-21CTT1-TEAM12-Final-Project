#pragma once

//#include "Course.h"
//#include "Schoolyear.h"
#include "Constants/constants.h"

#include <iostream>
#include <string.h>

using namespace std;

const int MAXSTR = 50; // for other features' convenience
const int MAXID = 8; // 21125XXX

struct Staff {
 
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];
 
    // các phương thức của 1 sinh viên

    // At the beginning of a school year:

    // Create a school year
    void createSchoolYear();

    // Create several classes for 1st year students
    void createClasses();

    // Add new 1st year students to 1st-year classes
    void addStudentToClasses();
 
    // At the beginning of a semester:

    // Create a semester: 1, 2, or 3, school year, start date, end date
    void createSemester();

    // Create a course registration session: start date, end date.
    void createCourse();

    // Add a course to this semester
    void addCourseToSemester();

    // View the list of courses
    void viewListCourses();

    // Update course information
    void updateCourseInfomation();

    // Delete a course by ID
    void deleteCourse();

    // At the end of a semester, an academic staff member can:

    // Export a list of students in a course to a CSV file
    void exportListStudentsToCSVFile();
    
    // Import the scoreboard of a course
    void importScoreboard();

    // View the scoreboard of a course
    void viewScoreboardOfCourse();

    // Update student result
    void updateStudentResult();

    // View the scoreboard of a class
    void viewScoreboardOfClass(); 
};

#include "Staff.cpp"
