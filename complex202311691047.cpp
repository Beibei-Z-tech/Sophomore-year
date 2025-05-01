#include <iostream>

class Complex {
private:
    double real; 
    double imag; 

public:

    Complex(double x, double y) : real(x), imag(y) {}

    double GetReal() const {
        return real;
    }

    double GetImag() const {
        return imag;
    }

    Complex Add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex Sub(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
};

int main() {

    double x, y;
    std::cout << "请输入复数的实部: ";
    std::cin >> x;
    std::cout << "请输入复数的虚部: ";
    std::cin >> y;

    Complex c(x, y);

    std::cout << "复数c的实部是: " << c.GetReal() << std::endl;
    std::cout << "复数c的虚部是: " << c.GetImag() << std::endl;

    std::cout << "请输入另一个复数的实部: ";
    std::cin >> x;
    std::cout << "请输入另一个复数的虚部: ";
    std::cin >> y;

    Complex c2(x, y);

    std::cout << "复数c2的实部是: " << c2.GetReal() << std::endl;
    std::cout << "复数c2的虚部是: " << c2.GetImag() << std::endl;

    Complex sum = c.Add(c2);
    std::cout << "复数c和c2的和是: " << sum.GetReal() << " + " << sum.GetImag() << "i" << std::endl;

    Complex diff = c.Sub(c2);
    std::cout << "复数c和c2的差是: " << diff.GetReal() << " + " << diff.GetImag() << "i" << std::endl;

    return 0;
}

