void viewBooks(const string titles[], const string authors[], int bookCount) {
    for (int i = 0; i < bookCount; ++i) {
        cout << i + 1 << ". Title: " << titles[i] << ", Author: " << authors[i] << endl;
    }
}

