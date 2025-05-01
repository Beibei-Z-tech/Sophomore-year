#include<iostream> 
using namespace std;

// 定义一个名为 A 的类
class A {
	int a, b; // 私有成员变量 a 和 b
public:
	// 默认构造函数，当创建 A 类对象时调用，初始化 a 和 b 为0
	A()
	{
		a = 0;
		b = 0;
		cout << "Default constructor called.\n";
	}
	// 带参数的构造函数，用于创建 A 类对象时提供初始值
	A(int i, int j)
	{
		a = i;
		b = j;
		cout << "Constructor: a=" << a << ", b=" << b << endl;
	}
};

int main()
{
	// 创建 A 类对象数组 a，长度为3，默认构造函数将被调用3次
	A a[3];
	
	// 创建 A 类对象数组 b，长度为3，使用带参数的构造函数进行初始化
	// 第一个元素初始化为 a=1, b=2，第二个元素初始化为 a=3, b=4，第三个元素初始化为 a=5, b=6
	A b[3] = { A(1, 2), A(3, 4), A(5, 6) };
	
	return 0; 
}
