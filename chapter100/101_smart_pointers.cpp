// 101_smart_pointers.cpp — 智能指针（shared_ptr / unique_ptr / weak_ptr）
// 编译：g++ -std=c++14 -o 101_smart_pointers 101_smart_pointers.cpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// ==================== shared_ptr ====================

class Resource {
public:
    Resource(const string& name) : name_(name) {
        cout << "  [Resource] " << name_ << " created" << endl;
    }
    ~Resource() {
        cout << "  [Resource] " << name_ << " destroyed" << endl;
    }
    void use() const { cout << "  Using resource: " << name_ << endl; }

private:
    string name_;
};

void demo_shared_ptr() {
    cout << "===== shared_ptr =====" << endl;

    // 1. make_shared 创建
    shared_ptr<Resource> p1 = make_shared<Resource>("FileHandle");
    p1->use();
    cout << "  ref count = " << p1.use_count() << endl;

    // 2. 拷贝增加引用计数
    {
        shared_ptr<Resource> p2 = p1;
        cout << "  ref count = " << p1.use_count() << endl;
        p2->use();
    } // p2 离开作用域，引用计数减 1
    cout << "  ref count after p2 gone = " << p1.use_count() << endl;

    // 3. 存入容器
    vector<shared_ptr<Resource>> pool;
    pool.push_back(p1);
    cout << "  ref count after push to vector = " << p1.use_count() << endl;
    pool.clear();
    cout << "  ref count after vector cleared = " << p1.use_count() << endl;

    cout << "  p1 going out of scope..." << endl;
}

// ==================== unique_ptr ====================

void demo_unique_ptr() {
    cout << "\n===== unique_ptr =====" << endl;

    // 1. make_unique 创建（C++14）
    unique_ptr<Resource> p1 = make_unique<Resource>("Socket");
    p1->use();

    // 2. 所有权转移（移动）
    unique_ptr<Resource> p2 = move(p1);
    cout << "  p1 is null? " << (p1 == nullptr ? "yes" : "no") << endl;
    p2->use();

    // 3. 自定义删除器
    auto customDeleter = [](Resource* r) {
        cout << "  [Custom Deleter] cleaning up: ";
        r->use();
        delete r;
    };
    unique_ptr<Resource, decltype(customDeleter)> p3(new Resource("DBConn"), customDeleter);
    p3->use();
    cout << "  p3 going out of scope..." << endl;
}

// ==================== weak_ptr：打破循环引用 ====================

class Node {
public:
    string name;
    shared_ptr<Node> partner;       // 指向搭档（强引用）
    weak_ptr<Node> weak_partner;    // weak_ptr 打破循环

    Node(const string& n) : name(n) {
        cout << "  [Node] " << name << " created" << endl;
    }
    ~Node() {
        cout << "  [Node] " << name << " destroyed" << endl;
    }
};

void demo_weak_ptr() {
    cout << "\n===== weak_ptr =====" << endl;

    // 循环引用问题：两个 shared_ptr 互相引用 → 内存泄漏
    cout << "  -- 循环引用（泄漏）--" << endl;
    {
        auto a = make_shared<Node>("Alice");
        auto b = make_shared<Node>("Bob");
        a->partner = b;
        b->partner = a;
        cout << "  Alice ref count = " << a.use_count() << endl;
        cout << "  Bob ref count = " << b.use_count() << endl;
    } // a, b 离开作用域但不会析构（引用计数仍为 1）

    // 用 weak_ptr 解决
    cout << "\n  -- weak_ptr 解决循环引用 --" << endl;
    {
        auto a = make_shared<Node>("Carol");
        auto b = make_shared<Node>("Dave");
        a->weak_partner = b;   // weak_ptr 不增加引用计数
        b->weak_partner = a;
        cout << "  Carol ref count = " << a.use_count() << endl;
        cout << "  Dave ref count = " << b.use_count() << endl;

        // 使用 weak_ptr 需要 lock() 转为 shared_ptr
        if (auto locked = a->weak_partner.lock()) {
            cout << "  Carol's partner is: " << locked->name << endl;
        }
    } // 正常析构
}

// ==================== main ====================

int main() {
    demo_shared_ptr();
    demo_unique_ptr();
    demo_weak_ptr();

    cout << "\nAll smart pointer examples passed!" << endl;
    return 0;
}
