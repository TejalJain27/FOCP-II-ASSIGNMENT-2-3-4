#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int studentID;

    Student(string n, int a, int id) : Person(n, a) {
        studentID = id;
    }

    void displayDetails() {
        cout << "Student ID: " << studentID << endl;
        Person::displayDetails();
    }
};

class UndergraduateStudent : public Student {
public:
    string major, minor, graduationDate;

    UndergraduateStudent(string n, int a, int id, string maj, string min, string gradDate)
        : Student(n, a, id) {
        major = maj;
        minor = min;
        graduationDate = gradDate;
    }

    void displayDetails() {
        cout << "Undergraduate Student - Major: " << major 
             << ", Minor: " << minor 
             << ", Graduation Date: " << graduationDate << endl;
        Student::displayDetails();
    }
};

class GraduateStudent : public Student {
public:
    string researchTopic, advisor, thesisTitle;

    GraduateStudent(string n, int a, int id, string topic, string adv, string thesis)
        : Student(n, a, id) {
        researchTopic = topic;
        advisor = adv;
        thesisTitle = thesis;
    }

    void displayDetails() {
        cout << "Graduate Student - Research Topic: " << researchTopic 
             << ", Advisor: " << advisor 
             << ", Thesis Title: " << thesisTitle << endl;
        Student::displayDetails();
    }
};

class Professor : public Person {
public:
    float salary;

    Professor(string n, int a, float sal) : Person(n, a) {
        salary = sal;
    }

    float calculatePayment() {
        return salary;
    }

    void displayDetails() {
        cout << "Professor - Salary: $" << salary << endl;
        Person::displayDetails();
    }
};

class AssistantProfessor : public Professor {
public:
    int yearsOfService;

    AssistantProfessor(string n, int a, float sal, int years) 
        : Professor(n, a, sal) {
        yearsOfService = years;
    }

    float calculatePayment() {
        return salary + (yearsOfService * 450);
    }

    void displayDetails() {
        cout << "Assistant Professor - Years of Service: " 
             << yearsOfService 
             << ", Total Payment: $" << calculatePayment() << endl;
        Professor::displayDetails();
    }
};

class AssociateProfessor : public Professor {
public:
    int publications;

    AssociateProfessor(string n, int a, float sal, int pubs) 
        : Professor(n, a, sal) {
        publications = pubs;
    }

    float calculatePayment() {
        return salary + (publications * 900);
    }

    void displayDetails() {
        cout << "Associate Professor - Publications: " 
             << publications 
             << ", Total Payment: $" << calculatePayment() << endl;
        Professor::displayDetails();
    }
};

class FullProfessor : public Professor {
public:
    bool tenure;

    FullProfessor(string n, int a, float sal, bool ten) 
        : Professor(n, a, sal) {
        tenure = ten;
    }

    float calculatePayment() {
        return tenure ? salary + 6000 : salary + 2500;
    }

    void displayDetails() {
        cout << "Full Professor - Tenure Status: " 
             << (tenure ? "Yes" : "No") 
             << ", Total Payment: $" << calculatePayment() << endl;
        Professor::displayDetails();
    }
};

class Course {
public:
    string courseName;
    Professor* instructor;

    Course(string name, Professor* prof) {
        courseName = name;
        instructor = prof;
    }

    void displayCourseDetails() {
        cout << "\nCourse Title: " << courseName 
             << "\nInstructor Information:" << endl;
        instructor->displayDetails();
    }
};

class Department {
public:
    string departmentName;
    Professor* professors[10];
    int professorCount;

    Department(string name) {
        departmentName = name;
        professorCount = 0;
    }

    void addProfessor(Professor* prof) {
        if (professorCount < 10) {
            professors[professorCount++] = prof;
        } else {
            cout << "Department is full, cannot add more professors!" << endl;
        }
    }

    void displayDepartmentDetails() {
        cout << "\nDepartment: " << departmentName 
             << "\nFaculty Members:" << endl;

        for (int i = 0; i < professorCount; i++) {
            professors[i]->displayDetails();
            cout << endl;
        }
    }
};

class University {
public:
    Department* departments[10];
    int departmentCount;

    University() {
        departmentCount = 0;
    }

    void addDepartment(Department* dept) {
        if (departmentCount < 10) {
            departments[departmentCount++] = dept;
        } else {
            cout << "University has reached max department capacity!" << endl;
        }
    }

    void displayUniversityDetails() {
        cout << "\n--- University Overview ---" << endl;
        for (int i = 0; i < departmentCount; i++) {
            departments[i]->displayDepartmentDetails();
        }
    }
};

int main() {
    AssistantProfessor ap("Dr. Clara", 38, 52000.0f, 4);
    AssociateProfessor asp("Dr. Miguel", 47, 63000.0f, 8);
    FullProfessor fp("Dr. Aisha", 55, 75000.0f, true);

    // Courses
    Course c1("Data Structures", &ap);
    Course c2("Quantum Mechanics", &asp);

    // Departments
    Department csDept("Computer Science");
    csDept.addProfessor(&ap);

    Department physDept("Physics");
    physDept.addProfessor(&asp);

    // University
    University uni;
    uni.addDepartment(&csDept);
    uni.addDepartment(&physDept);

    // Display all details
    uni.displayUniversityDetails();

    return 0;
}