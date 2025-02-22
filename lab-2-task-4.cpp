#include <iostream>
#include <string>

using namespace std;

const int NUM_SUBJECTS = 5;

struct Student {
    string name;
    int rollNumber;
    int marks[NUM_SUBJECTS];
    double average;
    char grade;
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

        cout << "Enter marks for 5 subjects:" << endl;
        
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            cin >> students[i].marks[j];
        }

        int totalMarks = 0;
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            totalMarks += students[i].marks[j];
        }
        students[i].average = static_cast<double>(totalMarks) / NUM_SUBJECTS;


        if (students[i].average >= 90) {
            students[i].grade = 'A';
        } 
        else if (students[i].average >= 80) {
            students[i].grade = 'B';
        } 
        else if (students[i].average >= 70) {
            students[i].grade = 'C';
        } 
        else if (students[i].average >= 60) {
            students[i].grade = 'D';
        } 
        else {
            students[i].grade = 'F';
        }
    }

    cout << "\nStudent Results:" << endl;
    
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Average Marks: " << students[i].average << endl;
        cout << "Grade: " << students[i].grade << endl;
        cout << "--------------------" << endl;
    }

    delete[] students;

    return 0;
}