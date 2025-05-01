#include<iostream>
using namespace std;
//定义一个玩具类，用于存储玩具的数量和价格
class toy
{
	public://公有成员，可以被外部访问
	//构造函数，初始化玩具的数量和价格
		toy(int q, int p)
		{
			quan=q;
			price=p;	
		}	
		int get_quan()
		{
			return quan;
		}
		int get_price()
		{
			return price;
		}
	private://私有成员，只能被类内部访问
		int quan,price;
} ;
int main()
{
	toy op[3][2]={//定义一个二维数组，用来存储多个玩具对象
		toy(10,20),toy(30,48),
		toy(50,68),toy(70,80),
		toy(90,16),toy(11,120),
	};
	for(int i=0;i<3;i++)//循环遍历二维数组中的每个玩具
	{
		cout<<op[i][0].get_quan()<<",";//输出第一个玩具的数量和价格
		cout<<op[i][0].get_price()<<"\n";
		cout<<op[i][1].get_quan()<<",";
		cout<<op[i][1].get_price()<<"\n";
	}
	cout<<endl;
	return 0;
}
