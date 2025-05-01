#include<iostream>
using namespace std;

// 定义一个名为 test 的类
class test
{
public:
	// 构造函数，用于创建对象时初始化成员变量
	test();
	// 析构函数，用于对象销毁时释放资源，这里为空，不做特殊处理
	~test() {};
private:
	// 私有成员变量 i，它被初始化但未在类外部直接访问
	int i;
};

// 构造函数的实现，当创建 test 类的对象时调用
test::test()
{
	i = 25; // 将成员变量 i 初始化为 25
	for (int ctr = 0; ctr < 10; ctr++)
	{
		cout << "Counting at " << ctr << "\n"; 
	}
}

// 创建 test 类的对象 anObject
test anObject;

int main()
{
	return 0; 
}
