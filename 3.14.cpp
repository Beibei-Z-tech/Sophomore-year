#include<iostream>
using namespace std;
class B {
public:
	B(){}
    B(int i, int j)
{
	x = i;//初始化成员变量x
	y = j;//初始化成员变量y
}
	void printb()
	{
		cout << x << "," << y << endl;
	}
 private:
	 int x, y;// 私有成员变量x和y
};
class A{
public:
A()
{}
 A(int I , int j);
 void printa();// 成员函数，打印B类成员的值
 private:
 B c;//私有成员变量，类型为B
};
 A::A(int i, int j) : c(i, j)
 {}
 //A类的成员函数printa定义
 void A::printa()
 {
	 c.printb();//调用B类的printb成员函数来打印私有成员c的值
 }
 int main()
 {
	 A a(7, 8);// 创建A类对象a，并使用7和8作为参数调用构造函数
	 a.printa();// 调用a的printa成员函数，打印对象a中B类成员c的值
	 return 0;
 }