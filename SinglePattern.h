#include <iostream>
using namespace std;
/*
创建一个 SingleObject 类。SingleObject 类有它的私有构造函数和本身的一个静态实例。

SingleObject 类提供了一个静态方法，供外界获取它的静态实例。SingletonPatternDemo 类使用 SingleObject 类来获取 SingleObject 对象。
*/

//饿汉式实现单例模式
class Singleton1{
private:
    static Singleton1* instance;

    Singleton1(){
        cout << "singleton1 construction." << endl;
    }; //构造函数私有化

public:
    //把编译器自动提供的拷贝构造与 = 号运算符重载移除
    Singleton1(Singleton1&)=delete;
    Singleton1& operator=(const Singleton1&)=delete;

    static Singleton1* getInstance(){
        return instance;
    }
    void showMessage(){
        cout << "Hello World1!" << endl;
    }
};

Singleton1* Singleton1::instance; //静态成员变量在类外声明并初始化

//懒汉式实现单例模式
/*
线程不安全：当有多个线程并发调用get_instance时，都认为instance==nullptr而导致创建了多个实例，违背了单例原则。
内存不安全：只有new，没有delete
*/
class Singleton2
{
private:
    static Singleton2* instance;
    Singleton2(){
        cout << "singleton2 construction." << endl;
    };

public:
    //把编译器自动提供的拷贝构造与 = 号运算符重载移除
    Singleton2(Singleton2&)=delete;
    Singleton2& operator=(const Singleton2&)=delete;

    static Singleton2* getInstance(){
        if(instance == nullptr){
            instance = new Singleton2();
        }
        return instance;
    }
    void showMessage(){
        cout << "Hello World2!" << endl;
    }
};
Singleton2* Singleton2::instance;

//局部静态变量实现懒汉式（线程安全）
class Singleton3{
private:
    Singleton3(){
        cout << "singleton3 construction." << endl;
    };
public:
    //把编译器自动提供的拷贝构造与 = 号运算符重载移除
    Singleton3(Singleton3&)=delete;
    Singleton3& operator=(const Singleton3&)=delete;

    static Singleton3* getInstance(){
        static Singleton3* instance;
        return instance;
    }
    void showMessage(){
        cout << "Hello World3!" << endl;
    }
};
