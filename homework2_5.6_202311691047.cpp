#include <iostream>
#include <vector>
#include <string>

// 基类 Person
class Person {
protected:
    std::string name;
    int age;

public:
    Person() {}

    Person(const std::string& name, int age) : name(name), age(age) {}

    virtual void showPerson() {
        std::cout << "姓名：" << name << "，年龄：" << age << std::endl;
    }

    virtual ~Person() {}
};

// 学生类 Student
class Student : public Person {
private:
    std::string studentID;
    int grade;
    std::string classID;
    std::string major;

public:
    Student() {}

    Student(const std::string& name, int age, const std::string& studentID, int grade, const std::string& classID, const std::string& major)
        : Person(name, age), studentID(studentID), grade(grade), classID(classID), major(major) {}

    void setStudentID(const std::string& studentID) {
        this->studentID = studentID;
    }

    void setGrade(int grade) {
        this->grade = grade;
    }

    void setClassID(const std::string& classID) {
        this->classID = classID;
    }

    void setMajor(const std::string& major) {
        this->major = major;
    }

    std::string getStudentID() const {
        return studentID;
    }

    int getGrade() const {
        return grade;
    }

    std::string getClassID() const {
        return classID;
    }

    std::string getMajor() const {
        return major;
    }

    void showStudent() {
        std::cout << "学生信息：" << std::endl;
        showPerson();
        std::cout << "学号：" << studentID << "，年级：" << grade << "，班级：" << classID << "，专业：" << major << std::endl;
    }
};

// 教师类 Teacher
class Teacher : public Person {
private:
    std::string department;
    std::string title;

public:
    Teacher() {}

    Teacher(const std::string& name, int age, const std::string& department, const std::string& title)
        : Person(name, age), department(department), title(title) {}

    void setDepartment(const std::string& department) {
        this->department = department;
    }

    void setTitle(const std::string& title) {
        this->title = title;
    }

    std::string getDepartment() const {
        return department;
    }

    std::string getTitle() const {
        return title;
    }

    void showTeacher() {
        std::cout << "教师信息：" << std::endl;
        showPerson();
        std::cout << "部门：" << department << "，职称：" << title << std::endl;
    }
};

// 主函数
int main() {
    std::vector<Student> students;
    std::vector<Teacher> teachers;
    std::vector<std::pair<Student, Teacher> > mentorStudents;

    // 创建学生和教师实例
    Student student1("张三", 20, "S1001", 1, "一班", "计算机科学");
    Student student2("李四", 21, "S1002", 2, "二班", "软件工程");
    Teacher teacher1("王老师", 40, "计算机学院", "副教授");
    Teacher teacher2("赵老师", 45, "软件学院", "教授");

    // 添加到相应的列表
    students.push_back(student1);
    students.push_back(student2);
    teachers.push_back(teacher1);
    teachers.push_back(teacher2);
    }
