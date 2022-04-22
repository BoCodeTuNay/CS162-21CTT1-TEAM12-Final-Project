#pragma once
#include "../List/List.h"
#include "../Course/Course.h"
#include "../Constants/Constants.h"
//#include "Score.h"
#include "../Date/Date.h"

struct CourseScore {
    Course pCourse;
    Score score;
};

struct Student {
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];

    string class_name;
    long long class_id;

    List<CourseScore> pScore;

    void enrolledCourse(const List<Course> &pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(string id);
    void init_classid();
    void listOfCourses();
};

#include "Student.cpp"