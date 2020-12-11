
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring function prototypes
int loadStudents();
int loadEnrollment();
int loadCourses();
void menu();

void search_student();
void search_course();
void add_course();
void count();
void sort();

// Structures
typedef struct Courses
{
	char c_id[10];		// Course id
	char c_name[50];	// Course name
	float total_credit; // Course credit total

} C;

typedef struct Enrollments
{
	int s_id;		   // Student id
	char c_id[10];	   // Course id
	char semester[30]; // Semester
	float score;	   // Score

} E;

typedef struct Students
{
	int e_id;					 // Unique id number
	char f_name[30], l_name[30]; // First and Last name
	int b_day, b_month, b_year;	 // Birth Day, Month and Year

} S;

// Main
int main()
{
	// Variable declarations
	int num_courses, num_enroll, num_students;
	S st[2000];	   // You can assume there should not be more than 2000 students.
	C course[100]; // You can assume there should not be more than 100 courses.
	E en[2000];	   // You can assume there should not be more than 5000 enrollments.

	// In the beginning of your code, you should load the...
	// ...data from each of the files into appropriate structures...
	// ...so that you don't have to access the file frequently...
	// ...to perform the operations.
	num_courses = loadCourses(course);
	num_enroll = loadEnrollment(en);
	num_students = loadStudents(st);

	// This function should be called from the main function after loading the array
	menu(st, num_students, course, num_courses, en, num_enroll);

	return 0;
}

//-------------------- Load Functions ----------------------

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

// ----------------------- Menu ---------------------------

// All the commands should be handled in this function in addition to other functions.
void menu(S ArrayOfStudents[], int amountStudents, C ArrayOfCourses[], int amountCourses, E ArrayOfEnrollments[], int amountEnrolls)
{
	// Declaration
	char commands[6][15] = {"search_student", "search_courses", "add_course", "count", "sort", "exit"};
	char options[9][20] = {"fname", "lname", "id", "byear", "cid", "cid_semester", "students", "students_course", "students_semester"};

	char input_c[15], input_o[20], input_d[20];
	int i;

	// Infinite while loop
	while (1)
	{

		printf("==================\n");
		scanf("%s", input_c);
		fflush(stdin);
		printf("------------------\n");

		// Check to see if the input is a valid command
		if (strcmp(commands[0], input_c) == 0) // search_student
		{
			// Call the _ function
			printf("Enter other details: ");
			scanf("%s %s", input_o, input_d);
			fflush(stdin);
			search_student(options, input_o);
		}
		else if (strcmp(commands[1], input_c) == 0) // search_courses
		{
			// Call the _ function
			printf("Enter other details: ");
			scanf("%s %s", input_o, input_d);
			fflush(stdin);
			search_course(options, input_o);
		}
		else if (strcmp(commands[2], input_c) == 0) // add_course
		{
			// Call the _ function
			printf("Enter other details: ");
			scanf("%s %s", input_o, input_d);
			fflush(stdin);
			add_course(options, input_o);
		}
		else if (strcmp(commands[3], input_c) == 0) // count
		{
			// Call the _ function
			printf("Enter other details: ");
			scanf("%s %s", input_o, input_d);
			fflush(stdin);
			count(options, input_o);
		}
		else if (strcmp(commands[4], input_c) == 0) // sort
		{
			// Call the _ function
			sort();
		}
		else if (strcmp(commands[5], input_c) == 0) // exit
		{
			printf("Bye!\n");
			break;
		}
		else
		{
			printf("Wrong option. Try again.\n");
		}
	}
}

// ------------------- Helper Functions --------------------

void search_student(char *options[], char info[])
{
	printf("Searching for student: %s\n", info);
}

void search_course(char *options[], char info[])
{
	printf("Searching for course: %s\n", info);
}

void add_course(char *options[], char info[])
{
	printf("Adding a course: %s\n", info);
}

void count(char *options[], char info[])
{
	printf("Counting: %s\n", info);
}

void sort()
{
	printf("Sorting the students by ID\n");
}