#pragma once
#include <fstream>
#include "../List/List.h"
#include "../Constants/Constants.h"
#include "../Score.h"
#include "../Date/Date.h"
#include "../Course/Course.h"
#include "../Course/CourseInfo.h"

struct CourseScore {
    Course* pCourse;
    Score* pScore;

    CourseScore(Course* pC = NULL, Score* pS = NULL) : pCourse(pC), pScore(pS) {}
};

struct Student {

    Account acc;

    char class_name[MAXSTR+1];
    bool fClass[8][5];
    long long class_id;

    List<CourseScore> CoursesList;

    void studentMenu(List <Course*> &pOpenCourse);
    void viewProfile();
    void changePassword();
    int CurCourses();
    void enrolledCourse(List<Course*> &pOpenCourse);
    void viewCourses();
    void removeCourse(char id[MAXID+1]);    
    void init_StudentInfo();
    void listOfCourses();
    int listOfCourseStudied();
    void viewScoreBoard();
    void updateResult();
    void viewListOpenCourse(List <Course*> &pOpenCourse);
    void load_data(ifstream &fin, List<Course*> &pAllCourses);
    void save_data(ofstream &fout);
    void viewCoursesWillStudy();
};

#include "Student.cpp"