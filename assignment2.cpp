#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Student1 {
private:
    string name;
    int rollNumber;
    float cgpa;
    string* courses;
    int courseCount;

public:
    Student1() : name("Unknown"), rollNumber(0), cgpa(0.0), courses(nullptr), courseCount(0) {}

    Student1(string n, int roll, float c, string* courseList, int count)
        : name(n), rollNumber(roll), cgpa(c), courseCount(count) {
        courses = new string[courseCount];
        for (int i = 0; i < courseCount; ++i) {
            courses[i] = courseList[i];
        }
    }

    Student1(const Student1& other)
        : name(other.name), rollNumber(other.rollNumber), cgpa(other.cgpa), courseCount(other.courseCount) {
        courses = new string[courseCount];
        for (int i = 0; i < courseCount; ++i) {
            courses[i] = other.courses[i];
        }
    }

    ~Student1() {
        delete[] courses;
    }

    void display() const {
        cout << "\n[Student1]\n";
        cout << "Name: " << name << "\nRoll No: " << rollNumber
             << "\nCGPA: " << cgpa << "\nCourses Enrolled:\n";
        for (int i = 0; i < courseCount; ++i) {
            cout << "- " << courses[i] << "\n";
        }}
};

class Student2 {
private:
    char name[100];
    int rollNumber;
    float cgpa;
    char courses[10][100];
    int courseCount;

public:
    Student2() {
        strcpy(name, "Unknown");
        rollNumber = 0;
        cgpa = 0.0;
        courseCount = 0;
    }

    Student2(const char* n, int roll, float c, const char courseList[][100], int count) {
        strcpy(name, n);
        rollNumber = roll;
        setCGPA(c);
        courseCount = 0;
        for (int i = 0; i < count && i < 10; i++) {
            addCourse(courseList[i]);
        }
    }

    Student2(const Student2& other) {
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        cgpa = other.cgpa;
        courseCount = other.courseCount;
        for (int i = 0; i < courseCount; i++) {
            strcpy(courses[i], other.courses[i]);
        }
    }

    void addCourse(const char* course) {
        for (int i = 0; i < courseCount; i++) {
            if (strcmp(courses[i], course) == 0) {
                cout << "Course already enrolled.\n";
                return;
            }
        }
        if (courseCount < 10) {
            strcpy(courses[courseCount], course);
            courseCount++;
            cout << "Course added successfully.\n";
        } else {
            cout << "Maximum course limit reached.\n";
        }
    }

    void setCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 10.0) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA. Must be between 0 and 10.\n";
        }
    }

    void display(const string& label) const {
        cout << "\n[" << label << "]\n";
        cout << "Name: " << name << "\nRoll No: " << rollNumber
             << "\nCGPA: " << cgpa << "\nCourses Enrolled:\n";
        for (int i = 0; i < courseCount; i++) {
            cout << "- " << courses[i] << "\n";
        }
    }
};
class Student3 {
private:
    char name[100];
    int rollNumber;
    float cgpa;
    char courses[10][100];
    int courseCount;

public:
    Student3() {
        strcpy(name, "Unknown");
        rollNumber = 0;
        cgpa = 0.0;
        courseCount = 0;
    }

    Student3(const char* n, int roll, float c, const char courseList[][100], int count) {
        strcpy(name, n);
        rollNumber = roll;
        setCGPA(c);
        courseCount = 0;
        for (int i = 0; i < count && i < 10; i++) {
            addCourse(courseList[i]);
        }
    }

    Student3(const Student3& other) {
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        cgpa = other.cgpa;
        courseCount = other.courseCount;
        for (int i = 0; i < courseCount; i++) {
            strcpy(courses[i], other.courses[i]);
        }
    }

    void addCourse(const char* course) {
        for (int i = 0; i < courseCount; i++) {
            if (strcmp(courses[i], course) == 0) {
                cout << "Course already enrolled.\n";
                return;
            }
        }
        if (courseCount < 10) {
            strcpy(courses[courseCount], course);
            courseCount++;
            cout << "Course added successfully.\n";
        } else {
            cout << "Maximum course limit reached.\n";
        }
    }

    void setCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 10.0) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA. Must be between 0 and 10.\n";
        }
    }

    void display(const string& label) const {
        cout << "\n[" << label << "]\n";
        cout << "Name: " << name << "\nRoll No: " << rollNumber
             << "\nCGPA: " << cgpa << "\nCourses Enrolled:\n";
        for (int i = 0; i < courseCount; i++) {
            cout << "- " << courses[i] << "\n";
        }}
};
int main() {
    // Student1 
    string courseList1[] = {"Math", "Physics", "CS"};
    Student1 s1("Tejal Jain", 101, 9.3, courseList1, 3);
    Student1 s2 = s1;
    s1.display();
    s2.display();

    // Student2
    const char initialCourses2[2][100] = {"Math", "Physics"};
    Student2 s1_2("Tejal Jain", 102, 9.3, initialCourses2, 2);
    s1_2.display("Student2");

    // Student3
    const char initialCourses3[2][100] = {"Math", "Physics"};
    Student3 s1_3("Tejal Jain", 103, 9.3, initialCourses3, 2);
    s1_3.display("Student3 Initial Info");

    cout << "\nadding 'Math' again:\n";
    s1_3.addCourse("Math");

    cout << "\nAdding 'Chemistry':\n";
    s1_3.addCourse("Chemistry");

    cout << "\nUpdating CGPA to 9.3:\n";
    s1_3.setCGPA(9.3);

    cout << "\nFinal Student3 Info:\n";
    s1_3.display("Student3 Final Info");

    return 0;
}