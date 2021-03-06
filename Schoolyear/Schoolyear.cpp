#include "Schoolyear.h"
#include <cassert>

void Schoolyear::createSemester() {
    clrscr();
    if (listSemesters.size() > 3) {
        std::cout << "You can only create at most 3 semesters." << std::endl;
        return;
    }

    Semester cur;
    cur.index = listSemesters.size();
    std::cout << "Creating semester " << cur.index + 1 << " ...\n";
    
    // std::cerr << __LINE__ << std::endl;
    std::cout << "Enter start date (yyyy/mm/dd):\n";
    cur.start_date.enter_date();

    std::cout << "Enter end date (yyyy/mm/dd):\n";
    cur.end_date.enter_date();
    listSemesters.insert(cur);
}

void Schoolyear::save_data(fstream& fout)
{
    // ID (2021-2022)
    // index (0, 1, 2, ...)
    // size of listSemesters
    // semester 0
    // semester 1
    // ...
    if (!fout.is_open()) return;
    fout << ID << endl << index << endl;
    fout << listSemesters.size() << endl;
    // cerr << listSemesters.begin()->data.index << endl;
    // system("pause");
    for (Node<Semester>* cur = listSemesters.begin(); cur; cur = cur->pNext)
        cur->data.save_data(fout);
}

void Schoolyear::load_data(fstream& fin, List <Course*>& pAllCourse, List <Course*>& pOpenCourse)
{
    if (!fin.is_open()) return;
    int N;
    fin >> ID >> index >> N;
    for (int i = 0; i < N; ++i) {
        Semester cur;
        listSemesters.insert(cur);
        listSemesters.end()->data.load_data(fin, pAllCourse, pOpenCourse);
    }
    // std::cerr << "Done loading data, size of listSemesters = " << listSemesters.size() << std::endl;
}

void Schoolyear::manageSemesters(List <Course*>& pOpenCourse, List <Course*>& pAllCourse)
{
    clrscr();
    std::cout << "MANAGE THE AVAILABLE SEMESTERS.\n\n";
    int N{0};
    for (Node<Semester>* cur = listSemesters.begin(); cur; cur = cur->pNext) {
        // std::cerr << __LINE__ << std::endl;
        std::cout << N++ << ". View semester " << N << endl;
    }
    // std::cerr << __LINE__ << std::endl;
    std::cout << N++ << ". Create a new semester\n";
    // std::cerr << __LINE__ << std::endl;
    std::cout << N++ << ". Go back\n";
    int t{choose(0, N - 1)};
    // std::cerr << __LINE__ << std::endl;
    if (t < N - 2) {
        listSemesters.get(t).manageCourses(pOpenCourse, pAllCourse);
        manageSemesters(pOpenCourse, pAllCourse);
    }
    else if (t == N - 2) {
        createSemester();
        manageSemesters(pOpenCourse, pAllCourse);
    }
    else if (t == N - 1) {
        // lets go back
    }
    else assert(false); // just to make sure this case cannot happen
}