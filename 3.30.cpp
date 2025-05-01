#include<iostream>
using namespace std;

class counter {
public:
    counter(int number) {
        value = number;
    }

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getvalue() const {
        return value;
    }

    int print() const {
        cout << "Current value: " << value << endl;
        return value;
    }

private:
    int value;
};
//以下是设计的main函数
int main() {
    counter count(0); 

    cout << "Initial value: " << count.getvalue() << endl; 
    count.print(); 

    count.increment(); 
    cout << "After increment: " << count.getvalue() << endl; 
    count.print(); 

    count.decrement(); 
    cout << "After decrement: " << count.getvalue() << endl;
    count.print();

    return 0;
}
