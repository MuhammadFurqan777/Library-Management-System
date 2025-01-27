void saveBooks(const string titles[], const string authors[], int bookCount, const string &filename) {
    ofstream file(filename.c_str());
    for (int i = 0; i < bookCount; ++i) {
        file << titles[i] << endl;
        file << authors[i] << endl;
    }
    file.close();
}

