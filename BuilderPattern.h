#include <iostream>
#include <vector>
using namespace std;
/*
假设一个快餐店的商业案例，其中，一个典型的套餐可以是一个汉堡（Burger）和一杯冷饮（Cold drink）。汉堡（Burger）可以是素食汉堡（Veg Burger）或鸡肉汉堡（Chicken Burger），它们是包在纸盒中。冷饮（Cold drink）可以是可口可乐（coke）或百事可乐（pepsi），它们是装在瓶子中。

我们将创建一个表示食物条目（比如汉堡和冷饮）的 Item 接口和实现 Item 接口的实体类，以及一个表示食物包装的 Packing 接口和实现 Packing 接口的实体类，汉堡是包在纸盒中，冷饮是装在瓶子中。

然后我们创建一个 Meal 类，带有 Item 的 ArrayList 和一个通过结合 Item 来创建不同类型的 Meal 对象的 MealBuilder。BuilderPatternDemo 类使用 MealBuilder 来创建一个 Meal。
*/
//包装类
class Packing{
public:
    virtual string pack()=0;
};
//物品类
class Item{
public:
    virtual string name()=0;
    virtual float price()=0;
    virtual Packing * packing()=0;    

};
//具体包装类 Wrapper
class Wrapper:public Packing{
public:
    string pack(){
        return "Wrapper";
    }
};
//具体包装类 Bottle
class Bottle:public Packing{
public:
    string pack(){
        return "Bottle";
    }
};
//抽象汉堡类
class Burger:public Item{
public:
    Packing* packing(){
        return new Wrapper();
    }
    virtual float price()=0;
};
//抽象冷饮类
class ColdDrink:public Item{
public:
    Packing* packing(){
        return new Bottle();
    }
    virtual float price()=0;
};
//具体汉堡类1
class ChickenBurger:public Burger{
public:
    float price(){
        return 25.0f;
    }
    string name(){
        return "ChickenBurger";
    }
};
//具体汉堡类2
class VegBurger:public Burger{
public:
    float price(){
        return 15.0f;
    }
    string name(){
        return "VegBurger";
    }
};
//具体冷饮类1
class Coke:public ColdDrink{
public:
    float price(){
        return 30.0f;
    }
    string name(){
        return "Coke";
    }
};
//具体冷饮类2
class Pepsi:public ColdDrink{
public:
    float price(){
        return 35.0f;
    }
    string name(){
        return "Pepsi";
    }
};
//创建一个Meal类，带有上面创建的Item对象
class Meal{
private:
    vector<Item*> items;

public:
    void addItem(Item* item){
        items.push_back(item);
    }
    float getCost(){
        float cost = 0.0f;
        for(int i = 0;i < items.size(); i++){
            cost += items[i]->price();
        }
        return cost;
    }
    void showItems(){
        for(int i = 0;i < items.size(); i++){
            cout << "Item:" << items[i]->name();
            cout <<", Packing:" << items[i]->packing()->pack();
            cout << ", Price:" << items[i]->price() << endl;
        }
    }
};
//创建一个MealBuilder类，负责创建Meal对象
class MealBuilder{
public:
    Meal* prepareVegMeal(){
        Meal* meal = new Meal();
        meal->addItem(new VegBurger());
        meal->addItem(new Coke());
        return meal;
    }
    Meal* prepareNonVegMeal(){
        Meal* meal = new Meal();
        meal->addItem(new ChickenBurger());
        meal->addItem(new Pepsi());
        return meal;
    }
};
