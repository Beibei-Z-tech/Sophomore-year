//编程1：有1,2,3,4个数字，能组成多少个互不相同的无重复数字的三位数？都是多少？
#include<iostream>      //在C++文件中这一行是编译预处理命令
using namespace std;    //这是针对命令空间std的指令
int main(){
	int i,j,k;
	cout<<endl;        //在C++中的输出是cout<<;且在C++中的换行操作符是endl
	for(i=1;i<5;i++){  //循环这里同C语言
		for(j=1;j<5;j++){
			for(k=1;k<5;k++){
				if(i!=k&&i!=j&&k!=j)
				cout<<endl<<i<<j<<k; //这里将输出改成C++的输出即cout<<
			}
		}
	}
	return 0;
}

