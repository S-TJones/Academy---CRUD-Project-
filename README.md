# Academy---CRUD-Project-

### A small C project centered around developing a file I/O based database system for storing and searching students information of IMAGINARY Academy.

---

#### There are 6 commands and 9 subcommands (and scenarios) in the project.

They are:

1. **search_student** : This command asks the user for another option.
   The options are:

   - _lname_ : This option asks for a student&#39;s last name and displays all the information of the students with the given last name. The information includes Student ID, Full Name, Date of birth., list of courses, semester, score, and letter grade. The grading scale is: A: &gt;90, B: 80-89.99, C: 70 - 79.99, D: 60-69.99, F:&lt;60
   - _fname_ : This option asks for a student&#39;s first name and displays all the information of the students with the given last name. The information includes Student ID, Full Name, Date of birth., list of courses, semester, score, and letter grade
   - _id_ : This option asks for a student&#39;s id number and displays all the information of the student with the given id number name. The information includes Student ID, Full Name, Date of birth., list of courses, semester, score, and letter grade
   - _byear_ : This option asks for a student&#39;s year of birth and displays all the information of the student with the given year of birth. The information includes Student ID, Full Name, Date of birth., list of courses, semester, score, and letter grade

2. **search_courses** : This command asks the user for another option.

   - _cid_ : This option asks for a course id and displays the course information and all the students enrolled to that course. The information will include: Course Name, credit, student name, semester, grade.
   - _cid_semester_ : This option will ask the user for providing a courseid and semester and then it will display the list of students enrolled in that course on that particular semester.

3. **add_course** : This command will ask the user for a courseid, course name, and credit and add this record to the end of the course.txt file. Before adding the course, the system will check whether the course id already exists or not. If the course id already exists, it will display &quot;violation of course id uniqueness. Cannot add the record.&quot;

4. **count** : This command has the following options:

   - _students_ : this option will display the total number of students
   - _students_course_ : this option will display the total number of students for each cid
   - _students_semester_ : this option will display the total number of students for each semester

5. **sort** : This command will sort the student list based on their
   id number and display the list one student per line in the following format --> _id, firstname, lastname, day/month/year of birth_.

6. **exit** : This command will exit the program. Otherwise, the program will keep waiting for more commands until the user chooses to exit.
