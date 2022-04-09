#pragma once

#include "..\\List\\List.h"
#include "..\\Student\\Student.h"
#include "..\\Date\\Date.h"

#include <iostream>
#include <string>

using namespace std;

struct Course {
 
	List <Student> student; // -> scoreboard ???
 
    Date start_date; // from Minh: có nên bỏ start_date và end_date không nhỉ vì bây giờ struct Course được bỏ vào Semester đã chứa Start_date và end_date rối ấy?
    Date end_date;
 
    string id; // mã học phần
    string name; // tên học phần
    string lecturer; // tên GV
    int numCredits;
    int maxStudents{50};
	int day[7]; // "MON", "TUE", "WED", "THU", "FRI", "SAT"; 
	// S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)
    int session; // 1 -> 4
 
	void viewCourses();
    void updateCourse();
    void viewStudents();
    void exportStudents(); // to a CSV file
	void viewScoreboard(); //
 
};

#include "Course.cpp"
