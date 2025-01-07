

Student Grade Manager 📚

A comprehensive grade management system built in C that allows educators to manage, analyze, and visualize student academic performance data.
Features
Grade Management

View complete grade spreadsheet
Update student information
Delete student records
Modify exam grades
Calculate total grades automatically

Sorting Capabilities

Sort by Student ID
Sort by Last Name
Sort by Exam Grade
Sort by Total Grade

Visualization

Display grade distribution histogram
Clear, formatted spreadsheet view
Visual grade distribution with ASCII art

Grade Mapping

Customizable grade thresholds
Dynamic grade calculation
Support for A-F grading scale
Automatic total score calculation

Technical Details
Data Structure
Student records contain:

Student ID (4-digit)
First and Last Name
Assignment Grades (A1, A2, A3)
Midterm Grade
Final Exam Grade
Total Score

Grade Calculation

Assignments: 25% (A1 + A2 + A3)
Midterm: 25%
Final Exam: 50%

File Structure

student.h - Header file with struct definitions
spreadsheet.c - Main program and menu interface
ordering.c - Sorting functions
calc.c - Grade calculations and display functions
data.c - File I/O operations

1. Display Spreadsheet
2. Display Histogram
3. Set sort column
4. Update Last Name
5. Update Exam Grade
6. Update Grade Mapping
7. Delete Student
8. Exit
   
Data Format
The program expects student data in a pipe-delimited text file (Students.txt) with the following format:
CopyStudentID|LastName|FirstName|A1Grade|A2Grade|A3Grade|MidtermGrade|ExamGrade
Requirements

C compiler (GCC recommended)
Standard C libraries
Text file with student data in the specified format

Note

Maximum support for 20 students
Grade thresholds are customizable
All grades are validated upon entry
Student IDs must be 4 digits
