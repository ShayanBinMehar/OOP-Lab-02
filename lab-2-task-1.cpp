#include <iostream>

using namespace std;

int main() {

    int userinput, sum = 0, maxValue;
    float avg = 0;
    int* ptr; 
    cout << "Enter the number for dynamic memory allocation" << endl;
    cin >> userinput;

    ptr = new int[userinput];

    for(int x = 0; x < userinput; x++) {

        cout << "Enter " << x+1 << " input : ";
        cin >> ptr[x];
        sum += ptr[x];
    }
    avg = sum / userinput;
    maxValue = ptr[0];
    for(int x = 0; x < userinput; x++) {

        if(ptr[x] > maxValue) {
            maxValue = ptr[x];
        }
    }

    cout << "Sum is equal to = " << sum << endl;
    cout << "Avg is equal to = " << avg << endl;
    cout << "Maximum value is equal to = " << maxValue << endl;

    delete[] ptr;
    return 0;
}