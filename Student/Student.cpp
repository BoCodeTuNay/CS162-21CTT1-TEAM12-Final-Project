#pragma once
#include "Student.h"
#include <vector>

bool cmp_CourseScore(const CourseScore &a, const CourseScore &b) {
    return a.pCourse == b.pCourse;
}

int Student::CurCourses() {
    int cnt = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext)
        cnt += ifDate(getCurrentDate(), ((p->data).pCourse)->start_date, ((p->data).pCourse)->end_date);
    return cnt;
}

///them courseInfo
List<CourseInfo> Student::enrolledCourse(List<Course> pOpenCourse) {
    List<CourseInfo> res;
    
    if (CurCourses() > 4) {
        cout << "You have registered 5 courses!";
        return res;
    }

    while (CurCourses() < 5) {
        clrscr();
        vector<Course*> vCourse;
        
        int reg_Num, Num = 0;
        for (Node<Course>* p = pOpenCourse.begin(); p; p = p->pNext) {
            bool check = true;
            for (int i = 1; i < 7; ++i) 
                if ((p->data).info.day[i] > 0 && !fClass[i][(p->data).info.day[i]])
                    check = false;
            if ((p->data).Student.size() >= (p->data).info.maxStudents) check = false;

            if (!check) continue;
            vCourse.push_back(&(p->data));
            ++Num;
            cout << Num << ". " << (p->data).info.name << '\n'; 
        }

        cout << "Please enter the number of course you want to regis: ";
        cin >> reg_Num;

        Course* pickCourse = vCourse[reg_Num - 1];

        for (int i = 1; i < 7; ++i)
            if ((*pickCourse).info.day[i] > 0)
                fClass[i][(*pickCourse).info.day[i]] = true;
        
        CourseScore* pickCS = new CourseScore(&(pickCourse->info), NULL);

        // pickCS.pCourse = &(pickCourse->info);
        // pickCS.pScore = NULL;

        CoursesList.insert(*pickCS);
        res.insert((*pickCourse).info);
    }
}

void Student::viewEnrolledCourses() {
    int Num = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        ++Num;
        cout << Num << ". " << ((p->data).pCourse->name) << '\n';
    }
}

void Student::removeCourse(char id[MAXID+1]) {
    CourseScore pick;

    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        if (strcmp((p->data).pCourse->ID, id)) {
            pick = p->data;
            break;
        }
    }

    CoursesList.remove(pick, cmp_CourseScore);
}

void Student::init_StudentInfo() {
    class_id = 0;
    long long MOD = 1333333337;
    long long base = 2017;
    for (int i = 0; i < strlen(class_name); ++i) {
        class_id = ((class_id * base % MOD) + class_name[i]) % MOD;
    }
    memset(fClass, false, sizeof fClass);
}

void Student::listOfCourses() {
    cout << "This semester you study courses:\n";
    int Num = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) 
        if (ifDate(getCurrentDate(), ((p->data).pCourse)->start_date, ((p->data).pCourse)->end_date)) {
            ++Num;
            cout << Num << ". " << ((p->data).pCourse->name) << '\n';
        }
}