#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct studentID {
    char name[100];
    int idNum;
    char course[10];
    int yearB;
} studentID;

void sortByName(studentID students[], int studentCount);
void sortByID(studentID students[], int studentCount);
void sortByCourse(studentID students[], int studentCount);
void printRecord(studentID students[], int studentCount);
void sortByYear(studentID students[], int studentCount);
int updateRecord(studentID students[], int studentCount);
void deleteRecord(studentID students[], int *studentCount);
// void populate(studentID students[], int *studentCount);

int main() {
    studentID students[MAX_STUDENTS];
    int choice, studentCount = 0;
    int *ptr = &studentCount;

    // Initializing pre-defined Student ID Records.
    strcpy(students[0].name, "Bob Smith");
    students[0].idNum = 25252525;
    strcpy(students[0].course, "BSIT");
    students[0].yearB = 2024;
    studentCount += 1;

    strcpy(students[1].name, "Jazz Miller");
    students[1].idNum = 19191919;
    strcpy(students[1].course, "BSCS");
    students[1].yearB = 2025;
    studentCount += 1;

    /////////////////////////////////////////////////////////////

    printf("Welcome to the Student Records Sorter.\n");
    printf("What would you like to do?\n\n");
    printf("(1) Sort Records by Name (ascending order).\n");
    printf("(2) Sort Records by ID Number (ascending order).\n");
    printf("(3) Sort Records by Course (ascending order).\n");
    printf("(4) Sort Records by Year (ascending order).\n");
    printf("(5) Update a Student Record.\n");
    printf("(6) Delete a Student Record.\n");
    printf("(7) Show list of students.\n");
    // printf("(8) Add Student Record/s.\n");

    printf("\nInput: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Records sorted by name in ascending order:\n\n");
            sortByName(students, studentCount);
            printRecord(students, studentCount);
            break;
        case 2:
            printf("Records sorted by ID in ascending order:\n\n");
            sortByID(students, studentCount);
            printRecord(students, studentCount);
            break;
        case 3:
            printf("Records sorted by course in ascending order:\n\n");
            sortByCourse(students, studentCount);
            printRecord(students, studentCount);
            break;
        case 4:
            printf("Records sorted by year in ascending order:\n\n");
            sortByYear(students, studentCount);
            printRecord(students, studentCount);
            break;
        case 5:
            system("CLS");
            if (updateRecord(students, studentCount)) {
                system("CLS");
                printf("Updated Record:\n");
                printRecord(students, studentCount);
            }
            break;
        case 6:
            deleteRecord(students, &studentCount);
            system("CLS");
            printf("Updated Record:\n");
            printRecord(students, studentCount);
            break;
        case 7:
            system("CLS");
            printRecord(students, studentCount);
            break;
        /* case 8:
            populate(students, ptr);
            break; */
        default:
            printf("Invalid input, program exiting...");
            return 0;
    }
    return 0;
}

void sortByName(studentID students[], int studentCount) {
    studentID temp;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < studentCount - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printRecord(studentID students[], int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        printf("\n");
        printf("Student Name: %s\n", students[i].name);
        printf("Student ID: %d\n", students[i].idNum);
        printf("Student Course: %s\n", students[i].course);
        printf("Student Year: %d\n", students[i].yearB);
    }
}

void sortByID(studentID students[], int studentCount) {
    studentID temp;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < studentCount - 1; j++) {
            if (students[j].idNum > students[j + 1].idNum) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByCourse(studentID students[], int studentCount) {
    studentID temp;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < studentCount - 1; j++) {
            if (strcmp(students[j].course, students[j + 1].course) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByYear(studentID students[], int studentCount) {
    studentID temp;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < studentCount - 1; j++) {
            if (students[j].yearB > students[j + 1].yearB) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int updateRecord(studentID students[], int studentCount) {
    int number, index = -1;

    printf("Enter the student's ID number: ");
    scanf("%d", &number);

    for (int i = 0; i < studentCount; i++) {
        if (number == students[i].idNum) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter the student's updated name: ");
        scanf(" %[^\n]", students[index].name);
        printf("Enter the student's updated ID number: ");
        scanf("%d", &students[index].idNum);
        printf("Enter the student's updated course: ");
        scanf(" %[^\n]", students[index].course);
        printf("Enter the student's updated year: ");
        scanf("%d", &students[index].yearB);
        
        return 1;
    } else {
        printf("Student ID number not found!\n");
        return 0;
    }
}

void deleteRecord(studentID students[], int *studentCount) {
    int number, found = -1;
    
    printf("Enter the student's ID number: ");
    scanf("%d", &number);
    
    for (int i = 0; i < *studentCount; i++) {
        if (number == students[i].idNum) {
            found = i;
            break;
        }
    }

    if (found >= 0) {
        for (int i = found; i < *studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        (*studentCount)--;
    } else {
        printf("Student ID number not found!\n");
    }
}

// Does not work for now since the main loop does not have another loop to store progress.
/*
void populate(studentID students[], int *studentCount) {
    int addStudents;

    system("CLS");
    printf("No. of student/s to add: ");
    scanf("%d", &addStudents);
    printf("\n");

    if (addStudents + *studentCount <= 100 && addStudents > 0) {
        for (int i = 0; i < addStudents; i++) {
            printf("Enter Details for student %d\n\n", i + 1);
            printf("Enter student name: ");
            scanf(" %[^\n]", students[*studentCount + i].name);
            printf("Enter student ID number: ");
            scanf("%d", &students[*studentCount + i].idNum);
            printf("Enter course: ");
            scanf(" %[^\n]", students[*studentCount + i].course);
            printf("Enter year: ");
            scanf("%d", &students[*studentCount + i].yearB);
            system("CLS");
        }
        *studentCount += addStudents;
    } else {
        printf("Invalid input, program exiting...");
    }
}
*/