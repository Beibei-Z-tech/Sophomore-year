#include<iostream>
using namespace std; 
class aClass //定义一个名为aclass的类
{public://构造函数，当创建类的新实例时调用
	aClass()
	{
		total++;//静态成员total自增1，表示实例数量增加
	}
	~aClass()//析构函数，当删除类实例时调用
	{
		total--;//静态成员total自减1，表示实例数量减少
	}
	int gettotal()//公有成员函数，获取静态成员total的值
	{
		return total;
	}

private://私有静态成员，用于跟踪创建的aclass实例的数量
	static int total; //静态成员total，所有实例共享这个变量
};
int aClass::total = 0;//初始化静态成员total，初始值为0
int main()
{
	aClass o1, o2, o3;//在main函数中创建三个class的实例o1,o2,o3
	cout << o1.gettotal() << "obiects in existence\n";//输出实例o1中静态成员total的值，即当前创建的实例数量
	aClass* p;
	p = new aClass;//使用关键字new分配内存
	if (!p)//检查分配是否成功
	{
		cout << "Allocation error\n";
		return 1;
	}
	cout << o1.gettotal();
	cout << "objects in existence after allocation\n";
	delete p;//使用delete关键字释放内存
	cout << o1.gettotal();
	cout << "objects in existence after deletion\n";
	return 0;
}