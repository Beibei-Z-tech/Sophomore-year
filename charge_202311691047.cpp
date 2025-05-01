#include <iostream>
using namespace std;

class CurrencyConverter{
    public:
        virtual ~CurrencyConverter(){}
        virtual double convert(double amount) const = 0;    
};
class USDConverter: public CurrencyConverter{
private:
    const double exchangeRate=711.49;
public:
    double convert(double amount) const override{

        return amount*exchangeRate/100;
    }
};
class EURConverter: public CurrencyConverter{
private:
    const double exchangeRate=765.55;
public:
    double convert(double amount) const override{
        return amount*exchangeRate/100;
    }
};
class GBPConverter: public CurrencyConverter{
private:
    const double exchangeRate=907.58;
public:
    double convert(double amount) const override{
        return amount*exchangeRate/100;
    }
};
class JPYConverter: public CurrencyConverter{
private:
    const double exchangeRate=4.5502;
public:
    double convert(double amount) const override{
        return amount*exchangeRate/100;
    }
}; 
class CADConverter: public CurrencyConverter{
private:
    const double exchangeRate=521.32;
public:
    double convert(double amount) const override{
        return amount*exchangeRate/100;
    }
};
class AUDConverter: public CurrencyConverter{
private:
    const double exchangeRate=474.05;
public:
    double convert(double amount) const override{
        return amount*exchangeRate/100;
    }
};
int main(){
    double amountToConvert=500;
    CurrencyConverter* converters[5];
    converters[0] = new USDConverter();
    converters[1] = new EURConverter();
    converters[2] = new GBPConverter();
    converters[3] = new JPYConverter();
    converters[4] = new CADConverter();
    for (int i = 0; i < 5; ++i) {
        std::cout << amountToConvert << " USD is equivalent to "
                    << converters[i]->convert(amountToConvert) << " CNY." << std::endl;
    }

    // 清理内存
    for (int i = 0; i < 5; ++i) {
        delete converters[i];
    }

    return 0;
}


