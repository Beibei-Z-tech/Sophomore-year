#include"mobliephone.h"
void mobliephone::setinfo(string n, string t, double l, double w, double h) {
	phone_name = n;
	phone_xinghao = t;
	length = l;
	weight = w;
	height = h;

}
void mobliephone::showinfo() {
	cout << "iphone" << phone_name << endl << "iphone 14" << phone_xinghao << endl;
};
void mobliephone::showsize() {
	cout << "15" << length <<"mm" << " 75" << weight <<"g" << " 7" << height<<"mm" << endl;
};
void mobliephone::call(string n) {
	cout << "mom" << n << endl;
}
mobliephone::mobliephone(string n, string t, double l, double w, double h) {
	phone_name = n;
	phone_xinghao = t;
	length = l;
	weight = w;
	height = h;
}
mobliephone::mobliephone() {}
mobliephone::~mobliephone() {
	cout << "" << endl;
}
int main() {
	cout << "call whom" << endl;
	mobliephone phoneA("zbb", "K40", 160, 76.4, 7.4);
	phoneA.showinfo();
	phoneA.showsize();
	cout << "" << endl;
	mobliephone *pA=new mobliephone("zbb phone2", "K40", 160, 76.4, 7.4);
	pA->showinfo();
	pA->showsize();
	delete pA;
	pA = NULL;
	cout << "" << endl;
	mobliephone phoneB;
	phoneB.setinfo("zbb phone3", "K40", 160, 76.4, 7.4);
	phoneB.showinfo();
	phoneB.showsize();
	cout << "" << endl;
	mobliephone* pB = new mobliephone;
	pB->setinfo("zbb phone4", "K40", 160, 76.4, 7.4);
	pB->showinfo();
	pB->showsize();
	delete pB;
	pB = NULL;
	return 0;
}