void deleteBook(string titles[], string authors[], int &bookCount, int index) {
    for (int i = index - 1; i < bookCount - 1; ++i) {
        titles[i] = titles[i + 1];
        authors[i] = authors[i + 1];
    }
    bookCount--;
}

