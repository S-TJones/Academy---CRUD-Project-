
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring function prototypes
int loadStudents();
int loadEnrollment();
int loadCourses();
void menu();

// Structures
typedef struct Courses
{
    char c_id[10];      // Course id
    char c_name[50];    // Course name
    float total_credit; // Course credit total

} C;

typedef struct Enrollments
{
    int s_id;          // Student id
    char c_id[10];     // Course id
    char semester[30]; // Semester
    float score;       // Score

} E;

typedef struct Students
{
    int e_id;                    // Unique id number
    char f_name[30], l_name[30]; // First and Last name
    int b_day, b_month, b_year;  // Birth Day, Month and Year

} S;

// Main
int main()
{
    // Variable declarations
    int num_courses, num_enroll, num_students;
    S st[2000];     // You can assume there should not be more than 2000 students.
    C course[100]; // You can assume there should not be more than 100 courses.
    E en[2000];     // You can assume there should not be more than 5000 enrollments.

    printf("Hello, World!\n");

    // In the beginning of your code, you should load the...
    // ...data from each of the files into appropriate structures...
    // ...so that you don't have to access the file frequently...
    // ...to perform the operations.
    num_courses = loadCourses(course);
    num_enroll = loadEnrollment(en);
    num_students = loadStudents(st);

    // This function should be called from the main function after loading the array
    menu(st, num_students, course, num_courses, en, num_enroll);

    printf("Bye!");
    return 0;
}

//-------------- Load Functions ------------------

// This function will update the referenced variable according to the total number of students in the file.
int loadStudents(S st[])
{
    return 0;
}

// This function loads the en[] array with the data from the
// ..enrollment file and returns the total number of enrollment entries.
// int loadEnrollment(Enrollments en[])
int loadEnrollment(E en[])
{
    return 0;
}

// This function loads the course[] array with the...
// ...data from the course file and returns the total...
// ... number of courses in the file.
// int loadCourses(Courses course[])
int loadCourses(C course[])
{
    return 0;
}

// -------------------------------------------------------

// All the commands should be handled in this function in addition to other functions.
void menu(S ArrayOfStudents[], int amountStudents, C ArrayOfCourses[], int amountCourses, E ArrayOfEnrollments[], int amountEnrolls)
{
    // Declaration
    char option[50];

    printf("Please enter an option.\n");
    scanf("%s", option);
    fflush(stdin);
    printf("%s", option);

    // Infinite while loop [ here ]
}