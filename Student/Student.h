#pragma once
#include "../List/List.h"
#include "../Course/Course.h"
#include "../Constants/Constants.h"
//#include "Score.h"
#include "../Date/Date.h"
#include "Course/CourseInfo.h"

struct CourseScore {
    * pCourse;
    Score score;
};

struct Student {

    Account acc;

    char class_name[MAXSTR+1];
    long long class_id;

    List<CourseScore> pScore;

    void enrolledCourse(List<Course> pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(char id[MAXNAME]);
    void init_classid();
    void listOfCourses();
};

#include "Student.cpp"