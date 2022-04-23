#include "Semester.h"

void Semester::createCourseRegistration(List <CourseInfo>& listCourseInfo, int schoolyearID) {
    CourseInfo courseInfo;
    int check;
    do {
        courseInfo.input();
        cout << "Are you sure about all of the information of the course you want to create? (0 for No and 1 for Yes): ";
        cin >> check;
    } while (check == 0);

    listCourseInfo.insert(courseInfo);
    courseInfo.semesterID = ID;
    courseInfo.schoolyearID = schoolyearID;
    Course course;
    course.info = courseInfo;
    
    listCourses.insert(course);
}
