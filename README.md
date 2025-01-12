# Student Management System

This project is a C++ application that manages a database of students. It supports operations such as adding, retrieving, updating, and removing student records. The system also allows sorting students by ID or year of enrollment using custom implementations of Merge Sort and Binary Search.

## Features

- Add new student records.
- Retrieve student details by ID.
- Update student information.
- Remove student records.
- Display all student records.
- Sort students by ID.
- Sort students by year of enrollment.

## Prerequisites

- A C++ compiler (GCC, Clang, MSVC, etc.) with support for C++11 or later.

## How to Build and Run

1. Clone or download the repository containing this project.

2. Navigate to the folder containing the `main.cpp` file.

3. Compile the code using a C++ compiler:

   ```bash
   g++ -o StudentDatabase main.cpp
   ```

4. Run the executable:

   ```bash
   ./StudentDatabase
   ```

5. Follow the menu options displayed on the console to interact with the program.

## Limitations and Known Issues

- **Input Validation:** The program does not validate all user inputs thoroughly. For example, entering non-integer values where integers are expected may cause errors. (Please do not, even if it causes "fun" problems in the menu. It may causes you to loose everything you built within the application.)
- **Unfinished Features:** Error handling for edge cases (e.g., empty databases, extremely large inputs) may need refinement.

## Future Improvements

- Improve input validation to handle erroneous inputs gracefully.
- Add persistent storage to save and load student data.