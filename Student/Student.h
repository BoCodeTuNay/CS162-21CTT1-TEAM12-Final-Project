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
<<<<<<< HEAD
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];
=======

    char id[MAXID];
    char name[MAXNAME];
>>>>>>> 919e43ed2fa22b260a21214cde32d02cae52664f

    char class_name[MAXSTR];
    long long class_id;

    List<CourseScore> pScore;

    void enrolledCourse(List<Course> pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(char id[MAXNAME]);
    void init_classid();
    void listOfCourses();
};

#include "Student.cpp"