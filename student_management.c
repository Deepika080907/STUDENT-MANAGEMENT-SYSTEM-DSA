#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int rollNo;
    char name[50];
    char course[30];
    float marks;
} Student;

Student students[MAX];
int count = 0;

/* Function declarations */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void sortStudents();
void menu();

int findStudent(int rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo)
            return i;
    }
    return -1;
}

/* Add a new student */
void addStudent() {
    if (count >= MAX) {
        printf("\nStudent record is full!\n");
        return;
    }

    int rollNo;
    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNo);

    if (findStudent(rollNo) != -1) {
        printf("A student with this Roll Number already exists.\n");
        return;
    }

    students[count].rollNo = rollNo;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter Course: ");
    scanf(" %29[^\n]", students[count].course);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("\nStudent added successfully!\n");
}

/* Display all students */
void displayStudents() {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s\n",
           "Roll No.", "Name", "Course", "Marks");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-20s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].course,
               students[i].marks);
    }
}

/* Search a student */
void searchStudent() {
    int rollNo;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    int index = findStudent(rollNo);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\nStudent Found!\n");
    printf("Roll Number : %d\n", students[index].rollNo);
    printf("Name        : %s\n", students[index].name);
    printf("Course      : %s\n", students[index].course);
    printf("Marks       : %.2f\n", students[index].marks);
}

/* Update student details */
void updateStudent() {
    int rollNo;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &rollNo);

    int index = findStudent(rollNo);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter New Name: ");
    scanf(" %49[^\n]", students[index].name);

    printf("Enter New Course: ");
    scanf(" %29[^\n]", students[index].course);

    printf("Enter New Marks: ");
    scanf("%f", &students[index].marks);

    printf("\nStudent record updated successfully!\n");
}

/* Delete a student */
void deleteStudent() {
    int rollNo;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);

    int index = findStudent(rollNo);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;
    printf("\nStudent deleted successfully!\n");
}

/* Sort students by marks in descending order */
void sortStudents() {
    if (count < 2) {
        printf("\nNot enough records to sort.\n");
        return;
    }

    /* Bubble Sort - a basic DSA sorting technique */
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by marks (highest to lowest).\n");
}

/* Main menu */
void menu() {
    printf("\n========================================\n");
    printf("       STUDENT MANAGEMENT SYSTEM\n");
    printf("          DSA PROJECT IN C\n");
    printf("========================================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Sort by Marks\n");
    printf("7. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                printf("\nThank you for using Student Management System!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
