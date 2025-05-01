#include<iostream>
using namespace std;
class Sample{
	public:
		Sample(int i,int j)//构造函数，用于创建对象时初始化成员变量
		{
			x=i;//初始化成员变量x
			y=j;
		}
		void disp()//成员函数，输出“disp1”
		{
			cout<<"disp1"<<endl;//输出“disp1”并换行
		}
		void disp() const//成员函数，输出“disp2”，const表示此函数不会修改对象状态
		{
			cout<<"disp2"<<endl;
		}
		private:
			int x,y;//私有成员变量x和y
};
int main()
{
	const Sample a(1,2);//创建一个const类型的Sample对象a，初始化x为1，y为2
	a.disp();//调用对象a的disp函数
	return 0;
}