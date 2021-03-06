#pragma once
#include <iostream>
#include "../Course/Course.h"
#include "../Course/CourseInfo.h"

struct Semester {
    // char ID[MAXSTR+1]; 
    int index;

    Date start_date;
    Date end_date;
    
    List <Course> listCourses;

    // bool created = false;
 
    // load a Semester from the given stream (the stream will be opened and closed outside this function, so don't need to do it)
    //void load_data(ifstream&);

    void manageCourses(List <Course*> &pOpenCourse, List<Course*> &pAllCourse);

    // create a Course Registration Session, this feature might need further discussion...
    void createCourseRegistration(List<Course*> &pOpenCourse);
    void addCourseToSemester(List <CourseInfo> &listRegis);
    void viewListCourses();
    void updateCourseInfomation();
    void deleteCourse();

    void load_data(fstream&, List <Course*>& pAllCourse, List <Course*> &pOpenCourse);
    void save_data(fstream&);
};

#include "Semester.cpp"

/*
    

format của 1 khối Semester (dự kiến):
<start_date>
<end_date>
K // số lượng Course đang có hiện tại
<1st Course> // một khối dữ liệu của 1 Course
<2nd Course>
...
<Kth Course>
    
*/