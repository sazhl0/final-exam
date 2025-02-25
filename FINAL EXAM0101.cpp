#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Grade: ";
    cin >> s.grade;
    students.push_back(s);
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }
    cout << "\nID\tName\tGrade\n";
    for (const auto &s : students) {
        cout << s.id << "\t" << s.name << "\t" << fixed << setprecision(2) << s.grade << "\n";
    }
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    for (const auto &s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << " - Grade: " << s.grade << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\nStudent Grade Management System\n";
        cout << "1. Add Student\n2. View Students\n3. Search Student\n4. Delete Student\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
    