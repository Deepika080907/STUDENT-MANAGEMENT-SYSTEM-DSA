# Student Management System - DSA Project

**Name:** Deepika  
**Roll No.:** BC2025097  
**Language:** C  
**Project Type:** Data Structures and Algorithms (DSA)

## Description

The Student Management System is a menu-driven C program used to manage student records.

Each student record contains:
- Roll Number
- Name
- Course
- Marks

## DSA Concepts Used

- Structure
- Array
- Linear Search
- Bubble Sort
- Insertion and deletion in an array
- Functions
- Menu-driven programming

## Features

1. Add Student
2. Display All Students
3. Search Student by Roll Number
4. Update Student
5. Delete Student
6. Sort Students by Marks
7. Exit

## Complexity

- Add: O(n) in the worst case because duplicate roll number is checked using linear search
- Search: O(n)
- Update: O(n)
- Delete: O(n)
- Display: O(n)
- Bubble Sort: O(n²)
- Space: O(n)

## How to Run

Compile:

```bash
gcc student_management.c -o student_management
```

Run:

```bash
./student_management
```

## Sample Output

```text
========================================
       STUDENT MANAGEMENT SYSTEM
          DSA PROJECT IN C
========================================
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Sort by Marks
7. Exit
========================================
Enter your choice: 1

Enter Roll Number: 101
Enter Student Name: Deepika
Enter Course: BCA
Enter Marks: 85

Student added successfully!
```
