#pragma once
#include "List.h"
#include "Course.h"
#include "Constants.h"


struct CourseScore {
    Course pCourse;
    Score pScore;
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