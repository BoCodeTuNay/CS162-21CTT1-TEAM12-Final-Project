#include "Class.h"

Class::Class(char name[MAXNAME], long long class_id = 0) {
    long long MOD = 1333333337;
    long long base = 2017;
    for (int i = 0; i < strlen(name); ++i) {
        class_id = ((class_id * base % MOD) + name[i]) % MOD;
    }
}

void Class::inputClass()
{
    cout << "Enter class name: ";
    cin.get(name, MAXNAME+1, '\n');

    cout << "Enter class id: ";
    fflush(stdin);
    cin.get(ID, MAXSTR, '\n');
}

List<Profile> Class::addStudent() {
    Profile tmp;
    cout << "Please enter your Student ID: ";
    cin >> tmp.ID;
    cout << "Please enter your first name: ";
    cin >> tmp.firstName;
    cout << "Please enter your last name: ";
    getline(cin, tmp.LastName);
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