#include <iostream>
#include <string>
class MobilePhone;
class Screen {
public:
    std::string size;
    std::string resolution;
    std::string technologyType;
    std::string manufacturer;
    std::string matchingModel;

    Screen(std::string size, std::string resolution, std::string technologyType, std::string manufacturer, std::string matchingModel)
        : size(size), resolution(resolution), technologyType(technologyType), manufacturer(manufacturer), matchingModel(matchingModel) {}

    void displayParameters() {
        std::cout << "Screen Parameters:" << std::endl;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Resolution: " << resolution << std::endl;
        std::cout << "Technology Type: " << technologyType << std::endl;
        std::cout << "Manufacturer: " << manufacturer << std::endl;
    }

    bool checkModelMatch(MobilePhone* phone) {
        return phone->model == matchingModel;
    }
};

class MobilePhone {
public:
    std::string model;
    Screen* screen;

    MobilePhone(std::string model, Screen* screen) : model(model), screen(screen) {}

    void showParameter() {
        std::cout << "Mobile Phone Parameters:" << std::endl;
        std::cout << "Model: " << model << std::endl;
        screen->displayParameters();
    }
};

class Person {
public:
    std::string name;
    int age;
    bool gender; // true for male, false for female
    MobilePhone* myPhone;

    Person(std::string name, int age, bool gender) : name(name), age(age), gender(gender), myPhone(nullptr) {}

    std::string whoareyou() {
        return "Name: " + name + ", Age: " + std::to_string(age) + ", Gender: " + (gender ? "Male" : "Female");
    }

    void callsomeone(std::string name) {
        if (myPhone) {
            std::cout << this->name << " is calling " << name << " using mobile phone." << std::endl;
        } else {
            std::cout << "I am poor and have no mobile phone." << std::endl;
        }
    }

    void receiveCall(std::string callerName) {
        std::cout << name << " is receiving a call from " << callerName << std::endl;
    }

    void givePhone(MobilePhone* phone) {
        myPhone = phone;
    }
};

int main() {
    // 创建屏幕A
    Screen* screenA = new Screen("6.5 inches", "2400*1080", "LTPS LCD", "Huawei", "Model A");

    // 创建手机A
    MobilePhone* phoneA = new MobilePhone("Model A", screenA);

    // 创建王小强，给他手机A
    Person* wangXiaoQiang = new Person("Wang XiaoQiang", 25, true);
    wangXiaoQiang->givePhone(phoneA);

    // 创建王叔叔，他没有手机
    Person* wangShuShu = new Person("Wang ShuShu", 50, true);

    // 王小强给王叔叔打电话
    wangXiaoQiang->callsomeone(wangShuShu->name);

    // 王小强把手机A给王叔叔
    wangShuShu->givePhone(phoneA);

    // 创建屏幕B
    Screen* screenB = new Screen("6.0 inches", "1080*2160", "OLED", "Huawei", "Model B");

    // 创建手机B
    MobilePhone* phoneB = new MobilePhone("Model B", screenB);

    // 给王小强手机B
    wangXiaoQiang->givePhone(phoneB);

    // 王小强给王叔叔打电话
    wangXiaoQiang->callsomeone(wangShuShu->name);

    // 王叔叔给王小强打电话
    wangShuShu->callsomeone(wangXiaoQiang->name);

    // 清理内存
    delete wangXiaoQiang;
    delete wangShuShu;
    delete phoneA;
    delete phoneB;
    delete screenA;
    delete screenB;

    return 0;
}
