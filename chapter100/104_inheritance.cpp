// 104_inheritance.cpp — 继承与多态（虚函数、override、纯虚函数、抽象类）
// 编译：g++ -std=c++14 -o 104_inheritance 104_inheritance.cpp

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// ==================== 1. 基本继承 ====================

class Animal {
public:
    Animal(const string& name) : name_(name) {}

    // 非虚函数：静态绑定
    void breathe() const {
        cout << "  " << name_ << " is breathing" << endl;
    }

    // 虚函数：动态绑定（多态）
    virtual void speak() const {
        cout << "  " << name_ << " makes a generic sound" << endl;
    }

    // 纯虚函数：使得 Animal 成为抽象类
    virtual string species() const = 0;

    // 虚析构函数：确保通过基类指针删除派生类对象时正确析构
    virtual ~Animal() {
        cout << "  [~Animal] " << name_ << " destroyed" << endl;
    }

    const string& name() const { return name_; }

protected:
    string name_;
};

// ==================== 2. 派生类 ====================

class Dog : public Animal {
public:
    Dog(const string& name, const string& breed)
        : Animal(name), breed_(breed) {}

    // override：显式标记重写虚函数（C++11）
    void speak() const override {
        cout << "  " << name_ << " says: Woof!" << endl;
    }

    string species() const override {
        return "Canis lupus familiaris";
    }

    void fetch() const {
        cout << "  " << name_ << " is fetching the ball!" << endl;
    }

    ~Dog() override {
        cout << "  [~Dog] " << name_ << " destroyed" << endl;
    }

private:
    string breed_;
};

class Cat : public Animal {
public:
    Cat(const string& name) : Animal(name) {}

    void speak() const override {
        cout << "  " << name_ << " says: Meow!" << endl;
    }

    string species() const override {
        return "Felis catus";
    }

    ~Cat() override {
        cout << "  [~Cat] " << name_ << " destroyed" << endl;
    }
};

class Parrot : public Animal {
public:
    Parrot(const string& name, const string& phrase)
        : Animal(name), phrase_(phrase) {}

    void speak() const override {
        cout << "  " << name_ << " says: " << phrase_ << "!" << endl;
    }

    string species() const override {
        return "Psittaciformes";
    }

    ~Parrot() override {
        cout << "  [~Parrot] " << name_ << " destroyed" << endl;
    }

private:
    string phrase_;
};

// ==================== 3. final 阻止进一步重写 ====================

class GuideDog final : public Dog {
public:
    GuideDog(const string& name, const string& breed)
        : Dog(name, breed) {}

    void speak() const override final {  // final：不允许子类重写
        cout << "  " << name_ << " says: *silently guides*" << endl;
    }

    ~GuideDog() override {
        cout << "  [~GuideDog] " << name_ << " destroyed" << endl;
    }
};

// GuideDog 再继承会报错：class GuideDog is final
// class BlindGuide : public GuideDog {};  // 编译错误

// ==================== 4. 多态使用 ====================

void animalConcert(const vector<unique_ptr<Animal>>& zoo) {
    cout << "  --- Animal Concert ---" << endl;
    for (const auto& animal : zoo) {
        // 多态：通过基类指针调用派生类的 speak()
        animal->speak();
    }
}

// ==================== main ====================

int main() {
    // 1. 基本继承与多态
    cout << "===== 1. 多态行为 =====" << endl;
    Dog dog("Buddy", "Golden Retriever");
    Cat cat("Kitty");
    Parrot parrot("Polly", "Polly wants a cracker");

    // 静态绑定（非虚函数）
    dog.breathe();
    cat.breathe();

    // 动态绑定（虚函数）
    Animal* animals[] = {&dog, &cat, &parrot};
    for (auto* a : animals) a->speak();

    // 2. 纯虚函数
    cout << "\n===== 2. 纯虚函数 =====" << endl;
    cout << "  Dog species: " << dog.species() << endl;
    cout << "  Cat species: " << cat.species() << endl;
    cout << "  Parrot species: " << parrot.species() << endl;
    // Animal a("test");  // 编译错误：抽象类不能实例化

    // 3. 派生类特有方法
    cout << "\n===== 3. 派生类特有方法 =====" << endl;
    dog.fetch();  // Dog 独有的方法

    // 4. 多态集合
    cout << "\n===== 4. 多态集合（unique_ptr） =====" << endl;
    vector<unique_ptr<Animal>> zoo;
    zoo.push_back(make_unique<Dog>("Rex", "German Shepherd"));
    zoo.push_back(make_unique<Cat>("Whiskers"));
    zoo.push_back(make_unique<Parrot>("Jack", "Hello"));
    zoo.push_back(make_unique<GuideDog>("Lucky", "Labrador"));

    animalConcert(zoo);

    for (const auto& a : zoo)
        cout << "  " << a->name() << " is a " << a->species() << endl;

    // 5. final 关键字
    cout << "\n===== 5. final 关键字 =====" << endl;
    GuideDog guide("Max", "Labrador");
    guide.speak();  // GuideDog 的 final override

    // 6. 析构顺序
    cout << "\n===== 6. 虚析构顺序 =====" << endl;
    {
        unique_ptr<Animal> p = make_unique<Dog>("Duke", "Poodle");
        cout << "  p going out of scope..." << endl;
    } // 先析构 Dog，再析构 Animal

    cout << "\nAll inheritance examples passed!" << endl;
    return 0;
}
