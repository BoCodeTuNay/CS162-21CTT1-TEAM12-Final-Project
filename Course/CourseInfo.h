#pragma once
#include "..\\Student\\Student.h"
#include "..\\Date\\Date.h"
#include "Profile/Profile.h"
#include "Score.h"

struct CourseInfo
{
    char ID[MAXSTR+1]; // mã học phần
    char name[MAXSTR+1]; // tên học phần
    int semesterID;
    int schoolyearID:
};