#pragma once
#include <iostream>
#include "..\Course\Course.h"

struct Semester {
    int ID; // 1, 2, or 3
    Date start_date;
    Date end_date;
    List<Course> listCourses;
 
    // load a Semester from the given stream (the stream will be opened and closed outside this function, so don't need to do it)
    void load_data(ifstream&);
    // create a Course Registration Session, this feature might need further discussion...
    void createCourseRegistration();
};

#include "Semester.cpp"