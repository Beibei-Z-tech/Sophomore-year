#include<iostream> 
using namespace std; 
class A {
public:
	void set(int i, int j)
	{
		x = i;//设置成员变量x的值
		y = j;//设置成员变量y的值
	}
	int get_y()//成员函数，获取y的值
	{
		return y;//返回成员变量y的值
	}
private:
	int x, y;
};
class box {
	public:
		void set(int l, int w, int s, int p)
		{
			length = l;//设置成员变量length的值
			width = w;//设置成员变量width的值
			label.set(s, p);//调用lable成员的set函数，设置其x和y值
		}

		int get_area()
		{
			return length * width;
		}
		private:
			int length, width;//私有成员变量，表示盒子的长度和宽度
			A label;//私有成员，表示盒子的标签，类型为A
		};
	int main()
	{
		box b;//创建box类对象b
		b.set(4, 6, 1, 20);//调用set函数，设置盒子的长度宽度和标签的x，y值
		cout<< b.get_area() << endl;
		return 0;
	}