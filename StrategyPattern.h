#include <iostream>
using namespace std;

class Strategy{
public:
    virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd:public Strategy{
public:
    int doOperation(int num1, int num2){
        return num1 + num2;
    }
};

class OperationSub:public Strategy{
public:
    int doOperation(int num1, int num2){
        return num1 - num2;
    }
};

class OperationMultiply:public Strategy{
public:
    int doOperation(int num1, int num2){
        return num1 * num2;
    }
};

class Contex{
private:
    Strategy* strategy;
public:
    Contex(Strategy* strategy){
        this->strategy = strategy;
    }
    int excuteStrategy(int num1, int num2){
        return strategy->doOperation(num1,num2);
    }
};