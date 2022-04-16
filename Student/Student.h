#pragma once
#include "List/List.h"
#include "Course/Course.h"
#include "Constants/Constants.h"
#include "Score.h"
#include "Date/Date.h"

struct CourseScore {
    Course pCourse;
    Score score;
};

struct Student {
    string username;
    string password;

    string name;
    string id;
    string email;

    string class_name;
    long long class_id;

    List<CourseScore> pScore;

    void enrolledCourse(const List<Course> &pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(string id);
    void init_classid();
    void listOfCourses();
};

#include "Student/Student.cpp"