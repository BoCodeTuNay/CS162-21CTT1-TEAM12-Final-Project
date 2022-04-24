#include "Staff.h"

void Staff::staffMenu()
{
    // this function cannot return true/false to go back because before it is the login screen
    clrscr();
    std::cout << "WELCOME TO THE SYSTEM, " << acc.name << endl << endl;
    std::cout << "0. Manage schoolyears.\n"
            "1. Manage classes.\n"
            "2. View profile.\n"
            "3. Log out.\n\n";
    std::cout << "Your choice: ";
    int t{choose(0, 3)};
    if (t == 0) {
        manageSchoolyears();
        staffMenu();
    }
    else if (t == 1) {
        manageClasses();
        staffMenu();
    }
    else if (t == 2) {
        viewProfile();
        staffMenu();
    }
    else {
        // go back to loginScreen()
    }
}

void Staff::viewProfile()
{
    clrscr();
    std::cout << "WELCOME TO YOUR PERSONAL PAGE.\n\n";

    std::cout << "Name: " << acc.name << endl;
    std::cout << "Email: " << acc.email << endl;
    std::cout << "Social ID: " << acc.socialID << endl;
    std::cout << "ID: " << acc.ID << endl;
    std::cout << std::endl;

    std::cout << "0. Change password\n";
    std::cout << "1. Go back\n\n";
    std::cout << "Your choice: ";
    int t{choose(0, 1)};
    if (t == 0) {
        changePassword();
        viewProfile();
    }
    else {
        // lets go back
    }
}

void Staff::changePassword()
{
    clrscr();
    std::cout << "CHANGE PASSWORD\n";
    std::cout << "Press Enter to go back.\n\n";
    
    bool cont{false};
    char cur_pass[MAXSTR+1];
    do {
        std::cout << "Enter your current password: ";
        fflush(stdin);
        std::cin.get(cur_pass, MAXSTR+1, '\n');
        if (std::cin.fail()) { // nothing was inputted
            std::cin.clear();
            fflush(stdin);
            return;
        }
        else if (std::cin.get() != '\n' || !checkAlphaDigit(cur_pass)) {
            std::cout << "Invalid password. Please try again.\n";
            cont = true;
        }
        else if (strcmp(cur_pass, acc.password)) {
            std::cout << "The password is incorrect. Please try again.\n";
            cont = true;
        }
        else cont = false;
    } while (cont);

    cont = false;
    char new_pass[MAXSTR+1];
    do {
        std::cout << "Enter your new password: ";
        fflush(stdin);
        std::cin.get(new_pass, MAXSTR+1, '\n');
        if (std::cin.fail() || std::cin.get() != '\n' || !checkAlphaDigit(new_pass)) {
            std::cin.clear();
            fflush(stdin);
            std::cout << "Invalid password. Please try again.\n";
            cont = true;
        }
        else cont = false;
    } while (cont);
    strcpy(acc.password, new_pass);
}

void Staff::manageSchoolyears()
{
    // viewAllSchoolYears();
    // chooseSchoolYears();
    // if (choose == createSchoolYear)
    // {
    //     createSchoolYear(listSchoolyears);
    // }
    // else (choose == viewSchoolYearX)
    // {
    //     manageSemesters(schoolYearX);
    // }
    clrscr();
    std::cout << "MANAGE THE AVAILABLE SCHOOLYEARS\n\n";
    int N{0}; // number of commands in this screen
    for (Node<Schoolyear>* cur = listSchoolyears.begin(); cur; cur = cur->pNext) {
        std::cout << N++ << ". View schoolyear " << cur->data.ID << endl;
    }
    std::cout << N++ << ". Create a new schoolyear\n";
    std::cout << N++ << ". Go back\n";
    std::cout << std::endl;

    std::cout << "Your choice: ";
    int t{choose(0, N - 1)};
    if (t < N - 2) {
        listSchoolyears.get(t).manageSemesters();
        manageSchoolyears();
    }
    else if (t == N - 2) {
        createSchoolyear();
        manageSchoolyears();
    }
    else if (t == N - 1) {
        // let's go back
    }
    else assert(false); // just to make sure this case cannot happen
}

