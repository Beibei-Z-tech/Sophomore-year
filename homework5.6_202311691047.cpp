#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string gender;
    int age;

public:

    Person(string n, string g, int a) : name(n), gender(g), age(a) {}

    void setPerson(string n, string g, int a) {
        name = n;
        gender = g;
        age = a;
    }

    void showPerson() {
        cout << "姓名：" << name << "\t性别:" << gender << "\t年龄:" << age << endl;
    }
};

class Student : public Person {
private:
    string studentId;
    string grade;
    string className;
    string major;

public:

    Student(string n, string g, int a, string id, string gr, string cl, string m)
        : Person(n, g, a), studentId(id), grade(gr), className(cl), major(m) {}

    void setStudent(string id, string gr, string cl, string m) {
        studentId = id;
        grade = gr;
        className = cl;
        major = m;
    }

    void showStudent() {
        Person::showPerson();
        cout << "学号：" << studentId << "\t年级:" << grade << "\t班级:" << className << "\t专业:" << major << endl;
    }
};

class Teacher : public Person {
private:
    string department;
    string title;

public:

    Teacher(string n, string g, int a, string dept, string t)
        : Person(n, g, a), department(dept), title(t) {}

    void setTeacher(string dept, string t) {
        department = dept;
        title = t;
    }

    void showTeacher() {
        Person::showPerson();
        cout << "部门：" << department << "\t职称:" << title << endl;
    }
};

int main() {

    Student student("小明", "男", 18, "202302", "大一", "计算机2班", "计算机科学与技术");
    Teacher teacher("李老师", "男", 30, "计算机学院", "教授");

    student.showStudent();
    teacher.showTeacher();

    return 0;
}
