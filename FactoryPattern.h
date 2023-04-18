#include <iostream>
using namespace std;
/*
创建一个 Shape 接口和实现 Shape 接口的实体类。下一步是定义工厂类 ShapeFactory。

FactoryPatternDemo 类使用 ShapeFactory 来获取 Shape 对象。它将向 ShapeFactory 传递信息（CIRCLE / RECTANGLE / SQUARE），以便获取它所需对象的类型。
*/

// 抽象产品类
class Shape
{
public:
    virtual void draw() = 0;
};
// 具体产品类 A
class Rectangle: public Shape{
public:
    void draw(){
        cout << "Inside Rectangle::draw() method." << endl;
    }
};
// 具体产品类 B
class Square: public Shape{
public:
    void draw(){
        cout << "Inside Square::draw() method." << endl;
    }
};
// 具体产品类 C
class Circle: public Shape{
public:
    void draw(){
        cout << "Inside Circle::draw() method." << endl;
    }
};

//工厂类
class ShapeFactory{
public:
    Shape* getShapeProduct(string shapetype){
        if(shapetype.size() == 0){
            return nullptr;
        }
        if(shapetype == "circle"){
            return new Circle();
        }
        else if(shapetype == "rectangle"){
            return new Rectangle();
        }
        else if(shapetype == "square"){
            return new Square();
        }
        return nullptr;
    }
};












