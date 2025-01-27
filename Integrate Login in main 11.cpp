int main() {
    string filename = "books.txt";
    string role;

    if (!login(role)) {
        cout << "Login failed. Exiting program.\n";
        return 0;
    }

    loadBooks(titles, authors, bookCount, filename);
    cout << "Welcome, " << role << "!" << endl;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 1 && role == "admin") { // Admin-only
            string title, author;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            addBook(titles, authors, bookCount, title, author);
            saveBooks(titles, authors, bookCount, filename);
        } else if (choice == 2) {
            viewBooks(titles, authors, bookCount);
        } else if (choice == 3 && role == "admin") { // Admin-only
            int index;
            cout << "Enter the index of the book to delete: ";
            cin >> index;
            deleteBook(titles, authors, bookCount, index);
            saveBooks(titles, authors, bookCount, filename);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice or access denied.\n";
        }
    }

    return 0;
}

