//#include <iostream>
//using namespace std;
//class Student{
//public:
  //  void printStu();
//private:
  //  char name[10];
    //int age;
    //float aver;
//};
//int main()
//{
  //  Student p1,p2,p3;
    //p1.age=30;
    //.
    //.
    //.
    //return 0;
//}
//以上代码的错误是：类 Student 中的 printStu 函数没有定义体，即函数内部的内容没有被包含在花括号 {} 内。
//类 Student 中的 printStu 函数是公有的，但是它没有在类外部进行声明或定义。在 C++ 中，公有的成员函数必须在类外部进行定义，除非它被声明为内联函数。
//类 Student 中的 name 成员变量是一个字符数组，但是没有指定大小。在 C++ 中，字符数组需要指定大小，否则会导致未定义行为。
//下面是修改后的代码
#include <iostream>
using namespace std;

class Student {
public:
    void printStu() {
        cout << "Name: " << name << ", Age: " << age << ", Average: " << aver << endl;
    }
    char name[15];
    int age;
    float aver;
};

int main() {
    Student p1, p2, p3;
    p1.age = 30;
    strcpy(p1.name, "John Doe"); // 假设使用了 strcpy 函数来复制字符串
    // 给第一个对象的平均分赋值
    p1.aver = 85.5;
    // 打印第一个对象的信息
    p1.printStu();
    return 0; 
}
