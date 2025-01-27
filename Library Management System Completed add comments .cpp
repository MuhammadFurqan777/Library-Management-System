#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

const int MAX_BOOKS = 100; // Maximum number of books allowed in the library

// Function to load books from a file
void loadBooks(string titles[], string authors[], int &bookCount, const string &filename) {
    ifstream file(filename.c_str());

    if (!file) {
        bookCount = 0;
        return;
    }

    bookCount = 0;

    while (bookCount < MAX_BOOKS && getline(file, titles[bookCount]) && getline(file, authors[bookCount])) {
        bookCount++;
    }

    file.close();
}

// Function to save books to a file
void saveBooks(const string titles[], const string authors[], int bookCount, const string &filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cerr << "Error: Unable to save books to file." << endl;
        return;
    }

    for (int i = 0; i < bookCount; ++i) {
        file << titles[i] << endl;
        file << authors[i] << endl;
    }

    file.close();
}

// Function to add a new book to the library
void addBook(string titles[], string authors[], int &bookCount, const string &title, const string &author) {
    if (title.empty() || author.empty()) {
        throw invalid_argument("Title and Author cannot be empty.");
    }

    if (bookCount >= MAX_BOOKS) {
        throw overflow_error("Library is full. Cannot add more books.");
    }

    titles[bookCount] = title;
    authors[bookCount] = author;
    bookCount++;
}

// Function to view all books in the library
void viewBooks(const string titles[], const string authors[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books available in the library." << endl;
        return;
    }

    cout << "\nBooks in the library:" << endl;
    for (int i = 0; i < bookCount; ++i) {
        cout << i + 1 << ". Title: " << titles[i] << ", Author: " << authors[i] << endl;
    }
}

// Function to delete a book from the library
void deleteBook(string titles[], string authors[], int &bookCount, int index) {
    if (index < 1 || index > bookCount) {
        throw out_of_range("Invalid book index.");
    }

    for (int i = index - 1; i < bookCount - 1; ++i) {
        titles[i] = titles[i + 1];
        authors[i] = authors[i + 1];
    }

    bookCount--;
}

// Function to display the menu
void displayMenu() {
    cout << "\n***** Library Management System *****" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. View Books" << endl;
    cout << "3. Delete Book" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to handle login
bool login(string &role) {
    string username, password;

    cout << "***** Library Management System Login *****" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        role = "admin";
        return true;
    } else if (username == "student" && password == "student123") {
        role = "student";
        return true;
    }

    cout << "Invalid username or password." << endl;
    return false;
}

// Main function
int main() {
    string titles[MAX_BOOKS];
    string authors[MAX_BOOKS];
    int bookCount = 0;
    string filename = "books.txt";

    string role;

    if (!login(role)) {
        cout << "Login failed. Exiting program." << endl;
        return 0;
    }

    cout << "Welcome, " << role << "!" << endl;

    loadBooks(titles, authors, bookCount, filename);

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(1000, '\n'); // Ignore trailing characters

        try {
            if (choice == 1) {
                if (role != "admin") {
                    cout << "Access denied. Only administrators can add books." << endl;
                    continue;
                }

                string title, author;
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);

                addBook(titles, authors, bookCount, title, author);
                saveBooks(titles, authors, bookCount, filename);

                cout << "Book '" << title << "' by " << author << " added successfully." << endl;

            } else if (choice == 2) {
                viewBooks(titles, authors, bookCount);

            } else if (choice == 3) {
                if (role != "admin") {
                    cout << "Access denied. Only administrators can delete books." << endl;
                    continue;
                }

                int index;
                cout << "Enter the book index to delete: ";
                cin >> index;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a valid number." << endl;
                    continue;
                }

                deleteBook(titles, authors, bookCount, index);
                saveBooks(titles, authors, bookCount, filename);

                cout << "Book deleted successfully." << endl;

            } else if (choice == 4) {
                cout << "Exiting the system." << endl;
                break;

            } else {
                cout << "Invalid choice. Please try again." << endl;
            }

        } catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << endl;

        } catch (const out_of_range &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}

