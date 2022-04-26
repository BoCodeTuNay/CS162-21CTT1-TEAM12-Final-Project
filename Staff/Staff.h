#pragma once
#include "../Course/Course.h"
#include "../Course/CourseInfo.h"
#include "../Student/Student.h"
#include "../Schoolyear/Schoolyear.h"
#include "../Constants/Constants.h"
#include "../List/List.h"
#include "../Class/Class.h"
#include <iostream>
#include <string.h>
#include <cassert>

//List<Schoolyear> listSchoolyears;

struct Staff {
    static List<Schoolyear> listSchoolyears;
    static List<Class> listClasses;
    Account acc;
    
    void staffMenu(List<Student>&); // CHECKED
    // return true if go to this function again, return false otherwise
    void manageSchoolyears(); // CHECKED
    void manageClasses(List<Student>&); // CHECKED
    void createSchoolyear(); // CHECKED
    void createClasses(); // CHECKED
    void viewProfile(); // CHECKED
    void changePassword(); // CHECKED
    void save_courses(fstream&);
    void save_classes(fstream&);
};

List<Schoolyear> Staff::listSchoolyears;
List<Class> Staff::listClasses;

// // At the end of a semester, an academic staff member can:

// // Export a list of students in a course to a CSV file
// void exportListStudentsToCSVFile();

// // Import the scoreboard of a course
// void importScoreboard();

// // View the scoreboard of a course
// void viewScoreboardOfCourse();

// // Update student result
// void updateStudentResult();

// View the scoreboard of a class
// void viewScoreboardOfClass(); 

#include "Staff.cpp"
