#include <iostream>
#include <string>

constexpr int MAX_STUDENTS = 5000;
int nextRollNo = 1;

struct Student {
    int rollNo;
    std::string name;
    float marks;
};

Student students[MAX_STUDENTS];
int totalStudents = 0;

bool checkStudents() {
    if (totalStudents == 0) {
        std::cout << "No Students Found.\n";
        return false;
    }
    return true;
}

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

        students[totalStudents].name = name;
        students[totalStudents].rollNo = nextRollNo;
        students[totalStudents].marks = marks;
        nextRollNo++;

        std::cout << "Roll No. of Student : "
                  << students[totalStudents].rollNo
                  << std::endl;

        totalStudents++;

        std::cout << "\nStudent Added Successfully!\n";

    std::cout << "\n";
    }

void viewStudents() {

    if (!checkStudents()) return;

    for (int i = 0; i<totalStudents; i++) {
        std::cout << "Student Name: " << students[i].name << std::endl;
        std::cout << "Student Marks: " << students[i].marks << std::endl;
        std::cout << "Student Roll No: " << students[i].rollNo << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "" << std::endl;
    }

    std::cout << "Total Students: " << totalStudents;

    std::cout << "\n";
}

void searchStudent() {

    if (!checkStudents()) return;

    int rollNo;
    std::cout << "Enter Student Roll No. : ";
    std::cin >> rollNo;
    bool found = false;

    for (int i = 0; i<totalStudents; i++) {
        if (students[i].rollNo == rollNo) {
            std::cout << "Student Name: " << students[i].name << std::endl;
            std::cout << "Student Marks: " << students[i].marks << std::endl;
            std::cout << "Student Roll No : " << students[i].rollNo << std::endl;
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
    if (!checkStudents()) return;

    int rollNo;
    std::cout << "Enter Student Roll No. : ";
    std::cin >> rollNo;
    bool found = false;

    float newMarks;
    std::string newName;

    for (int i = 0; i<totalStudents; i++) {
        if (students[i].rollNo == rollNo) {
            std::cout << "Enter New Student Name: ";
            std::cin.ignore(1000, '\n');
            getline(std::cin, newName);
            std::cout << "Enter New Student Marks : ";
            std::cin >> newMarks;
            if(newMarks < 0 || newMarks > 100) {
                std::cout << "Invalid Student Marks.\n";
                return;
            }

            students[i].name = newName;
            students[i].marks = newMarks;

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
    if (!checkStudents()) return;
    int rollNo;
    std::cout << "Enter Student Roll No. : ";
    std::cin >> rollNo;
    char choice;
    bool found = false;
    for (int i = 0; i<totalStudents; i++) {
        if (students[i].rollNo == rollNo) {
            found = true;
            std::cout << "Confirm To Delete Student (Y/n) : ";
            std::cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                for (int j = i; j < totalStudents - 1; j++) {
                    students[j] = students[j + 1];
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
    std::cout << "1. Add Student\n2. View All Students\n3. Search Student\n4. Edit Student\n5. Delete Student\n6. Calculate Average Marks\n7. Show Topper\n0. Back\n";
}

void calculateAvgMarks() {

    if (!checkStudents()) return;

    float total = 0;

    for (int i = 0; i<totalStudents; i++) {
        total += students[i].marks;
    }

    float avg = total / totalStudents;

    std::cout << "Average Marks : " << avg << std::endl;
}

void showTopper() {
    if (!checkStudents()) return;

    int index = 0;
    float topper = students[index].marks;

    for (int i = 0; i<totalStudents; i++) {
        if (students[i].marks > topper) {
            topper = students[i].marks;
            index = i;
        }
    }

    std::cout << "Topper Name : " << students[index].name << std::endl;
    std::cout << "Topper Marks : " << topper << std::endl;
    std::cout << "Topper Roll No : " << students[index].rollNo << std::endl;

}

void studentManagement() {
    int studentOption;

    do {
        std::cout << "\n";
        std::cout << "====================================================\n";
        std::cout << "            ORION STUDENT MANAGEMENT\n";
        std::cout << "====================================================\n";
        std::cout << "\n";

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
        case 6:
            calculateAvgMarks();
            break;
        case 7:
            showTopper();
            break;
        default:
            std::cout << "Invalid Option." << std::endl;
    }

    } while (studentOption != 0);

    std::cout << "\n";

}