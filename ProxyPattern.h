#include <iostream>
using namespace std;

class Image{
public:
    virtual void display() = 0;
};
//实际类 创建时就加载图像
class RealImage:public Image{
private:
    string filename;
    void loadFromDisk(string filename){
        cout << "Loading " << filename << endl;
    }
public: 
    RealImage(string filename){
        this->filename = filename;
        loadFromDisk(filename);
    }
    void display(){
        cout << "Displaying " << filename << endl;
    }
};
//代理类 在创建对象时不加载图片，只有当需要展示时才加载
class ProxyImage:public Image{
private:
    RealImage* realImage = nullptr;
    string filename;
public:
    ProxyImage(string file){
        this->filename = file;
    }
    void display(){
        if(realImage == nullptr){
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};
