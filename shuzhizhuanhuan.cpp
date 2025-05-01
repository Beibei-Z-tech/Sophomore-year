#include <iostream>
#include <string>
#include <algorithm>

std::string convertToBase(int num, int base) {
    const char digits[] = "0123456789ABCDEF";
    
    if (num < base) {
        return std::string(1, digits[num]);
    } else {

        return convertToBase(num / base, base) + digits[num % base];
    }
}

int main() {
    int decimal1 = 11;
    int base1 = 2;
    std::string binary = convertToBase(decimal1, base1);
    std::reverse(binary.begin(), binary.end()); 
    std::cout << "(" << decimal1 << ")10=(" << binary << ")2" << std::endl;

    int decimal2 = 1348;
    int base2 = 16;
    std::string hex = convertToBase(decimal2, base2);
    std::reverse(hex.begin(), hex.end()); 
    std::cout << "(" << decimal2 << ")10=(" << hex << ")" << base2 << std::endl;

    return 0;
}
