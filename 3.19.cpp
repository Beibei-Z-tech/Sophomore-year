//【3.19】
# include<iostream>
using namespace std;
class example
{public://公有成员，可以被外部访问
    example (int n)//构造函数，初始化类的一个新实例，并打印“constructing”
    {i=n;
      cout<<"Constructing\n";
      }
      ~ example ()//析构函数，当对象被销毁时调用函数，并打印“Destructing”
    {cout <<"Destructing\n";
    }
      int get_i()//公有成员函数，并获取私有变量i的值
      {    return i;
      }
  private://私有成员，存储一个整数值
  int i;//私有变量，存储类的实例变量
} ;
int sqr_it (example o)//友元函数，不是example类的成员函数，但可以访问类的私有成员
{ return o.get_i () * o. get_i();
}
int main ( )
{ example x (10);//在main函数中创建example类的实例x，参数为10
  cout<<x.get_i() <<endl;
  cout<<sqr_it(x)<< endl;//调用sqr_it函数并输出返回值
  return 0;
}