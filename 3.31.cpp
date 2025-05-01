#include<iostream>
using namespace std;

class Date {
public:
    void printDate() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void setDay(int d) {
        if (d >= 1 && d <= 31) {
            day = d;
        } else {
            cout << "Invalid day. Please enter a value between 1 and 31." << endl;
        }
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            cout << "Invalid month. Please enter a value between 1 and 12." << endl;
        }
    }

    void setYear(int y) {
        year = y;
    }

private:
    int day, month, year;
};
//以下是设计的mainhanshu来测试代码
int main() {
    Date testDay;
    testDay.setDay(5);
    testDay.setMonth(10);
    testDay.setYear(2003);
    testDay.printDate();

    return 0;
}
