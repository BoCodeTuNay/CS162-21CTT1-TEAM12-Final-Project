#include "Staff.h"

void Staff::staffMenu(List<Student>& listStudents, List <Course*>& pOpenCourse, List <Course*>& pAllCourse)
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
        manageSchoolyears(pOpenCourse, pAllCourse);
        staffMenu(listStudents, pOpenCourse, pAllCourse);
    }
    else if (t == 1) {
        manageClasses(listStudents); // chua co
        staffMenu(listStudents, pOpenCourse, pAllCourse);
    }
    else if (t == 2) {
        viewProfile();
        staffMenu(listStudents, pOpenCourse, pAllCourse);
    }
    else {
        // go back to loginScreen()
    }
}

void Staff::save_courses(fstream& fout)
{
    if (!fout.is_open()) return;
    fout << listSchoolyears.size() << endl;
    for (Node<Schoolyear>* cur = listSchoolyears.begin(); cur; cur = cur->pNext)
        cur->data.save_data(fout);
    fout << endl;
}

void Staff::load_courses(fstream& fin, List <Course*>& pAllCourse)
{
    if (!fin.is_open()) return;
    int N;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        Schoolyear cur;
        listSchoolyears.insert(cur);
        listSchoolyears.end()->data.load_data(fin, pAllCourse);
    }
}

void Staff::save_classes(fstream& fout)
{
    if (!fout.is_open()) return;
    fout << listClasses.size() << endl;
    for (Node<Class>* cur = listClasses.begin(); cur; cur = cur->pNext)
        cur->data.save_data(fout);
}

void Staff::load_classes(fstream& fin, List<Student>& listStudents)
{
    if (!fin.is_open()) return;
    int N;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        Class cur;
        listClasses.insert(cur);
        listClasses.end()->data.load_data(fin, listStudents);
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

void Staff::manageSchoolyears(List <Course*>& pOpenCourse, List <Course*>& pAllCourse)
{
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
        listSchoolyears.get(t).manageSemesters(pOpenCourse, pAllCourse);
        manageSchoolyears(pOpenCourse, pAllCourse);
    }
    else if (t == N - 2) {
        createSchoolyear();
        manageSchoolyears(pOpenCourse, pAllCourse);
    }
    else if (t == N - 1) {
        // let's go back
    }
    else assert(false); // just to make sure this case cannot happen
}
void Staff::manageClasses(List<Student>& listStudents)
{
    clrscr();
    std::cout << "MANAGE THE AVAILABLE CLASSES\n\n";
    int N{0}; // number of commands in this screen
    for (Node<Class>* cur = listClasses.begin(); cur; cur = cur->pNext) {
        std::cout << N++ << ". View class " << cur->data.ID << endl;
    }
    std::cout << N++ << ". Create a new class\n";
    std::cout << N++ << ". Go back\n";
    std::cout << std::endl;

    std::cout << "Your choice: ";
    int t{choose(0, N - 1)};
    if (t < N - 2) {
        listClasses.get(t).manageStudent(listStudents);
        manageClasses(listStudents);
    }
    else if (t == N - 2) {
        createClasses();
        manageClasses(listStudents);
    }
    else if (t == N - 1) {
        // let's go back
    }
    else assert(false); // just to make sure this case cannot happen
}

void Staff::createSchoolyear()
{
    clrscr();
    std::cout << "PLEASE ENTER THE SCHOOLYEAR. PRESS ENTER TO GO BACK.\n\n";

    auto validSchoolyear = [](char* yearID) -> bool {
        if (strlen(yearID) != 9) return false;
        if (yearID[4] != '-') return false;
        char* fi = yearID; fi[4] = 0;
        if (!checkDigit(fi)) return false;
        fi[4] = '-';
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
            system("pause");
        }
    } while (cont);
    
}

// 2. Create several classes for 1st year students
void Staff::createClasses(){
    clrscr();
    auto validClass = [](const char* classname) -> bool {
        const char* ch= classname;
        for (int i=2; i<strlen(classname)-2; i++){
            if (ch[i]<65 || ch[i]>90){
                return false;
            }
        }
        char a[3];
        a[0]=classname[0];
        a[1]=classname[1];
        a[2] = 0;
        const char* b = (classname+strlen(classname)-2);
        if (!checkDigit(a)||!checkDigit(b)) return false;
        return true;
    };
    auto cmp = [](const Class& c1, const Class& c2) -> bool {
        return strcmp(c1.ID, c2.ID) == 0;
    };
    Class newClass;
    bool cont{false};
    do {
        std::cout << "Enter the class (e.g. 21APCS01): ";
        // check for bad input
        fflush(stdin);
        std::cin.get(newClass.ID, MAXSTR+1, '\n');
        if (std::cin.fail()) { // nothing was inputted, so go back
            std::cin.clear();
            fflush(stdin);
            return;
        }
        else if (std::cin.get() != '\n' || !validClass(newClass.ID)) {
            std::cout << "The class format is invalid. Please try again.\n";
            cont = true;
        }
        else if (listClasses.indexOf(newClass, cmp) != -1) {
            std::cout << "This class already exists. Please try again.\n";
            cont = true;
        }
        else {
            cont = false;
            listClasses.insert(newClass);
            std::cout << "The class is added successfully.\n";
            // wait a couple of secs
        }
    } while (cont);
}