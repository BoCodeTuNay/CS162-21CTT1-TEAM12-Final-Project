#pragma once
#include "../List/List.h"
#include "../Constants/Constants.h"
#include "Score.h"
#include "../Date/Date.h"
#include "../Course/Course.h"
#include "../Course/CourseInfo.h"

struct CourseScore {
    CourseInfo* pCourse;
    Score* pScore;

    CourseScore(CourseInfo* pC = NULL, Score* pS = NULL) : pCourse(pC), pScore(pS) {}
};

struct Student {

    Account acc;

    char class_name[MAXSTR+1];
    bool fClass[7][5];
    long long class_id;

    List<CourseScore> CoursesList;

    int CurCourses();
    List<CourseInfo> enrolledCourse(List<Course*> pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(char id[MAXID+1]);
    void init_StudentInfo();
    void listOfCourses();
};

#include "Student.cpp"