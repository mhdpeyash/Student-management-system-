#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
    int id;
};

void saveToFile(const vector<Student>&students, const string &filename) {
    ofstream file(filename);
    for(const Student &s:students) {
        file<<s.name<<endl;
        file<<s.age<<endl;
        file<<s.gpa<<endl;
        file<<s.id<<endl;
    }
    file.close();
}


void loadFromFile(vector<Student>&students, const string &filename) {
    ifstream file(filename);
    Student s;
    while(getline(file, s.name)) {
        file>>s.id;
        file>>s.age;
        file>>s.gpa;
        file.ignore();
        students.push_back(s);
    }
    file.close();
}


void addStudent(vector<Student>&students) {
    Student s;
    cout << "Enter ID : " << endl;
    cin >> s.id;
    cout << "Enter name : " << endl;
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter age : " << endl;
    cin >> s.age;
    cout << "Enter GPA : " << endl;
    cin >>s.gpa ;

    students.push_back(s);
    cout << "Student added successfully..." << endl<<endl;
};


void displayStudents(const vector<Student>&students) {
    for(const auto &s: students) {
        cout << "Name : " <<s.name<< endl;
        cout << "ID : " <<s.id<< endl;
        cout << "Age : " <<s.age<< endl;
        cout << "GPA : " <<s.gpa<< endl;
    }
    cout << endl;
};


void searchStudent(vector<Student>&students, int id) {
    bool found=false;
    for(const auto& s:students) {
        if(s.id==id) {
            cout << "Student found" << endl;
            cout << "Name : " <<s.name<< endl;
            cout << "ID   : " <<s.id<< endl;
            cout << "GPA  : " <<s.gpa<< endl;
            cout << "Age  : " <<s.age<<endl;

            found=true;
            break;
        }
    }
    if(!found) {
        cout<<"Student Not Found" << endl;
    }
    cout << endl;
}


void deleteStudent(vector<Student>&students, int id) {
    for(auto it=students.begin(); it!=students.end(); ++it) {
        if((*it).id==id) {
            students.erase(it);
            cout << "Student Deleted Successfully." << endl<<endl;
            return;
        }
    }
    cout << "Student Not Found." << endl<<endl;
}


void updateStudent(vector<Student>&students, int id) {
    for(auto &s:students) {
        if(s.id==id) {
            cout << "Enter New Name : " << endl;
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter New age : " << endl;
            cin >> s.age;
            cout << "Enter New GPA : " << endl;
            cin >> s.gpa;

            cout << "Student  Updated Successfully." << endl<<endl;
            return;
        }
        
    }cout << "Student Not Found" << endl<<endl;
}


int main() {

    vector<Student>students;
    vector<Student>loadedStudents;
    loadFromFile(loadedStudents, "students.txt");
    
    int choice, id;
    while(true) {
        cout << "......Student Management System...." << endl;
        cout << "1. Add new student" << endl;
        cout << "2.Display students" << endl;
        cout << "3.Search Student" << endl;
        cout << "4.Delete Student" << endl;
        cout << "5.Update Student" << endl;
        cout << "6.Exit" << endl<<endl;

        cout << "Enter your choice : " << endl;
        cin >> choice;


        switch(choice) {

        case 1:
            addStudent(students);
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            cout << "Enter your ID : " << endl;
            cin >> id;
            searchStudent(students, id);
            break;
        case 4:
            cout << "Enter your ID : " << endl;
            cin >> id;
            deleteStudent(students, id);
            break;
        case 5:
            cout << "Enter ID to update information" << endl;
            cin >> id;
            updateStudent(students, id);
            break;
        case 6:
            saveToFile(students, "students.txt");
            cout << "You exited successfully..." << endl;
            return 0;
        default :
            cout << "Invalid choice. Try again..." <<endl<<endl;
        }
    }

    return 0;
}