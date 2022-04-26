#pragma once

#include "..\\Date\\Date.h"
#include "../Account/Account.h"
#include "../Score.h"

struct CourseInfo
{
    char ID[MAXSTR+1]; // mã học phần
    // char semesterID[MAXSTR+1];
    // char schoolyearID[MAXSTR+1];

    // make sure (start_regis < end_regis < start_date < end_date)
    Date start_date;
    Date end_date;
    Date start_regis;
    Date end_regis;
    char name[MAXSTR+1]; // tên học phần
    char lecturer[MAXSTR+1]; // tên GV
    int numCredits;
    int maxStudent{50};
	int day[7]; // "MON", "TUE", "WED", "THU", "FRI", "SAT"; 
	// S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)
    // int session; // 1 -> 4

    void viewCourseInfo();
    void inputCourseInfo();
    void updateCourseInfo();
    void manageCourseInfo();

    void load_data(fstream& fin);
    void save_data(fstream& fout);
};

#include "CourseInfo.cpp"