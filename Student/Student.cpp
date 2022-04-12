#pragma once
#include "Student.h"

bool cmp_Course(const CourseScore &a, const CourseScore &b) {
    return (a.pCourse.id == b.pCourse.id);
}

void Student::enrolledCourse(List<Course> pOpenCourse) {
    if (pScore.size() > 4) {
        /// Thông báo sinh viên không thể đăng ký thêm
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

void Student::removeCourse(string id) {
    CourseScore pick;

    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) {
        if (p -> data.pCourse.id == id) {
            pick = p->data;
            break;
        }
    }

    pScore.remove(pick, cmp_Course);
}