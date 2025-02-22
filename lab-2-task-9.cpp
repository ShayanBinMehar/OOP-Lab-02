#include <iostream>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    int marks;
};

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        
        cout << "Name: ";
        cin >> students[i].name;
        
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;

        cout << "Marks: ";
        cin >> students[i].marks;
    }

    int highestMarksIndex = 0;
    for (int i = 1; i < numStudents; ++i) {
        
        if (students[i].marks > students[highestMarksIndex].marks) {
            highestMarksIndex = i;
        }
    }

    cout << "\nStudent with the highest marks:" << endl;
    cout << "Name: " << students[highestMarksIndex].name << endl;
    cout << "Roll Number: " << students[highestMarksIndex].rollNumber << endl;
    cout << "Marks: " << students[highestMarksIndex].marks << endl;

    delete[] students;

    return 0;
}