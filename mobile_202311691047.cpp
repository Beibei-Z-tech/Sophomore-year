#pragma once
#include<iostream>
#include<string>
using namespace std;
class CMobilePhone;
class CScreen
{
public:
    CScreen (double width =40.0, double length= 66.0,double
    d=600,string t="OLED",string f="zhang bei bei",
    string m ="iPhone 14"):wth(width),len(length),dpi(d),type(t),factory(f),matchtype(m)
    {

    }
    void showParameter();
    bool checkType(CMobilePhone *p);

private:
    const double len;
    const double wth;
    const double dpi;
    const string type;
    const string factory;
    const string matchtype;

};
int main(){
    CMobilePhone A("iPhone 14",8.19,152.7,69.9,152.7,69.9,(2400*1080));
    cout<<"手机的信息如下:"<<endl;
    A.showParameter():
    Person XqWang("王小强",22,1,&A);
    cout<<"用户信息"<<endl;
    XqWang.whoareyou();
    cout<<"小强想要给王叔叔打电话～"<<endl;
    XqWang.callsomeone(&UncleWang);
    cout<<"---------------------------"<<endl;
    CMobilePhone B("iphone 13",8.0,152.7,69.9,152.7,69.9,(3600*1080)); 
    cout<<"手机的信息如下:"<<endl;
    B.showParameter():
    Person UncleWang("王叔叔",&B);
    cout<<"用户信息"<<endl;
    uncleWang.whoareyou();
    cout<<"王叔叔想给小强打电话"<<endl;
    
}