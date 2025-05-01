#include <iostream>
#include <string>

class CComplex {
private:
    double real; // 实部
    double imag; // 虚部

public:
    // 构造函数
    CComplex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 加法运算符重载
    CComplex operator+(const CComplex& other) const {
        return CComplex(real + other.real, imag + other.imag);
    }

    // 减法运算符重载
    CComplex operator-(const CComplex& other) const {
        return CComplex(real - other.real, imag - other.imag);
    }

    // 乘法运算符重载
    CComplex operator*(const CComplex& other) const {
        return CComplex(real * other.real - imag * other.imag,
                        real * other.imag + imag * other.real);
    }

    // 除法运算符重载
    CComplex operator/(const CComplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            std::cerr << "Division by zero!" << std::endl;
            return CComplex();
        }
        return CComplex((real * other.real + imag * other.imag) / denominator,
                        (imag * other.real - real * other.imag) / denominator);
    }

    // 输入运算符重载
    friend std::istream& operator>>(std::istream& is, CComplex& c) {
        std::string input;
        is >> input;
        size_t pos = input.find('+');
        if (pos == std::string::npos) {
            c.real = std::stod(input);
            c.imag = 0;
        } else {
            c.real = std::stod(input.substr(0, pos));
            c.imag = std::stod(input.substr(pos + 1, input.length() - pos - 2));
        }
        return is;
    }

    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const CComplex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        os << c.imag << "i";
        return os;
    }
};

int main() {
    CComplex c1(2, 3), c2(1, 1), result;

    std::cout << "Enter a complex number (e.g., 2+3i): ";
    std::cin >> result;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    result = c1 + c2;
    std::cout << "c1 + c2 = " << result << std::endl;

    result = c1 - c2;
    std::cout << "c1 - c2 = " << result << std::endl;

    result = c1 * c2;
    std::cout << "c1 * c2 = " << result << std::endl;

    result = c1 / c2;
    std::cout << "c1 / c2 = " << result << std::endl;

    return 0;
}
