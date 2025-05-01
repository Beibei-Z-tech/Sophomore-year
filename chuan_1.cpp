#include <iostream>
using namespace std;

int BF(const char *mainStr,const char *pattern, int start){
    int mainLen = 0;//使用字符数组来储存字符串
    while (mainStr[mainLen]!='\0')++mainLen;// 计算主串长度
    int patternLen=0;
    while (pattern[patternLen]!='\0')++patternLen;// 计算子串长度
    for (int i=start;i<=mainLen-patternLen;++i){
        int j;
        for (j=0;j<patternLen;++j){
            if (mainStr[i + j]!=pattern[j]){
                break;
            }
        }
        if (j==patternLen){
            return i;
        }
    }
    return -1; 
}

int main(){
    const char *mainStr1="ababcabcacbab";
    const char *pattern1="abcac";
    int start1 = 2;
    cout<<"实例1 主串："<<mainStr1<<"子串："<<pattern1<<"起始位置："<< start1<<" 结果："<<BF(mainStr1, pattern1, start1)<<endl;

    const char *mainStr2="ababcabcacbab";
    const char *pattern2="edadc";
    int start2=1;
    cout<<"实例2 主串："<<mainStr2<<"子串："<<pattern2<<"起始位置："<<start2<<" 结果："<<BF(mainStr2, pattern2, start2)<<endl;
    return 0;
}
