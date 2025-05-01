#include<iostream>
using namespace std;

// 定义一个名为 Test 的类
class Test {
private:
	int val; // 私有成员变量，用于存储一个整数值
public:
	// 默认构造函数，当创建 Test 类对象时调用，输出 "default."
	Test()
	{
		cout << "default." << endl;
	}
	// 带参数的构造函数，用于创建 Test 类对象时提供初始值，输出 "Con."
	Test(int n)
	{
		val = n;
		cout << "Con." << endl;
	}
	// 复制构造函数，用于创建 Test 类对象的副本，输出 "Copy con."
	Test(const Test& t) 
	{
		val = t.val;
		cout << "Copy con." << endl;
	}
};

int main() {
	// 创建 Test 类对象 t1，并使用带参数的构造函数初始化，输出 "Con."
	Test t1(6);
	// 创建 Test 类对象 t2，通过复制构造函数从 t1 复制，输出 "Copy con."
	Test t2 = t1;
	// 创建 Test 类对象 t3，使用默认构造函数初始化，输出 "default."
	Test t3;
	// 通过复制构造函数将 t1 的值复制到 t3，输出 "Copy con."
	t3 = t1;
	
	return 0; 
}
