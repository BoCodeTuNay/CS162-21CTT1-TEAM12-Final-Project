#pragma once
#include "List.h"
#include "Course.h"
#include "Constants.h"
#include "Score.h"

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

    void enrolledCourse(List<Course> pOpenCourse);
    void viewEnrolledCourses();
    void removeCourse(string id);
};

#include "Student.cpp"