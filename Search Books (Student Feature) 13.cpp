void searchBook(const string titles[], const string authors[], int bookCount, const string &searchTitle) {
    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (titles[i].find(searchTitle) != string::npos) {
            cout << i + 1 << ". Title: " << titles[i] << ", Author: " << authors[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with the title \"" << searchTitle << "\".\n";
    }
}

