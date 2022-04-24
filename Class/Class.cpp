#include "Class.h"

void Class::inputClass()
{
    cout << "Enter class name: ";
    cin.get(name, MAXNAME+1, '\n');

    cout << "Enter class id: ";
    fflush(stdin);
    cin.get(ID, MAXSTR, '\n');
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