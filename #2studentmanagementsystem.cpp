#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int rollno;
    float cgpa;
    int n;
    vector<string> courses;  // Changed to vector to store multiple courses
public:
    Student():name(""),rollno(0), cgpa(0.0){} // Default Constructor
    Student(string name, int rollno, float cgpa, vector<string> courses)
        : name(name), rollno(rollno), cgpa(cgpa), courses(courses) {} // Parameterized Constructor
    Student(const Student &other) { // Copy Constructor
        name = other.name;
        rollno = other.rollno;
        cgpa = other.cgpa;
        courses = other.courses;
    }
    ~Student() {
        cout << "Destructor called for student: " << name << endl;
    } // Destructor
    void get() {
        cout << "Provide student's name: ";
        cin.ignore(); // To handle leftover character
        getline(cin, name);
        cout << "Enter student's roll no: ";
        cin >> rollno;
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cout << "Enter number of courses enrolled: ";
        cin >> n;
        cin.ignore(); // To handle leftover newline character 
        courses.clear(); // Clear any existing courses
        for (int i=0; i<n;i++) {
            cout << "Enter the name of course " <<(i + 1) << ": ";
            string course;
            getline(cin, course);
            courses.push_back(course);
        }
    }
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll no.: " << rollno << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Courses Enrolled:" << endl;
        for (const auto &course : courses) {
            cout << "- " << course << endl;
        }
    }
// #2
void addCourse(const string &course) { //ADD COURSE
    if (!course.empty()) {
        courses.push_back(course);
        cout << "Course added successfully." << endl;
    } else {
        cout << "Invalid course name!" << endl;
    }
}
void updateCGPA(float newCGPA) {  // Update student CGPA
    if (newCGPA >= 0.0 && newCGPA <= 4.0) {
        cgpa = newCGPA;
        cout << "CGPA updated successfully." << endl;
    } else {
        cout << "CGPA value  must be between 0.0 and 4.0." << endl;
    }
}
};
int main() {
    Student s1;    // Default constructor
    s1.get();        
    s1.display();
    vector<string> courseList = {"Mathematics", "Physics", "Chemistry"};
    Student s2("Alice", 102, 3.8, courseList);  // Parameterized constructor
    s2.addCourse("Chemistry");
    s2.addCourse(""); // Invalid case
    s2.updateCGPA(3.8);
    s2.updateCGPA(4.5); // Invalid case
    s2.display();    
    Student s3 = s2; //Copy constructor
    s3.display();
    return 0;}

