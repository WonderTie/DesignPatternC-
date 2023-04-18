#include <iostream>
using namespace std;

//抽象形状类
class Shape{
public:
    virtual void draw() = 0;
};
//具体形状类1
class Circle:public Shape{
public:
    void draw(){
        cout << "Shape: Circle" << endl;
    }
};
//具体形状类2
class Rectangle:public Shape{
public:
    void draw(){
        cout << "Shape: Rectangle" << endl;
    }
};
//装饰类
class ShapeDecorator{
protected:
    Shape* decoratedshape;
public:
    ShapeDecorator(Shape* decoratedShape){
        this->decoratedshape = decoratedShape;
    }
    virtual void draw(){
        decoratedshape->draw();
    }
};
//具体装饰类
class RedShapeDecorator:public ShapeDecorator{
public:
    RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}
    void draw(){
        this->decoratedshape->draw();
        setRedBorder();
    }
private:
    void setRedBorder() {
        cout << "Border Color: Red" << endl;
    }
};