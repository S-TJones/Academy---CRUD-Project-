
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring function prototypes
void loadStudents();
int loadEnrollment();
int loadCourses();
void menu();

// Structures
struct Courses
{
    char c_id[10];      // Course id
    char c_name[50];    // Course name
    float total_credit; // Course credit total

} C;

struct Enrollments
{
    int s_id;          // Student id
    char c_id[10];     // Course id
    char semester[30]; // Semester
    float score;       // Score

} E;

struct Students
{
    int e_id;                    // Unique id number
    char f_name[30], l_name[30]; // First and Last name
    int b_day, b_month, b_year;  // Birth Day, Month and Year

} S;

// Main
int main()
{
    // Variable declarations

    printf("Hello, World!\n");

    // In the beginning of your code, you should load the...
    // ...data from each of the files into appropriate structures...
    // ...so that you don't have to access the file frequently...
    // ...to perform the operations.
    loadCourses();
    loadEnrollment();
    loadStudents();

    // This function should be called from the main function after loading the array
    menu();

    return 0;
}

//-------------- Load Functions ------------------

void loadStudents()
{
}

// This function loads the en[] array with the data from the
// ..enrollment file and returns the total number of enrollment entries.
int loadEnrollment(Enrollments en[])
{
}

// This function loads the course[] array with the...
// ...data from the course file and returns the total...
// ... number of courses in the file.
int loadCourses(Courses course[])
{
}

// -------------------------------------------------------

// All the commands should be handled in this function in addition to other functions.
void menu(Students ArrayOfStudents[], int amountStudents, Courses ArrayOfCourses[], int amountCourses, Enrollments ArrayOfEnrollments[], int amountEnrolls)
{
    // Declaration
    char option[50];

    printf("Please enter an option.\n");
    return scanf("%s", option);
    printf("%s", option);

    // Infinite while loop [ here ]
}