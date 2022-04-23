#pragma once

#include "..\\List\\List.h"
#include "..\\Date\\Date.h"
#include "..\\Account\\Account.h"
#include "CourseInfo.h"
#include "Score.h"

#include <iostream>
#include <string>

using namespace std;

struct StudentScore{
    Account profile;
    Score score;
};

struct Course {
 
	List <StudentScore> Student; // -> scoreboard ???
    CourseInfo info;

    Course(){};
    
	void viewCourses(); //move to courseInfo
    void updateCourse(); //move to courseInfo
    void viewStudents(); 
    void exportStudents(); // to a CSV file
	void viewScoreboard(); //
    void addStudent();
    void isRegistrable();
};

// #include "Course.cpp"
