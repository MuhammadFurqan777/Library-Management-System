Library Management System

Report on Library Management System
Developers:
Muhammad Furqan Salman,
Muhammad Ayyan,
Saad Ali.

Overview
The Library Management System is a C++ program designed to manage books in a library, featuring functionalities such as adding, viewing, and deleting books. It is secured by a login system that assigns users roles as either an "admin" or "student."
Key features include:
Admin-only functionalities for adding and deleting books.
Persistent data storage using files.
A user-friendly menu-driven interface.

Code Analysis
Key Functionalities
Login System:


The login system uses a std::map to store credentials.
Two roles are supported:
Admin: Full access to add, view, and delete books.
Student: Limited access to view books only.
Predefined credentials:
Admin: admin / admin123
Student: student / student123
Book Management:


Books are stored in two parallel arrays: titles[] and authors[].
Data persistence is achieved using file input/output (books.txt).

Menu Options:


Add Book: Admins can add books by entering the title and author.
View Books: Displays all available books with their indices.
Delete Book: Admins can delete a book by specifying its index.
Exit: Terminates the program.
Error Handling:


Includes checks for invalid inputs, empty fields, and file I/O errors.
Prevents buffer overflows and out-of-range operations.


Improvements and Suggestions
Password Hashing:


Currently, passwords are stored in plaintext. Using a hashing algorithm (e.g., MD5, SHA256) would enhance security.
Dynamic Storage:


Replace fixed-size arrays (titles[], authors[]) with dynamic data structures like std::vector to allow unlimited book entries.
Enhanced Search:


Implement a search feature to allow users to find books by title or author.
Database Integration:


Transition from file-based storage to a database (e.g., SQLite or MySQL) for better scalability and reliability.
Multi-User Login:


Add functionality for creating and managing multiple user accounts with unique credentials.





How to Use
Compile and run the program.


Log in using the following credentials:


Admin: username: admin, password: admin123
Student: username: student, password: student123
After logging in:


Admin can add, view, or delete books.
Students can only view books.
Exit the program by selecting option 4 in the menu.



Conclusion
The Library Management System is a robust and modular solution for small-scale libraries. With its role-based access control, secure data handling, and extensible architecture, it lays the foundation for further enhancements like database integration and advanced search functionalities.


