#include<iostream> 
using namespace std; 

// 定义一个名为 N 的类
class N { 
    private: 
      int A; // 私有成员变量 A，用于存储一个整数值
      static int B; // 静态私有成员变量 B，用于存储一个整数值，静态成员在类外部也可以访问
    public: 
      // 构造函数，接收一个整数参数 a，用于初始化成员变量 A，并更新静态成员变量 B
      N (int a) 
      { 
          A = a; 
          B += a; 
      } 
      // 静态成员函数，接收一个 N 类型的对象参数 m，输出 m 的成员变量 A 和静态成员变量 B
      static void f1(N m)
      { 
          cout<<"A="<<m.A<<endl; // 输出 m 的成员变量 A 的值
          cout<<"B="<<B<<endl;   // 输出静态成员变量 B 的值
      } 
}; 

// 静态成员变量的定义和初始化，B 的初始值为0
int N::B=0;

int main() 
{ 
    // 创建 N 类的对象 P，并使用构造函数初始化，输出 "A=5" 和更新 B 的值
    N P(5); 
    // 创建 N 类的对象 Q，并使用构造函数初始化，输出 "A=9" 和更新 B 的值
    N Q(9); 
    
    // 调用静态成员函数 f1，传递 N 对象 P 作为参数，输出 P 的成员变量 A 和静态成员变量 B
    N::f1(P); 
    // 调用静态成员函数 f1，传递 N 对象 Q 作为参数，输出 Q 的成员变量 A 和静态成员变量 B
    N::f1(Q); 
    return 0; 
}
