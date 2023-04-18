#include <iostream>
#include <vector>
using namespace std;

class Subject;

//抽象观察者类
class Observer{
protected:
    Subject* subject; //观察对象
public:
    virtual void update() = 0;
};

//被观察者类
class Subject{
private:
    vector<Observer*> observers;
    int state;
public:
    int getState(){
        return state;
    }
    void setState(int s){
        state = s;
        notifyAllObservers();
    }
    void attach(Observer* observer){
        observers.push_back(observer);
    }
    void notifyAllObservers(){
        for(Observer* obs : observers){
            obs->update();
        }
    }

};

//具体观察者类1
class OctalObserver:public Observer{
public:
    OctalObserver(Subject* subject){
        this->subject = subject;
        this->subject->attach(this);
    }
    void update(){
        cout << "Octal String:" << oct << (subject->getState()) << endl;
    }
};
//具体观察者类2
class HexaObserver:public Observer{
public:
    HexaObserver(Subject* subject){
        this->subject = subject;
        this->subject->attach(this);
    }
    void update(){
        cout << "Hex String:" << hex << (subject->getState()) << endl;
    }
};
