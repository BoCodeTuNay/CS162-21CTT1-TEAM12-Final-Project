#pragma once
#include "Student/Student.h"

bool cmp_Course(const CourseScore &a, const CourseScore &b) {
    return strcmp(a.pCourse.ID, b.pCourse.ID);
}

void Student::enrolledCourse(List<Course> pOpenCourse) {
    if (pScore.size() > 4) {
        cout << "You have enrolled 5 courses!.";
        return;
    } else {
        Course pickCourse;
        Score c;
        for (Node<Course>* p = pOpenCourse.begin(); p; p = p -> pNext) {
            /// Hiển thị danh sách cho sinh viên chọn khóa đăng ký thêm.
        }

        CourseScore tmp = {pickCourse, c};
        pScore.insert(tmp);
    }
}

void Student::viewEnrolledCourses() {
    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) {
        /// Hiển thị danh sách sinh viên đã enroll
    }
}

void Student::removeCourse(char id[MAXNAME]) {
    CourseScore pick;

    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) {
        if (strcmp(p -> data.pCourse.ID, id)) {
            pick = p->data;
            break;
        }
    }

    pScore.remove(pick, cmp_Course);
}

void Student::init_classid() {
    class_id = 0;
    long long MOD = 1333333337;
    long long base = 2017;
    for (int i = 0; i < strlen(class_name); ++i) {
        class_id = ((class_id * base % MOD) + class_name[i]) % MOD;
    }
}

void Student::listOfCourses() {
    cout << "This semester you study courses:\n";
    int cnt = 0;
    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) 
        if (ifDate(getThisDate(), (p->data.pCourse.start_date), (p->data.pCourse.end_date))) 
            cout << ++cnt << '.' << (p->data.pCourse.name) << '\n';
}