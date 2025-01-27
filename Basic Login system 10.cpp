bool login(string &role) {
    string username, password;
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
    } else {
        cout << "Invalid username or password.\n";
        return false;
    }
}

