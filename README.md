# 📚 Student Grade Manager
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://gcc.gnu.org/)

A comprehensive command-line grade management system built in C that empowers educators to efficiently manage, analyze, and visualize student academic performance data.

## 🎯 Core Features

### 📊 Grade Management
- Complete grade spreadsheet visualization
- Real-time student information updates
- Seamless record deletion
- Dynamic exam grade modifications
- Automated total grade calculations

### 🔄 Advanced Sorting
| Category | Description |
|----------|-------------|
| Student ID | Sort by 4-digit identifier |
| Last Name | Alphabetical sorting |
| Exam Grade | Numerical grade ordering |
| Total Grade | Overall performance sorting |

### 📈 Visualization Tools
- Interactive grade distribution histogram
- Formatted spreadsheet display
- ASCII art grade distribution
- Customizable display formats

## 🛠️ Technical Architecture

### 📁 Data Structure
**Student Record Format:**
```c
struct Student {
    int studentID;      // 4-digit
    char firstName[50];
    char lastName[50];
    float assignments[3];
    float midterm;
    float finalExam;
    float totalScore;
};
📊 Grade Calculation
ComponentWeightAssignments25% (A1 + A2 + A3)Midterm25%Final Exam50%
📂 Project Structure
Copystudent-grade-manager/
├── src/
│   ├── student.h        // Structure definitions
│   ├── spreadsheet.c    // Main program interface
│   ├── ordering.c       // Sorting algorithms
│   ├── calc.c          // Grade calculations
│   └── data.c          // File I/O operations
└── data/
    └── Students.txt     // Student records
🚀 Getting Started
Prerequisites

C compiler (GCC recommended)
Standard C libraries
Text editor

Installation
bashCopy# Compile the program
gcc -o grademanager *.c

# Run the application
./grademanager
📌 Menu Options
Copy1. Display Spreadsheet
2. Display Histogram
3. Set sort column
4. Update Last Name
5. Update Exam Grade
6. Update Grade Mapping
7. Delete Student
8. Exit
📄 Data Format
Input File Format (Students.txt)
CopyStudentID|LastName|FirstName|A1Grade|A2Grade|A3Grade|MidtermGrade|ExamGrade
System Constraints

Maximum capacity: 20 students
Student ID: 4-digit format
Grades: 0-100 range
File format: Pipe-delimited

⚙️ Configuration

Customizable grade thresholds
Flexible grading scale (A-F)
Adjustable weighting system
Modifiable display formats

🤝 Contributing
I welcome contributions! To contribute:
Fork the repository
Create a feature branch
Submit a pull request
