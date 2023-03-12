#include <iostream>

class Singleton {

private:
    Singleton(){
        std::cout << "构造函数" << std::endl;
    };
    ~Singleton(){
        std::cout << "析构函数" << std::endl;
    };
    // 私有，无法外部拷贝和赋值
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    static Singleton *_pInstance;

public:
    void getSingletonName() {
        std::cout << "Singleton" << std::endl;
    }
    static Singleton *getInstance() {
        if (NULL == _pInstance) {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }    
};

Singleton*  Singleton::_pInstance = nullptr;

int main() {

    auto tmp1 = Singleton::getInstance();
    auto tmp2 = Singleton::getInstance();
    // tmp.getSingletonName();
    std::cout << "&tmp1" << &tmp1 << std::endl;
    std::cout << "&tmp2" << &tmp1 << std::endl;
    return 0;
}