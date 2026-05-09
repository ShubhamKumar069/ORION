#include <iostream>
#include <string>

constexpr int MAX_STUDENTS = 5000;
int nextRollNo = 1;

std::string studentNames[MAX_STUDENTS];
float studentMarks[MAX_STUDENTS];
int studentRollNo[MAX_STUDENTS];
int totalStudents = 0;

void addStudent() {
        if(totalStudents >= MAX_STUDENTS) {
            std::cout << "Students Full! Try Again Next Year.\n";
            return;
        }

        std::string name;
        float marks;

        std::cout << "Enter Student Name : ";
        std::cin.ignore(1000, '\n');
        getline(std::cin, name);

        std::cout << "Enter Total Avg Marks Out Of 100 : ";
        std::cin >> marks;

        if(marks < 0 || marks > 100) {
            std::cout << "Invalid Student Marks.\n";
            return;
        }

        studentNames[totalStudents] = name;
        studentMarks[totalStudents] = marks;
        studentRollNo[totalStudents] = nextRollNo;
        nextRollNo++;

        std::cout << "Roll No. of Student : "
                  << studentRollNo[totalStudents]
                  << std::endl;

        totalStudents++;

        std::cout << "\nStudent Added Successfully!\n";

    std::cout << "\n";
    }

void viewStudents() {

    if(totalStudents == 0) {
        std::cout << "No Students Found.\n";
        return;
    }

    for (int i = 0; i<totalStudents; i++) {
        std::cout << "Student Name: " << studentNames[i] << std::endl;
        std::cout << "Student Marks: " << studentMarks[i] << std::endl;
        std::cout << "Student Roll No: " << studentRollNo[i] << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "" << std::endl;
    }

    std::cout << "Total Students: " << totalStudents;

    std::cout << "\n";
}

void searchStudent() {

    if (totalStudents == 0) {
        std::cout << "No Students Found.\n";
        return;
    }

    int rollNo;
    std::cout << "Enter Student Roll No. : ";
    std::cin >> rollNo;
    bool found = false;

    for (int i = 0; i<totalStudents; i++) {
        if (studentRollNo[i] == rollNo) {
            std::cout << "Student Name: " << studentNames[i] << std::endl;
            std::cout << "Student Marks: " << studentMarks[i] << std::endl;
            std::cout << "Student Roll No : " << studentRollNo[i] << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student Not Found." << std::endl;
    }

    std::cout << "\n";

}

void editStudent() {
    if (totalStudents == 0) {
        std::cout << "No Students Found.\n";
        return;
    }

    int rollNo;
    std::cout << "Enter Student Roll No. : ";
    std::cin >> rollNo;
    bool found = false;

    float newMarks;
    std::string newName;

    for (int i = 0; i<totalStudents; i++) {
        if (studentRollNo[i] == rollNo) {
            std::cout << "Enter New Student Name: ";
            std::cin.ignore(1000, '\n');
            getline(std::cin, newName);
            std::cout << "Enter New Student Marks : ";
            std::cin >> newMarks;
            if(newMarks < 0 || newMarks > 100) {
                std::cout << "Invalid Student Marks.\n";
                return;
            }

            studentNames[i] = newName;
            studentMarks[i] = newMarks;

            std::cout << "Student Successfully Updated!";

            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student Not Found." << std::endl;
    }

    std::cout << "\n";
}

void deleteStudent() {
    if (totalStudents == 0) {
        std::cout << "No Students Found.\n";
        return;
    }
    int rollNo;
    std::cout << "Enter Student Roll No. : ";
    std::cin >> rollNo;
    char choice;
    bool found = false;
    for (int i = 0; i<totalStudents; i++) {
        if (studentRollNo[i] == rollNo) {
            found = true;
            std::cout << "Confirm To Delete Student (Y/n) : ";
            std::cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                for (int j = i; j < totalStudents - 1; j++) {
                    studentNames[j] = studentNames[j + 1];
                    studentMarks[j] = studentMarks[j + 1];
                    studentRollNo[j] = studentRollNo[j + 1];
                }

                totalStudents--;
                std::cout << "Student Deleted Successfully!\n";
                break;
            } else if (choice == 'n' || choice == 'N') {
                std::cout << "Deleting Student Rejected\n";
                return;
            } else {
                std::cout << "Enter Valid Choices!\n";
                return;
            }
        }
    }
    if(!found) {
        std::cout << "Student Not Found.\n";
    }
}
void showMenuStudent() {
    // std::cout << "1. Add Student\n2. View All Students\n3. Search Student\n4. Edit Student\n5. Delete Student\n6. Calculate Average Marks\n7. Show Topper\n8. Sort Students\n0. Back\n";
    std::cout << "1. Add Student\n2. View All Students\n3. Search Student\n4. Edit Student\n5. Delete Student\n";
}

void studentManagement() {
    int studentOption;

    do {
        std::cout << "===== STUDENT MANAGEMENT =====\n";

        showMenuStudent();

        std::cout << "Enter Option : ";
        std::cin >> studentOption;

    switch (studentOption) {
        case 0:
            std::cout << "Returning...\n";
            break;
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            editStudent();
            break;
        case 5:
            deleteStudent();
            break;
        default:
            std::cout << "Invalid Option." << std::endl;
    }

    } while (studentOption != 0);

    std::cout << "\n";

}