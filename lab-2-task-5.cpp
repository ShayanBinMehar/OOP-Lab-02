#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char* str1 = nullptr;
    char* str2 = nullptr;

    cout << "Enter the first string: ";
    char temp1[100];
    cin.getline(temp1, 100); 

    str1 = new char[strlen(temp1) + 1]; 
    strcpy(str1, temp1); 

    cout << "Enter the second string: ";
    char temp2[100]; 
    cin.getline(temp2, 100);

    str2 = new char[strlen(temp2) + 1];
    strcpy(str2, temp2);

    char* concatStr = new char[strlen(str1) + strlen(str2) + 1]; 
    strcpy(concatStr, str1);
    strcat(concatStr, str2);

    int comparisonResult = strcmp(str1, str2);
    string comparison;
    if (comparisonResult == 0) {
        comparison = "are equal";
    } 
    else if (comparisonResult < 0) {
        comparison = "comes before";
    } 
    else {
        comparison = "comes after";
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    cout << "Concatenated string: " << concatStr << endl;
    cout << "String 1 " << comparison << " String 2" << endl;
    cout << "Length of String 1: " << len1 << endl;
    cout << "Length of String 2: " << len2 << endl;

    delete[] str1;
    delete[] str2;
    delete[] concatStr;

    return 0;
}