// 1. Create a school year
void Staff::createSchoolyear()
{
    clrscr();
    std::cout << "PLEASE ENTER THE SCHOOLYEAR. PRESS ENTER TO GO BACK.\n\n";

    auto validSchoolyear = [](char* yearID) -> bool {
        if (strlen(yearID) != 9) return false;
        if (yearID[4] != '-') return false;
        char* fi = yearID; fi[4] = 0;
        if (!checkDigit(fi)) return false;
        char* se = (yearID + 5);
        if (!checkDigit(se)) return false;
        if (atoi(fi) + 1 != atoi(se)) return false;
        return true;
    };
    auto cmp = [](const Schoolyear& y1, const Schoolyear& y2) -> bool {
        return strcmp(y1.ID, y2.ID) == 0;
    };

    Schoolyear newSchoolYear;
    bool cont{false};
    do {
        std::cout << "Enter the schoolyear (e.g. 2021-2022): ";
        // check for bad input
        fflush(stdin);
        std::cin.get(newSchoolYear.ID, YEARLENGTH+1, '\n');
        if (std::cin.fail()) { // nothing was inputted, so go back
            std::cin.clear();
            fflush(stdin);
            return;
        }
        else if (std::cin.get() != '\n' || !validSchoolyear(newSchoolYear.ID)) {
            std::cout << "The schoolyear format is invalid. Please try again.\n";
            cont = true;
        }
        else if (listSchoolyears.indexOf(newSchoolYear, cmp) != -1) {
            std::cout << "This schoolyear already exists. Please try again.\n";
            cont = true;
        }
        else {
            cont = false;
            newSchoolYear.index = listSchoolyears.size();
            listSchoolyears.insert(newSchoolYear);
            std::cout << "The schoolyear is added successfully.\n";
            // wait a couple of secs
        }
    } while (cont);
    
}

// 2. Create several classes for 1st year students
void createClass(){
    clrscr();
    auto validClass = [](char* classname) -> bool {
        char* ch= classname;
        for (int i=2; i<strlen(classname)-2; i++){
            if (ch[i]<65 || ch[i]>90){
                return false;
            }
            ch[i]='0';
        }
        if (!checkDigit(ch)) return false;
        return true;
    };
    Class newClass;
    bool cont{false};
    do {
        std::cout << "Enter the class (e.g. 21APCS01): ";
        // check for bad input
        fflush(stdin);
        std::cin.get(newClass.name, MAXNAME+1, '\n');
        if (std::cin.fail()) { // nothing was inputted, so go back
            std::cin.clear();
            fflush(stdin);
            break;
        }
        else if (std::cin.get() != '\n' || !validClass(newClass.name)) {
            std::cout << "The class format is invalid. Please try again.\n";
            cont = true;
        }
    } while (cont);
    newClass.inputClass();
    listClasses.insert(newClass);
}

// 3. Add new 1st year students to 1st-year classes
void addStudentToClasses(Class &class){
    // do add student to class
    class.addStudent();
}

// 4. Add students by CSV file
void importStudentFromCSVFile(Class &class)
{
    class.importStudentFile();
}

// At the beginning of a semester:

// 6. Create a semester: 1, 2, or 3, school year, start date, end date
void createSemester(Schoolyear &schoolyear){
    schoolyear.createSemester();
    // char scyear[YEARLENGTH+1];
    // do{
    //     if (listSchoolyears.size() == 0){
    //         cout << "You don't have any school year yet.\n";
    //         return;
    //     }
    //     cout << "What school year of this semester (example: 2021-2022)?\n";
    //     cin>>scyear;
    //     for (Node<Schoolyear>* schoolyear = listSchoolyears.begin(); schoolyear != nullptr; schoolyear = schoolyear->pNext){
    //         if (schoolyear->data.ID==scyear){
    //             schoolyear->data.createSemester();
    //             return;
    //         }
    //     }
    //     cout << "Do not have this school year or your school year invalid. Please try again.\n";
    // } while (strlen(scyear) != 9 || scyear[4] != '-');
}

// 7, 8. Add a course to this semester
// input school year and semester, add course to semester in school year
// semester.cpp

// 9. View the list of courses
// semester.cpp

// 10. Update course information
// semester.cpp

bool cmp_course(const Course& c1, const Course& c2)
{
    return (strcmp(c1.info.ID, c2.info.ID));
}
// Delete a course by ID
void deleteCourse(List <Schoolyear> &listSchoolyears){
    if (listSchoolyears.size() == 0){
        cout << "You don't have any school year yet.\n";
        return;
    }
    string courseID;
    cout << "What course ID do you want to delete?\n";
    cin>>courseID;
    Schoolyear schoolYear=listSchoolyears.get(getCurrentYearIndex());
    for (Node<Course>* currentCourse = schoolYear.yearSemesters[schoolYear.currentSemester - 1].listCourses.begin(); currentCourse != nullptr; currentCourse = currentCourse->pNext){
        if (currentCourse->data.ID == courseID){
            schoolYear.yearSemesters[schoolYear.currentSemester-1].listCourses.remove(currentCourse->data,cmp_course);
            return;
        }
    }
    cout << "Do not have this course ID.\n";
}

// At the end of a semester, an academic staff member can:

// Export a list of students in a course to a CSV file
void exportListStudentsToCSVFile();

// Import the scoreboard of a course
void importScoreboard();

// View the scoreboard of a course
void viewScoreboardOfCourse();

// Update student result
void updateStudentResult();

// View the scoreboard of a class
void viewScoreboardOfClass();
