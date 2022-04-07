#pragma once
#include "..\\List\\List.h"
#include "..\\Course\\Course.h"
#include "..\\constants.h"

struct Score {
    double mid_term_p;
    double process_p;
    double final_p;
};

struct CourseScore {
    Course *pCourse;
    Score *pScore;
};

struct Student {
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];

    char class_name[MAXSTR+1];
    long long class_id;

    List<CourseScore> pScore;

    void enrolledCourse(List<Course> pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse();
};

#include "Student.cpp"