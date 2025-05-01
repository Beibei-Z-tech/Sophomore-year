#pragma once
#include<iostream>
#include<string>
using namespace std;
class mobliephone {
private:
	string phone_name;
	string phone_xinghao;
	double length, weight, height;
public:
	void setinfo(string n,string t,double l,double w,double h);
	void showinfo();
	void showsize();
	void call(string n);
	mobliephone(string n, string t, double l, double w, double h);
	mobliephone();
	~mobliephone();
};