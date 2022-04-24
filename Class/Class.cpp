#include "Class.h"

void Class::manageStudent()
{
    clrscr();
    std::cout << "MANAGE CLASS " << ID << endl << endl;
    std::cout << "1. View a list of student.\n"
            "2. Add student.\n"
            "3. Import student from CSV file.\n"
            "4. Go back.\n\n";
    std::cout << "Your choice: ";
    int t{choose(1, 4)};
    if (t == 1) {
        viewStudentList();
        manageStudent();
    }
    else if (t == 2) {
        addStudent();
        manageStudent();
    }
    else if (t == 3) {
        importStudentFile();
        manageStudent();
    }
    else if (t == 4) {
        // lets go back
    }
    else assert(false); // just to make sure this case cannot happen
}

void Class::viewStudentList()
{
    clrscr();
    std::cout << "STUDENT LIST " << endl << endl;

    int N{1};
    for (Node <Student*> *i; i; i = i -> pNext)
    {
        std::cout << N++ << ". " << i->data->acc.name << "\n";
    }
    std::cout << "\n";
    std::cout << "Press any key to continue...\n";
    int x;
    std::cin >> x;
}

void Class::inputClass()
{
    cout << "Enter class name: ";
    cin.get(ID, MAXSTR+1, '\n');
}

List<Account> Class::addStudent() {
    Account tmp;
    cout << "Please enter your Student ID: ";
    cin >> tmp.ID;
    cout << "Please enter your name: ";
    getline(cin, tmp.name);
    cout << "Please enter your gender (1: male/ 2: female): ";
    int x;
    cin >> x;
    tmp.gender = (x == 1);
    cout << "Please enter your date of birth (dd/mm/yyyy): ";
    cin >> tmp.DOB.day >> tmp.DOB.month >> tmp.DOB.year;
    cout << "Please enter your social ID: ";
    cin >> tmp.socialID;

    stu_list.insert(tmp);

    // return tmp;
}

List<Profile> Class::importStudentFile() {
    Profile tmp;
    List<Profile> res;
    ifstream fin;
    fin.open("input.csv");
    vector<string> row;
    string line, word, tmp;
    if (fin >> tmp) {
        do {
            row.clear();
            getline(fin, line);
            
            stringstream s(line);

            while (getline(s, word, ', ')) row.push_back(word);

            for (int i = 0; i < row[1].length(); ++i) tmp.ID[i] = row[1][i];
            for (int i = 0; i < row[2].length(); ++i) tmp.firstName[i] = row[2][i];
            for (int i = 0; i < row[3].length(); ++i) tmp.lastName[i] = row[3][i];
            tmp.gender = (stoi(row[4]) == 1);
            tmp.DOB = Date(row[5]);
            for (int i = 0; i < row[6].length(); ++i) tmp.socialID[i] = row[6][i];
            stu_list.insert(tmp);
            res.insert(tmp);            
        } while (!row.empty());
    }
    // return res;
}