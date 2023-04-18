#include <iostream>
using namespace std;

//父类
class Game{
public:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;
    //模板方法，不能被子类重写
    virtual void paly() final{
        //初始化游戏
        initialize();
        //开始游戏
        startPlay();
        //结束游戏
        endPlay();
    }
};

//子类1
class Cricket:public Game{
public:
    void endPlay(){
        cout << "Criket Game Finished!" << endl;
    }
    void initialize(){
        cout << "Criket Game Initialized! Start Playing." << endl;
    } 
    void startPlay(){
        cout << "Criket Game Started. Enjoy the Game!" << endl;
    }
};

//子类2
class Football:public Game{
public:
    void initialize(){
        cout << "Football Game Initialized! Start Playing." << endl;
    }
    void startPlay(){
        cout << "Football Game Started. Enjoy the Game!" << endl;
    }
    void endPlay(){
        cout << "Football Game Finished!" << endl;
    }
};