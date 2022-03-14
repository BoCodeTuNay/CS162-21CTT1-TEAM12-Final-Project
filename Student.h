
struct Score {
    double midTerm, finalTerm, processScore;
    double averScore;
};

struct CourseScore {
    Course* courseP;
    Score* scoreP;
};

struct Student {
    char username[20];
    char password[20];

    char name[50];
    int id;
    char email[100];

    int courseNum = 0;
    CourseScore studentCS[5];

    void enrolledCourse() {
        if (courseNum > 4) {
            ///Thong bao k the dky them
            return;
        }
        
    }

    void viewEnrolledCourses() {

    }

    void removeCourse() {

    }
}