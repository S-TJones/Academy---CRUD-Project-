
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring function prototypes
int loadStudents();
int loadEnrollment();
int loadCourses();
void menu();

void search_student_lname();
void search_student_fname();
void search_student_id();
void search_student_byear();
void search_course_cid();
void search_course_semester();
void add_course();
void count_students();
void count_course();
void count_semester();
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

		count = (count + 1); // Counts the number of students
	}

	fclose(s_ptr); // Closes the file

	return count;
}

// This function loads the en[] array with the data from the
// ..enrollment file and returns the total number of enrollment entries.
// int loadEnrollment(Enrollments en[])
int loadEnrollment(E *en)
{
	int count = 0;
	E enrollment;

	FILE *e_ptr;						  // Declares the file pointer
	e_ptr = fopen("enrollment.txt", "r"); // Opens the file for reading

	// Begin reading each line from the 'enrollment.txt' file...
	while (!feof(e_ptr)) // ... until EOF-End of File
	{
		fscanf(e_ptr, "%d %s %s %f ", &enrollment.s_id, enrollment.c_id, enrollment.semester, &enrollment.score);
		// printf("Enrolls: %d %s %s %f - line %d\n", enrollment.s_id, enrollment.c_id, enrollment.semester, enrollment.score, count);

		en[count] = enrollment; // Update Enrollment-array

		count = (count + 1); // Counts the number of enrollments
	}

	fclose(e_ptr); // Closes the file

	return count;
}

// This function loads the course[] array with the...
// ...data from the course file and returns the total...
// ... number of courses in the file.
// int loadCourses(Courses course[])
int loadCourses(C *course)
{
	int count = 0;
	C a_course;

	FILE *c_ptr;					   // Declares the file pointer
	c_ptr = fopen("courses.txt", "r"); // Opens the file for reading

	// Begin reading each line from the 'courses.txt' file...
	while (!feof(c_ptr)) // ... until EOF-End of File
	{
		fscanf(c_ptr, "%s %s %f ", a_course.c_id, a_course.c_name, &a_course.total_credit);
		// printf("Courses: %s %s %f - line %d\n", a_course.c_id, a_course.c_name, a_course.total_credit, count);

		course[count] = a_course; // Updates the Course-array

		count = (count + 1); // Counts the number of courses
	}

	fclose(c_ptr); // Closes the file

	return count;
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

				// Call the search_student function
				search_student_lname(ArrayOfStudents);
			}
			else if (strcmp(options[1], input_o) == 0) // fname
			{
				printf("Searching for student with first name: %s\n", input_d);

				// Call the search_student function
				search_student_fname(ArrayOfStudents);
			}
			else if (strcmp(options[2], input_o) == 0) // id
			{
				printf("Searching for student with the id: %s\n", input_d);

				// Call the search_student function
				search_student_id(ArrayOfStudents);
			}
			else if (strcmp(options[3], input_o) == 0) // byear
			{
				printf("Searching for student with the birth year: %s\n", input_d);

				// Call the search_student function
				search_student_byear(ArrayOfStudents);
			}
			else
			{
				printf("Wrong option for \'search_student\' command. Try again.\n");
			}
		}
		else if (strcmp(commands[1], input_c) == 0) // search_courses
		{
			char input_o[20], input_cid[20], input_semester[20];

			scanf("%s %s", input_o, input_cid);

			// Check to see if the input is a valid option
			if (strcmp(options[4], input_o) == 0) // cid
			{
				printf("Searching for a course with the ID: %s\n", input_cid);

				// Call the search_course function
				search_course_cid(ArrayOfCourses, ArrayOfEnrollments, ArrayOfStudents);
			}
			else if (strcmp(options[5], input_o) == 0) // cid_semester
			{
				scanf("%s", input_semester);
				printf("Searching for a course with the ID & Semester: %s & %s\n", input_cid, input_semester);

				// Call the search_course function
				search_course_semester(ArrayOfEnrollments, ArrayOfCourses, ArrayOfStudents);
			}
			else
			{
				printf("Wrong option for \'search_course\' command. Try again.\n");
			}
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

				// Call the count function
				count_students(ArrayOfStudents);
			}
			else if (strcmp(options[7], input) == 0) // students_course
			{
				printf("Counting the number of: %s\n", input);

				// Call the count function
				count_course(ArrayOfCourses);
			}
			else if (strcmp(options[8], input) == 0) // students_semester
			{
				printf("Counting the number of: %s\n", input);

				// Call the count function
				count_semester(ArrayOfEnrollments);
			}
			else
			{
				printf("Wrong option for \'count\' command. Try again.\n");
			}
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

// ------------------- Search_Student Functions --------------------

// This function displays all the information of the students with the given last name.
void search_student_lname(S *student_array)
{
	printf("Search by Last Name\n");

	printf("------------------\n");
}

// This function displays all the information of the students with the given first name.
void search_student_fname(S *student_array)
{
	printf("Search by First Name\n");

	printf("------------------\n");
}

// This function displays all the information of the students with the given id number.
void search_student_id(S *student_array)
{
	printf("Search by ID\n");

	printf("------------------\n");
}

// This function displays all the information of the students with the given birth year.
void search_student_byear(S *student_array)
{
	printf("Search by Birth Year\n");

	printf("------------------\n");
}

// ------------------- Search_Courses Functions --------------------

// This function will display the course information and all the students enrolled to that course.
void search_course_cid(C *course_array, E *enroll_array, S *student_array)
{
	printf("Search Course ID\n");

	printf("------------------\n");
}

// This function will display the list of students enrolled in that course on that particular semester.
void search_course_semester(E *enroll_array, C *course_array, S *student_array)
{
	printf("Search Course Semester\n");

	printf("------------------\n");
}

// ------------------- Add_Course Functions --------------------

// This function will add new records to the end of the course.txt file.
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

// ------------------- Count Functions --------------------

// This function will display the total number of students
void count_students(S *student_array)
{
	printf("Count Students\n");

	printf("------------------\n");
}

// This function will display the total number of students for each cid
void count_course(C *courses_array)
{
	printf("Count Courses\n");

	printf("------------------\n");
}

// This function will display the total number of students for each semester
void count_semester(E *enroll_array)
{
	printf("Counting Semester\n");

	printf("------------------\n");
}

// ------------------- Sort Function --------------------

void sort(S ArrayOfStudents[], int num_students)
{
	printf("Sorting the students by ID\n");

	printf("------------------\n");
}