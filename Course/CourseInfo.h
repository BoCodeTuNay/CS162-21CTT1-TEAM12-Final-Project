#pragma once

#include "..\\Date\\Date.h"

struct CourseInfo
{
    char ID[MAXSTR+1]; // mã học phần
    char semesterID[MAXSTR+1];
    char schoolyearID[MAXSTR+1];

    Date start_date;
    Date end_date;
    char name[MAXSTR+1]; // tên học phần
    char lecturer[MAXSTR+1]; // tên GV
    int numCredits;
    int maxStudents{50};
	int day[7]; // "MON", "TUE", "WED", "THU", "FRI", "SAT"; 
	// S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)
    // int session; // 1 -> 4

    void input();
    void update();
    void view();
};