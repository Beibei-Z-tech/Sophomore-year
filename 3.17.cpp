#include<iostream>
using namespace std;
class R {
public:
	R(int r1, int r2)
	{
		R1 = r1;
		R2 = r2;
	}
	void print();//非const成员函数，可以修改对象状态
	void print()  const;//const成员函数，不能修改对象状态
private:
	int R1, R2;
};
//const成员函数print的定义
void R::print()
{
	cout << R1 << "," << R2 << endl;
}
void R::print()  const
{
	cout << R1 << "," << R2 << endl;
}
int main()
{
	R a(6, 8);//创建一个R类型的对象a，初始化R1为6，R2为8
	const R b(56, 88);//创建一个const类型的R对象b，初始化R1为56，R2为88
	b.print();//调用对象b的print函数
	return 0;
}