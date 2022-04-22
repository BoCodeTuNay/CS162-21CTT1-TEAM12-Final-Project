#pragma once
#include <iostream>
#include "..\Course\Course.h"

struct Semester {
    bool created = false;
    Date start_date;
    Date end_date;
    Date start_registration_date;
    Date end_registration_date;
    static List<Course> listCourses;
 
    // load a Semester from the given stream (the stream will be opened and closed outside this function, so don't need to do it)
    //void load_data(ifstream&);

    // create a Course Registration Session, this feature might need further discussion...
    void createCourseRegistration();
};

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