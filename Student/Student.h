#include "List.h"
#include "Course.h"

struct Score {
    double mid_term_p;
    double process_p;
    double final_p;
}

struct CourseScore {
    Course *pCourse;
    Score *pScore;
}

struct Student {
    char username[20];
    char password[20];

    char name[50];
    int id;
    char email[100];

    List<CourseScore> pScore;

    void enrolledCourse();
    void viewEnrolledCourses();
    void removeCourse();
}