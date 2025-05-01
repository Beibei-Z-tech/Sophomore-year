//#include<iostream>
//using namespace std;
//class Student {
//	int sno;
//	int age;
//	void printStu();
//	void setSno(int d);
//};
//void printStu() {
//	cout << "\nSno is" << sno << ",";
//	cout << "age is" << age << "."<<endl;
//}
//void setSno(int s) {
//	sno = s;
//}
//void setAge(int a) {
//	age = a;
//}
//int main() {
//	Student lin;
//	lin.setSno(20021);
//	lin.setAge(20);
//	lin.printStu();
//}
//指出以上程序错误

//这个程序有几个问题：

//printStu 函数和 setSno、setAge 函数定义在类 Student 的外部，这意味着它们不是 Student 类的成员函数。在 C++ 中，如果要在类外部定义成员函数，需要使用 :: 运算符来指明它们属于哪个类。
//函数 printStu、setSno 和 setAge 没有被声明为 Student 类的成员函数，所以它们不能直接使用 sno 和 age 这两个私有成员变量。
//在 main 函数中创建 Student 类型的对象 lin 时，没有使用 Student:: 来指定 printStu 函数属于 Student 类。


//以下是修正后的代码
#include<iostream>
using namespace std;

class Student {
    int sno;
    int age;

public:
    void setSno(int d);
    void setAge(int a);
    void printStu();
};

void Student::setSno(int s) {
    sno = s;
}

void Student::setAge(int a) {
    age = a;
}

void Student::printStu() {
    cout << "\nSno is " << sno << ",";
    cout << "age is " << age << "." << endl;
}

int main() {
    Student lin;
    lin.setSno(20021);
    lin.setAge(20);
    lin.printStu();

    return 0;
}
