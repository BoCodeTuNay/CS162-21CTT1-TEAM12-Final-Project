#pragma once
#include <iostream>

struct Semester {
 
    Date start_date;
    Date end_date;
	// Linked list of courses …
 
    void coursesList();
    void deleteCourse();
 
};

#include "Semester.cpp"