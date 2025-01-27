int main() {
    string filename = "books.txt";
    loadBooks(titles, authors, bookCount, filename);

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
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
        } else if (choice == 3) {
            int index;
            cout << "Enter the index of the book to delete: ";
            cin >> index;
            deleteBook(titles, authors, bookCount, index);
            saveBooks(titles, authors, bookCount, filename);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}

