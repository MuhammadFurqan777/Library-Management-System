void addBook(string titles[], string authors[], int &bookCount, const string &title, const string &author) {
    if (bookCount < MAX_BOOKS) {
        titles[bookCount] = title;
        authors[bookCount] = author;
        bookCount++;
    }
}

