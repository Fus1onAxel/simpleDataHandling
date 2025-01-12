#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Define a Data Type to Represent Entities (e.g., Student)
struct Student 
{
    int id;
    string name;
    int yearOfEnrollment;

    // Constructor for convenience
    Student(int id, string name, int yearOfEnrollment)
        : id(id), name(name), yearOfEnrollment(yearOfEnrollment) {}
};

// Utility to display a student
void displayStudent(const Student &s) 
{
    cout << "ID: " << s.id << ", Name: " << s.name << ", Year: " << s.yearOfEnrollment << endl;
}

// Custom Data Structure for Managing Students
class StudentDatabase 
{
private:
    vector<Student> students;

    // Helper function for binary search
    int binarySearch(int id) 
    {
        int left = 0, right = students.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (students[mid].id == id)
                return mid;
            if (students[mid].id < id)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1; // Not found
    }

public:
    // Add a new student
    void addStudent(const Student &student) 
    {
        students.push_back(student);
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.id < b.id; });
    }

    // Retrieve a student by ID
    void retrieveStudent(int id) 
    {
        int index = binarySearch(id);
        if (index != -1)
            displayStudent(students[index]);
        else
            cout << "Student not found!" << endl;
    }

    // Update a student by ID
    void updateStudent(int id, const string &newName, int newYear) 
    {
        int index = binarySearch(id);
        if (index != -1) 
        {
            students[index].name = newName;
            students[index].yearOfEnrollment = newYear;
            cout << "Student updated successfully." << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    // Remove a student by ID
    void removeStudent(int id) 
    {
        int index = binarySearch(id);
        if (index != -1) 
        {
            students.erase(students.begin() + index);
            cout << "Student removed successfully." << endl;
        } else 
        {
            cout << "Student not found!" << endl;
        }
    }

    // Display all students
    void displayAll() 
    {
        for (const auto &student : students)
            displayStudent(student);
    }

    // Merge Sort implementation for sorting by year of enrollment
    void mergeSortByYear() 
    {
        mergeSort(0, students.size() - 1);
    }

    // Sort students by ID
    void sortById() 
    {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.id < b.id; });
    }

private:
    void merge(int left, int mid, int right) 
    {
        vector<Student> leftArray(students.begin() + left, students.begin() + mid + 1);
        vector<Student> rightArray(students.begin() + mid + 1, students.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < leftArray.size() && j < rightArray.size()) 
        {
            if (leftArray[i].yearOfEnrollment <= rightArray[j].yearOfEnrollment)
                students[k++] = leftArray[i++];
            else
                students[k++] = rightArray[j++];
        }

        while (i < leftArray.size())
            students[k++] = leftArray[i++];

        while (j < rightArray.size())
            students[k++] = rightArray[j++];
    }

    void mergeSort(int left, int right) 
    {
        if (left < right) 
        {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }
};

// Console Menu for Interaction
int main() 
{
    StudentDatabase db;

    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Retrieve Student\n";
        cout << "3. Update Student\n";
        cout << "4. Remove Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Sort Students by Year\n";
        cout << "7. Sort Students by ID\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;


        if (choice == 8)
            break;

        switch (choice) 
        {
        case 1: 
        {
            int id, year;
            string name;
            cout << "Enter ID:" << endl;
            cin >> id;
            cout << "Enter Name:" << endl; 
            cin >> name;
            cout << "Year of Enrollment:" << endl;
            cin >> year;
            db.addStudent(Student(id, name, year));
            break;
        }
        case 2: 
        {
            db.sortById();
            int id;
            cout << "Enter ID to retrieve: ";
            cin >> id;
            db.retrieveStudent(id);
            break;
        }
        case 3: 
        {
            db.sortById();
            int id, year;
            string name;
            cout << "Enter ID to update: " << endl;
            cin >> id;
            cout << "Enter new Name: " << endl;
            cin >> name;
            cout << "Enter new Year of Enrollment: " << endl;
            cin >> year;
            db.updateStudent(id, name, year);
            break;
        }
        case 4: 
        {
            db.sortById();
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            db.removeStudent(id);
            break;
        }
        case 5:
            db.displayAll();
            break;
        case 6:
            db.mergeSortByYear();
            cout << "Students sorted by year of enrollment." << endl;
            break;
        case 7:
            db.sortById();
            cout << "Students sorted by ID." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}