#include<iostream>
using namespace std;

// 定义一个名为 M 的类
class M{
    int x,y; // 私有成员变量 x 和 y，用于存储两个整数
  public:
    // 默认构造函数，初始化 x 和 y 为 0
    M()
    { 
        x = y = 0;
    }
    // 带参数的构造函数，初始化 x 和 y 为传入的参数 i 和 j
    M(int i, int j)
    { 
        x = i;
        y = j;
    }
    // 成员函数 copy，用于复制一个 M 类型的指针指向的对象
    void copy(M* m)
    { 
        x = m->x; // 复制指针指向对象的 x 成员
        y = m->y; // 复制指针指向对象的 y 成员
    }
    // 成员函数 setxy，用于设置 x 和 y 的值
    void setxy(int i, int j)
    { 
        x = i;
        y = j;
    }
    // 成员函数 print，用于输出 x 和 y 的值
    void print()
    { 
        cout << x << "," << y << endl;
    }
};

// 非成员函数 fun，接收一个 M 类型的对象和一个 M 类型的指针
void fun(M m1, M* m2)
{
    m1.setxy(12, 15); // 设置 m1 的 x 和 y 值为 12 和 15
    m2->setxy(22, 25); // 设置 m2 指向的对象的 x 和 y 值为 22 和 25
}

int main()
{
    // 创建 M 类的对象 p，并使用带参数的构造函数初始化，x 为 5，y 为 7
    M p(5, 7);
    // 创建 M 类的对象 q
    M q;
    // 调用 q 的 copy 函数，将 p 的值复制到 q，此时 q 的 x 为 5，y 为 7
    q.copy(&p);
    // 调用 fun 函数，将 p 的 x 和 y 设置为 12 和 15，将 q 的 x 和 y 设置为 22 和 25
    fun(p, &q);
    // 输出 p 的 x 和 y 值，应为 12 和 15
    p.print();
    // 输出 q 的 x 和 y 值，应为 22 和 25
    q.print();
    
    return 0; 
}
