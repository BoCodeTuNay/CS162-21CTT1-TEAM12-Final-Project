#include "Student.h"

bool cmpCourse(CourseScore &a, CourseScore &b) {
    return (a.pCourse == b.pCourse);
}

void Student::enrolledCourse(List<Course> pOpenCourse) {
    if (pScore.size() > 4) {
        /// Thông báo sinh viên không thể đăng ký thêm
    } else {
        Course* pickCourse = nullptr;
        Score* c = new Score;
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

void Student::removeCourse() {
    CourseScore pick;

    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) {
        /// Hiển thị danh sách sinh viên đã enroll
    }

    pScore.remove(pick, cmpCourse);
}