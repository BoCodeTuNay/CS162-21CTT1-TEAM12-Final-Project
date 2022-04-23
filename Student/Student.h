#pragma once
#include "../List/List.h"
// #include "../Course/Course.h"
#include "../Constants/Constants.h"
//#include "Score.h"
#include "../Date/Date.h"
#include "../Course/CourseInfo.h"

struct CourseScore {
    CourseInfo* pCourse;
    Score**pSpScore;

    CourseScore : pCourse(NULL), pSpSore(NULL);
};

struct Student {

    Account acc;

    char class_name[MAXSTR+1];
    bool fClass[7][5];
    long long class_id;

    List<CourseScore> CoursesList;

    int CurCourses();
    List<CourseInfo> enrolledCourse(List<Course> pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(char id[MAXID+1]);
    void init_StudentInfo();
    void listOfCourses();
};

#include "Student.cpp"