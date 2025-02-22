#include <iostream>


using namespace std;

struct Employee {
    int employeeID;
    string name;
    string department;
    double salary;
};

int main() {
    int numEmployees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;


    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        cout << endl;
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        
        cout << "Employee ID: ";
        cin >> employees[i].employeeID;
        
        cout << "Name: ";
        cin >> employees[i].name;
        
        cout << "Department: ";
        cin >> employees[i].department;
        
        cout << "Salary: ";
        cin >> employees[i].salary;
    }

    cout << "\nEmployee Details:" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Employee ID: " << employees[i].employeeID << endl;
        cout << "Name: " << employees[i].name << endl;
        cout << "Department: " << employees[i].department << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << "--------------------" << endl;
    }


    int searchID;
    cout << "\nEnter employee ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        
        if (employees[i].employeeID == searchID) {
            cout << "\nEmployee Found:" << endl;
            cout << "Employee ID: " << employees[i].employeeID << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Department: " << employees[i].department << endl;
            cout << "Salary: " << employees[i].salary << endl;
            found = true;
            break;
        }
    }

    if (found == false) {
        cout << endl;
        cout << "Employee not found!" << endl;
    }

    delete[] employees;

    return 0;
}