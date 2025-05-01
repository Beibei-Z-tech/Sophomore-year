//#include<iostream>
//using namespace std;
//class Point {
//public:
//	int x, y;
//private:
//	Point()
//	{
//		x = 1; y = 2;
//	}
//};
//int main()
//{
//	Point cpoint;
//	cpoint.x = 2;
//	return 0;
//}

//以上代码的主要问题是 Point 类的构造函数 Point() 是私有的，这意味着它不能被外部访问。因此，在 main 函数中无法通过 Point cpoint; 
//创建 Point 类的对象。

//以下是改正后的代码
#include<iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point() {
        x = 1;
        y = 2;
    }
};

int main() {
    Point cpoint;
    cpoint.x = 2;
    return 0;
}
