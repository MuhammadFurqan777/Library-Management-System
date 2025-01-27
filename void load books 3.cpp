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

