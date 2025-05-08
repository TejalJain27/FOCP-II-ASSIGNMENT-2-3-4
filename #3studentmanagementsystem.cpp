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
        name =other.name;
        rollno =other.rollno;
        cgpa =other.cgpa;
        courses=other.courses;}
// #1
    ~Student() {       // Destructor
        cout << "Destructor called for student: " << name << endl;}
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
// #3
int getRollNumber()const{  // Get Roll Number (for search)
    return rollno;}
};
class StudentManagementSystem {
private:
unordered_map<int, Student> students;
public:
void addStudent(const Student &student) {  // Add a new student
    if (students.find(student.getRollNumber()) == students.end()) {
        students[student.getRollNumber()] = student;
        cout << "Student added successfully." << endl;
    } else {
        cout << "Student with this roll number already exists." << endl;
    }
}
void searchStudent(int rollno) const {  // Search for a student by roll number
    auto it= students.find(rollno);
    if (it!= students.end()) {
        it->second.display();} 
    else {
        cout << "Student with roll number " << rollno << " not found." << endl;}}
void displayAllStudents() const {
    if (students.empty()) {
        cout << "No student records available." << endl;}
    else{
        for (const auto &pair : students) {
                    pair.second.display();}}}
};
int main() {
    Student s1;    // Default constructor
    s1.get();        
    s1.display();
    vector<string> courseList = {"Mathematics", "Physics", "Chemistry"};
    Student s2("Alice", 102, 3.8, courseList);  // Parameterized constructor
    s2.addCourse("Chemistry");
    s2.addCourse(""); 
    s2.updateCGPA(3.8);
    s2.updateCGPA(4.5);
    s2.display();    
    Student s3 = s2; //Copy constructor
    s3.display();

    StudentManagementSystem sms;
    vector<string>courses1 = {"Mathematics", "Physics"};
    Student s4("John", 101, 3.5, courses1);
    vector<string>courses2={"English", "Biology"};
    Student s5("Alice", 102, 3.8, courses2);
    sms.addStudent(s4);
    sms.addStudent(s5);
    cout << "\nSearch for Student :" << endl;
    sms.searchStudent(101);
    cout << "Display All Students" << endl;
    sms.displayAllStudents();
    return 0;
}

