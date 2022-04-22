#pragma once
#include <iostream>
#include "..\Constants\Constants.h"
#include "..\Semester\Semester.h"
#include "..\Class\Class.h"

struct Schoolyear {
    char ID[YEARLENGTH+1]; 
    List<Semester> listSem;
    // load a Schoolyear from the given stream (the stream will be opened and closed outside this function, so don't need to do it)
    // void load_data(ifstream&);


    // ask the user to fill in the Semester's info (remember to flush the input stream first by fflush(stdin)) and then 
    // add it to this schoolyear by inserting it into listSemester
    void createSemester();
};


/*
format của database Schoolyear (dự kiến):

N // số lượng schoolyear đang có hiện tại
<1st Schoolyear> // một khối dữ liệu của 1 schoolyear
<2nd Schoolyear>
...
<Nth Schoolyear>

format của 1 khối Schoolyear (dự kiến):

<ID> // e.g. 2020-2021
M // số lượng Semester đang có hiện tại (phải là 1, 2, hoặc 3)
<1st Semester> // một khối dữ liệu của 1 Semester
<2nd Semester>
...
<Mth Semester>

format của 1 khối Course (dự kiến):
// cái này chắc cần bàn thêm với mấy ông code struct Course :v

<ID>
<Name>
<lecture>
<numCredits>
<maxStudents>

// each of session (MON / TUE / WED / THU / FRI / SAT)
// S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)

<day1>
<session1>

<day2>
<session2>
*/