#include <iostream>
#include <cmath>

// 定义常量PI
const double PI = 3.14159265358979323846;

// 抽象基类Container
class Container {
public:
    // 虚析构函数，确保删除指向派生类的基类指针时能正确调用派生类的析构函数
    virtual ~Container() {}

    // 虚函数计算体积
    virtual double volume() = 0;

    // 虚函数计算表面积，可选实现
    // virtual double surfaceArea() = 0;
};

// 球体类Sphere
class Sphere : public Container {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    // 计算球体体积的函数
    double volume() override {
        return (4.0 / 3) * PI * std::pow(radius, 3);
    }

    // 可选：计算球体表面积的函数
    // double surfaceArea() override {
    //     return 4 * PI * std::pow(radius, 2);
    // }
};

// 圆柱体类Cylinder
class Cylinder : public Container {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    // 计算圆柱体体积的函数
    double volume() override {
        return PI * std::pow(radius, 2) * height;
    }

    // 可选：计算圆柱体表面积的函数
    // double surfaceArea() override {
    //     return 2 * PI * radius * (radius + height);
    // }
};

// 正方体类Cube
class Cube : public Container {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    // 计算正方体体积的函数
    double volume() override {
        return std::pow(side, 3);
    }

    // 可选：计算正方体表面积的函数
    // double surfaceArea() override {
    //     return 6 * std::pow(side, 2);
    // }
};

int main() {
    // 创建不同形状的指针数组
    Container* shapes[3] = {
        new Sphere(5),
        new Cylinder(3, 10),
        new Cube(4)
    };

    // 循环遍历指针数组，计算并打印每个形状的体积
    for (auto shape : shapes) {
        std::cout << "The volume is: " << shape->volume() << std::endl;
        // 可选：打印表面积
        // std::cout << "The surface area is: " << shape->surfaceArea() << std::endl;
        delete shape; // 清理内存
    }

    return 0;
}
