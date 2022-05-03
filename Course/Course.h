#pragma once

#include "..\\List\\List.h"
#include "..\\Date\\Date.h"
#include "..\\Account\\Account.h"
#include "CourseInfo.h"
#include "../Score.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct StudentScore{
    Account acc;
    Score* score;
};

struct Course {
    CourseInfo info;
	List <StudentScore> student; // -> scoreboard ???

    Course(){};
    Course(char _ID[MAXSTR+1]){
        strcpy(info.ID, _ID);
    }
    
    void viewStudentsList(); 
	void viewScoreboard(); //
    void addStudent();
    void isRegistrable();
    void manageCourseInfo();
    void exportStudentsToCSV();
    void importStudentsFromCSV();

    void load_data(fstream &fin);
    void save_data(fstream &fout);
};

bool cmp_course(const Course& s1, const Course& s2);

#include "Course.cpp"
