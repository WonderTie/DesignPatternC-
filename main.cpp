#include <iostream>
// #include "FactoryPattern.h"
#include "SinglePattern.h"
#include "BuilderPattern.h"
#include "AdapterPattern.h"
#include "DecoratorPattern.h"
#include "ProxyPattern.h"
#include "ObserverPattern.h"
#include "TemplatePattern.h"
#include  "StrategyPattern.h"
using namespace std;

int main(){
    cout << endl;
    // //工厂模式演示
    // ShapeFactory* sf = new ShapeFactory();
    // Shape* shape1 = sf->getShapeProduct("circle");
    // shape1->draw();
    // Shape* shape2 = sf->getShapeProduct("rectangle");
    // shape2->draw();
    // Shape* shape3 = sf->getShapeProduct("square");
    // shape3->draw();

    //单例模式演示
    Singleton1* instance1 = Singleton1::getInstance();
    instance1->showMessage();
    Singleton2* instance2 = Singleton2::getInstance();
    instance2->showMessage();
    Singleton3* instance3 = Singleton3::getInstance();
    instance3->showMessage();
    

    //建造者模式演示
    MealBuilder* mealbuilder = new MealBuilder();
    Meal* vegMeal = mealbuilder->prepareVegMeal();
    cout << "Veg Meal:" << endl;
    vegMeal->showItems();
    cout << "Total Cost:" << vegMeal->getCost() << endl;
    Meal* nonvegMeal = mealbuilder->prepareNonVegMeal();
    cout << "NonVeg Meal" << endl;
    nonvegMeal->showItems();
    cout << "Total Cost:" << nonvegMeal->getCost() << endl;

    //适配器模式演示
    AudioPlayer* audioPlayer = new AudioPlayer();
    audioPlayer->play("mp3", "beyond the horizon.mp3");
    audioPlayer->play("vlc", "far far away.vlc");
    audioPlayer->play("mp4", "alone.mp4");
    audioPlayer->play("avi", "mind me.avi");

    //装饰器模式演示
    Shape* circle = new Circle();
    ShapeDecorator* redCircle = new RedShapeDecorator(new Circle());
    ShapeDecorator* redRectangle = new RedShapeDecorator(new Rectangle());
    cout << "Circle with normal border:" << endl;
    circle->draw();
    cout << "Circle of red border:" << endl;
    redCircle->draw();
    cout << "Rectangle of red border:" << endl;
    redRectangle->draw();

    //代理模式演示
    Image* image = new ProxyImage("test.jpg");
    //图像从磁盘加载
    image->display();
    //图像不需要从磁盘加载
    image->display();

    //观察者模式演示
    Subject* subject = new Subject();
    new OctalObserver(subject);
    new HexaObserver(subject);
    cout << "First state change: 15" << endl;
    subject->setState(15);
    cout << "Second state change: 10" << endl;
    subject->setState(10);

    //模板模式演示
    Game* game = new Cricket();
    game->paly();
    cout << endl;
    game = new Football();
    game->paly();

    //策略模式演示
    Contex* contex = new Contex(new OperationAdd());
    cout << "10+5=" << contex->excuteStrategy(10,5) << endl;
    contex = new Contex(new OperationSub());
    cout << "10-5=" << contex->excuteStrategy(10,5) << endl;
    contex = new Contex(new OperationMultiply());
    cout << "10*5=" << contex->excuteStrategy(10,5) << endl;

}
