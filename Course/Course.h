#pragma once
#include <iostream>

struct Course {
 
	Student arr[]; // -> scoreboard ???
 
    Date start_date;
    Date end_date;
 
    string id; // mã học phần
    string name; // tên học phần
    string lecturer; // tên GV
    int numCredits;
    int maxStudents{50};
	int day[7]; // "MON", "TUE", "WED", "THU", "FRI", "SAT"; 
	// S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)
    int session; // 1 -> 4
 
	Void viewCourses();
    void updateCourse();
    void viewStudents();
    void exportStudents(); // to a CSV file
	void viewScoreboard(); //
 
};

#include "Course.cpp"