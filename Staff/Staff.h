#pragma once
//#include "Course.h"
#include "Schoolyear.h"
#include "constants.h"
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
    void createSchoolYear(List <Schoolyear> &listSchoolyears);

    // Create several classes for 1st year students
    void createClasses(List <Class> &classes);

    // Add new 1st year students to 1st-year classes
    void addStudentToClasses();
 
    // At the beginning of a semester:

    // Create a semester: 1, 2, or 3, school year, start date, end date
    void createSemester(List <Schoolyear> &listSchoolyears);

    // Create a course registration session: start date, end date.
    void createCourse();

    // Add a course to this semester
    void addCourseToSemester(List <Schoolyear> &listSchoolyears);

    // View the list of courses
    void viewListCourses(List <Schoolyear> &listSchoolyears);

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
bool cmp_course(const Course& c1, const Course& c2);
#include "Staff.cpp"
