
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
int loadStudents(S *st)
{
	int count = 0;
	S student;

	FILE *s_ptr;						// Declares the file pointer
	s_ptr = fopen("students.txt", "r"); // Opens the file for reading

	// Begin reading each line from the 'students.txt' file...
	while (!feof(s_ptr)) // ... until EOF-End of File
	{
		fscanf(s_ptr, "%d %s %s %d %d %d ", &student.e_id, student.f_name, student.l_name, &student.b_day, &student.b_month, &student.b_year);
		// printf("%d %s %s %d %d %d: line %d\n", student.e_id, student.f_name, student.l_name, student.b_day, student.b_month, student.b_year, count);

		st[count] = student; // Update Student-array

		count = (count + 1); // Count the number of students
	}

	fclose(s_ptr); // Closes the file

	return count;
}

// This function loads the en[] array with the data from the
// ..enrollment file and returns the total number of enrollment entries.
// int loadEnrollment(Enrollments en[])
int loadEnrollment(E *en[])
{
	return 0;
}

// This function loads the course[] array with the...
// ...data from the course file and returns the total...
// ... number of courses in the file.
// int loadCourses(Courses course[])
int loadCourses(C *course[])
{
	return 0;
}

// ----------------------- Menu ---------------------------

// All the commands should be handled in this function in addition to other functions.
void menu(S ArrayOfStudents[], int amountStudents, C ArrayOfCourses[], int amountCourses, E ArrayOfEnrollments[], int amountEnrolls)
{
	// Declaration
	char commands[6][15] = {"search_student", "search_courses", "add_course", "count", "sort", "exit"};
	char options[9][20] = {"lname", "fname", "id", "byear", "cid", "cid_semester", "students", "students_course", "students_semester"};

	char input_c[15];
	int i;

	// Infinite while loop
	while (1)
	{

		printf("==================\n");
		scanf("%s", input_c);
		printf("------------------\n");

		// Check to see if the input is a valid command
		if (strcmp(commands[0], input_c) == 0) // search_student
		{
			char input_o[20], input_d[20];

			scanf("%s %s", input_o, input_d);

			// Check to see if the input is a valid option
			if (strcmp(options[0], input_o) == 0) // lname
			{
				printf("Searching for student with last name: %s\n", input_d);
			}
			else if (strcmp(options[1], input_o) == 0) // fname
			{
				printf("Searching for student with first name: %s\n", input_d);
			}
			else if (strcmp(options[2], input_o) == 0) // id
			{
				printf("Searching for student with the id: %s\n", input_d);
			}
			else if (strcmp(options[3], input_o) == 0) // byear
			{
				printf("Searching for student with the birth year: %s\n", input_d);
			}
			else
			{
				printf("Wrong option for \'search_student\' command. Try again.\n");
			}

			// Call the search_student function
			search_student(options);
		}
		else if (strcmp(commands[1], input_c) == 0) // search_courses
		{
			char input_o[20], input_cid[20], input_semester[20];

			scanf("%s %s", input_o, input_cid);

			// Check to see if the input is a valid option
			if (strcmp(options[4], input_o) == 0) // cid
			{
				printf("Searching for a course with the ID: %s\n", input_cid);
			}
			else if (strcmp(options[5], input_o) == 0) // cid_semester
			{
				scanf("%s", input_semester);
				printf("Searching for a course with the ID & Semester: %s & %s\n", input_cid, input_semester);
			}
			else
			{
				printf("Wrong option for \'search_course\' command. Try again.\n");
			}

			// Call the search_course function
			search_course(options);
		}
		else if (strcmp(commands[2], input_c) == 0) // add_course
		{
			// Call the add_course function
			add_course(ArrayOfCourses, amountCourses);
		}
		else if (strcmp(commands[3], input_c) == 0) // count
		{
			char input[20];

			scanf("%s", input);

			// Check to see if the input is a valid option
			if (strcmp(options[6], input) == 0) // students
			{
				printf("Counting the number of: %s\n", input);
			}
			else if (strcmp(options[7], input) == 0) // students_course
			{
				printf("Counting the number of: %s\n", input);
			}
			else if (strcmp(options[8], input) == 0) // students_semester
			{
				printf("Counting the number of: %s\n", input);
			}
			else
			{
				printf("Wrong option for \'count\' command. Try again.\n");
			}

			// Call the count function
			count(options);
		}
		else if (strcmp(commands[4], input_c) == 0) // sort
		{
			// Call the sort function
			sort(ArrayOfStudents, amountStudents);
		}
		else if (strcmp(commands[5], input_c) == 0) // exit
		{
			printf("Bye!\n");
			break;
		}
		else
		{
			printf("Wrong command. Try again.\n");
		}
	}
}

// ------------------- Helper Functions --------------------

void search_student(char *options[])
{
	printf("Nt here 1\n");

	printf("------------------\n");
}

void search_course(char *options[])
{
	printf("Ntn here 2\n");

	printf("------------------\n");
}

void add_course(C ArrayOfCourses[], int num_courses)
{
	int credit;
	char cid[20], c_name[20];

	scanf("%s %s %d", cid, c_name, &credit);

	// Make Course struct
	printf("Making a Course structure\n");

	// Add new Corse struct to array

	printf("------------------\n");
}

void count(char *options[])
{
	printf("Ntn here 3\n");

	printf("------------------\n");
}

void sort(S ArrayOfStudents[], int num_students)
{
	printf("Sorting the students by ID\n");

	printf("------------------\n");
}