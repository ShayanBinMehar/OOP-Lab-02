#include <iostream>
#include <string>

using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    bool isAvailable;
};

void addBook(Book* &books, int& numBooks) {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.bookID;

    cout << "Enter Book Title: ";
    cin >> newBook.title;

    cout << "Enter Author Name: ";
    cin >> newBook.author;

    newBook.isAvailable = true;

    Book* temp = new Book[numBooks + 1];
    for (int i = 0; i < numBooks; ++i) {
        temp[i] = books[i];
    }
    temp[numBooks] = newBook;

    delete[] books;

    books = temp;
    numBooks++;
}

void removeBook(Book* &books, int& numBooks, int bookID) {
    int index = -1;
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].bookID == bookID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < numBooks - 1; ++i) {
            books[i] = books[i + 1];
        }

        Book* temp = new Book[numBooks - 1];
        for (int i = 0; i < numBooks - 1; ++i) {
            temp[i] = books[i];
        }

        delete[] books;

        books = temp;
        numBooks--;

        cout << "Book with ID " << bookID << " removed successfully." << endl;
    } else {
        cout << "Book with ID " << bookID << " not found." << endl;
    }
}

void searchBook(Book* books, int numBooks, int bookID) {
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].bookID == bookID) {
            cout << "Book Found:" << endl;
            cout << "Book ID: " << books[i].bookID << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Availability: " << (books[i].isAvailable ? "Available" : "Not Available") << endl;
            return;
        }
    }
    cout << "Book with ID " << bookID << " not found." << endl;
}

void displayAvailableBooks(Book* books, int numBooks) {
    cout << "\nAvailable Books:" << endl;
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].isAvailable) {
            cout << "Book ID: " << books[i].bookID << ", Title: " << books[i].title << ", Author: " << books[i].author << endl;
        }
    }
}

int main() {
    int numBooks = 0;
    Book* books = nullptr;

    int choice;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Display Available Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, numBooks);
                break;
            case 2: {
                int bookID;
                cout << "Enter Book ID to remove: ";
                cin >> bookID;
                removeBook(books, numBooks, bookID);
                break;
            }
            case 3: {
                int bookID;
                cout << "Enter Book ID to search: ";
                cin >> bookID;
                searchBook(books, numBooks, bookID);
                break;
            }
            case 4:
                displayAvailableBooks(books, numBooks);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    if (books != nullptr) {
        delete[] books;
    }

    return 0;
}