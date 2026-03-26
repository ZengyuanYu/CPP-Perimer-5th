# C++ Primer 5th Edition 练习题

[![C++](https://img.shields.io/badge/C++-11-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)]()

《C++ Primer 第五版》课后习题解答，涵盖第 1、2、3、6、7、8、9、10 章，一个补充的单例设计模式实现，以及 chapter100 高级 C++ 特性示例。

**开发环境：** Windows 10 / Visual Studio 2015

---

## 项目结构

```
CPP-Perimer-5th/
├── chapter1/          # 开始学习 C++
├── chapter2/          # 变量和基本类型
├── chapter3/          # 字符串、向量和数组
├── chapter6/          # 函数
├── chapter7/          # 类
├── chapter8/          # IO 库
├── chapter9/          # 顺序容器
├── chapter10/         # 泛型算法
├── chapter100/        # 高级 C++ 特性示例（补充）
└── Singleton/         # 单例设计模式（补充）
```

---

## 章节内容与涉及的 C++ 特性

### Chapter 1 — 开始学习

| 文件 | 知识点 |
|------|--------|
| [chapter1.cpp](chapter1/chapter1.cpp) | `cin` / `cout` 基本输入输出、`while` / `for` / `if-else` 控制流、`getline`、`using` 声明、流作为条件判断、`Sales_item` 类的使用 |

### Chapter 2 — 变量和基本类型

| 文件 | 知识点 |
|------|--------|
| [Sales_data.h](chapter2/Sales_data.h) | `struct` 定义、类内成员初始值、`#ifndef` include 守卫 |
| [2.3.cpp](chapter2/2.3.cpp) | `unsigned` 与 `signed` 运算陷阱 |
| [2.13.cpp](chapter2/2.13.cpp) | 变量作用域与遮蔽、`::` 作用域运算符 |
| [2.14.cpp](chapter2/2.14.cpp) | `for` 循环变量的作用域 |
| [2.17.cpp](chapter2/2.17.cpp) | 引用（`int &ri = i`） |
| [2.42.cpp](chapter2/2.42.cpp) | `struct` 使用、基本算术与条件逻辑 |

### Chapter 3 — 字符串、向量和数组

| 文件 | 知识点 |
|------|--------|
| [3.1.cpp](chapter3/3.1.cpp) | `std::string` 的 `cin >> s` 与 `getline` |
| [3.2.cpp](chapter3/3.2.cpp) | `string` 读取：逐词 vs 逐行 |
| [3.4.cpp](chapter3/3.4.cpp) | `string` 比较运算符 |
| [3.5.cpp](chapter3/3.5.cpp) | `string` 拼接 `+=`、三目运算符 `? :` |
| [3.6.cpp](chapter3/3.6.cpp) | **范围 `for` 循环** `for (auto &c : s)` |
| [3.8.cpp](chapter3/3.8.cpp) | **`decltype`** 类型推导 |
| [3.10.cpp](chapter3/3.10.cpp) | `ispunct()` 字符分类、范围 `for` |
| [3.11.cpp](chapter3/3.11.cpp) | 范围 `for` 中的 `const` 引用 |
| [3.15.cpp](chapter3/3.15.cpp) | `std::vector<int>`、`push_back()` |
| [3.17.cpp](chapter3/3.17.cpp) | `vector<string>`、范围 `for` 引用修改元素、`string::size_type` |
| [3.20.cpp](chapter3/3.20.cpp) | `vector` 相邻元素求和与对称求和 |
| [3.21.cpp](chapter3/3.21.cpp) | `vector` **迭代器** `cbegin()` / `cend()`、`pow()` |
| [3.22.cpp](chapter3/3.22.cpp) | 嵌套范围 `for` 处理 `vector`、`isalpha()` |
| [3.23.cpp](chapter3/3.23.cpp) | `vector` **迭代器算术**、元素翻倍 |
| [3.31.cpp](chapter3/3.31.cpp) | **C 风格数组**、`constexpr size_t`、范围 `for` 遍历数组 |
| [3.32.cpp](chapter3/3.32.cpp) | C 风格数组拷贝 |
| [3.35.cpp](chapter3/3.35.cpp) | **指针算术** `begin(a)` / `end(a)`、指针遍历清零数组 |
| [3.36.cpp](chapter3/3.36.cpp) | 用指针比较 C 风格数组 |

### Chapter 6 — 函数

| 文件 | 知识点 |
|------|--------|
| [Chapter6.h](chapter6/Chapter6.h) | 函数声明（原型）、include 守卫 |
| [Chapter6.cpp](chapter6/Chapter6.cpp) | 函数定义、**分离编译** |
| [6.4.cpp](chapter6/6.4.cpp) | **指针传递** swap |
| [6.5.cpp](chapter6/6.5.cpp) | 简单函数、三目运算符 |
| [6.7.cpp](chapter6/6.7.cpp) | **`static` 局部变量** |
| [6.9.cpp](chapter6/6.9.cpp) | 头文件引用与分离编译 |
| [6.10.cpp](chapter6/6.10.cpp) | 指针传递 swap |
| [6.11.cpp](chapter6/6.11.cpp) | **引用传递** `reset(int &i)` |
| [6.17.cpp](chapter6/6.17.cpp) | `const string&` 参数、`isupper()` / `tolower()` |
| [6.21.cpp](chapter6/6.21.cpp) | `const` 指针参数 |
| [6.22.cpp](chapter6/6.22.cpp) | 交换指针本身（非指针所指值） |
| [6.23.cpp](chapter6/6.23.cpp) | **函数重载**、数组引用传递 |
| [6.25.cpp](chapter6/6.25.cpp) | `main(int argc, char **argv)` 命令行参数 |
| [6.30.cpp](chapter6/6.30.cpp) | 返回值与引用返回 |
| [6.33.cpp](chapter6/6.33.cpp) | **递归**、`const_iterator`、`using` 类型别名 |
| [6.42.cpp](chapter6/6.42.cpp) | **默认实参** |
| [6.44.cpp](chapter6/6.44.cpp) | **`inline` 内联函数** |

### Chapter 7 — 类

| 文件 | 知识点 |
|------|--------|
| [7.1.cpp](chapter7/7.1.cpp) | `struct` 成员访问与基本操作 |
| [7.2.cpp](chapter7/7.2.cpp) | 成员函数、**返回 `*this`** |
| [7.4.cpp](chapter7/7.4.cpp) | `Person` 类（struct 形式） |
| [7.6.cpp](chapter7/7.6.cpp) | 操作 `Person` 的自由函数 `read()` / `print()` / `add()` |
| [7.9.cpp](chapter7/7.9.cpp) | `Person` struct 配合自由函数使用 |
| [7.11.cpp](chapter7/7.11.cpp) | **多构造函数**（default、参数化、istream） |
| [7.13.cpp](chapter7/7.13.cpp) | 构造函数与成员函数联合使用 |
| [7.21.h](chapter7/7.21.h) | `class Sales_data`：**`friend` 函数**、`= default` 构造函数、**构造函数初始值列表**、**`this` 指针** |
| [7.21.cpp](chapter7/7.21.cpp) | 使用 7.21.h 中的 Sales_data 类 |
| [7.22.h](chapter7/7.22.h) | `class Person`：**`friend`**、多构造函数、`this->` 访问、返回 `*this` |
| [7.22.cpp](chapter7/7.22.cpp) | 使用 7.22.h 中的 Person 类 |
| [screen.h](chapter7/screen.h) | `Screen` 类与 `Window_mgr` 类：**友元类**、**`const` 与非 const 成员函数重载**、**内联成员函数**、**方法链**（返回 `*this`）、**类内类型别名**（`typedef` / `using`） |
| [7.27.cpp](chapter7/7.27.cpp) | Screen 与 Window_mgr 的完整使用，方法链式调用 |
| [7.43.cpp](chapter7/7.43.cpp) | 无默认构造函数的类、**构造函数初始值列表**必要性 |
| [Person.h](chapter7/Person.h) | `Person` 的 `class` 和 `struct` 两种写法对比 |
| [Sales_data.h](chapter7/Sales_data.h) | 完整 `Sales_data` 类：前向声明、多构造函数、分离定义 |

### Chapter 8 — IO 库

| 文件 | 知识点 |
|------|--------|
| [8.1.cpp](chapter8/8.1.cpp) | `istream&` 作为函数参数和返回值、`clear()` / `rdstate()` |
| [8.4.cpp](chapter8/8.4.cpp) | **`ifstream`** 文件读取 |
| [8.9.cpp](chapter8/8.9.cpp) | **`istringstream`** 字符串流 |
| [8.10.cpp](chapter8/8.10.cpp) | `ifstream` + `istringstream` 组合：文件逐行读取再逐词解析 |
| [8.13.cpp](chapter8/8.13.cpp) | `ifstream` / `istringstream` / **`ostringstream`**：结构化电话号码解析与格式化输出 |

### Chapter 9 — 顺序容器

| 文件 | 知识点 |
|------|--------|
| [9.4.cpp](chapter9/9.4.cpp) | `vector` 迭代器遍历 `begin()` / `end()` |
| [9.14.cpp](chapter9/9.14.cpp) | **迭代器范围构造函数**：`list<char*>` → `vector<string>` |
| [9.15.cpp](chapter9/9.15.cpp) | `vector` 容器比较 `==` |
| [9.16.cpp](chapter9/9.16.cpp) | 跨容器类型比较（`vector` vs `list`） |
| [9.18.cpp](chapter9/9.18.cpp) | **`deque`** 与迭代器 |
| [9.19.cpp](chapter9/9.19.cpp) | **`list`** 与迭代器 |
| [9.20.cpp](chapter9/9.20.cpp) | `list` → 两个 `deque`（奇偶分离） |
| [9.24.cpp](chapter9/9.24.cpp) | `vector` 元素访问：`front()` / `[]` / `at()` / `*begin()` |
| [9.26.cpp](chapter9/9.26.cpp) | `list` 和 `vector` 的 `erase()`、安全迭代器推进 |

### Chapter 10 — 泛型算法

| 文件 | 知识点 |
|------|--------|
| [10.1.cpp](chapter10/10.1.cpp) | **`std::count`** 算法 |
| [10.2.cpp](chapter10/10.2.cpp) | `std::count` 作用于 `list<string>` |
| [10.3.cpp](chapter10/10.3.cpp) | **`std::accumulate`**（`<numeric>`） |
| [10.6.cpp](chapter10/10.6.cpp) | **`std::fill_n`** + **`back_inserter`** 插入迭代器 |
| [10.9.cpp](chapter10/10.9.cpp) | **`sort` + `unique` + `erase`** 去重模式 |
| [10.11.cpp](chapter10/10.11.cpp) | **`stable_sort`** + 自定义谓词（`isShoter`） |

### Singleton — 设计模式补充

| 文件 | 知识点 |
|------|--------|
| [singleton.cpp](Singleton/singleton.cpp) | **单例模式**（懒汉式）：private 构造/析构、`= delete` 禁用拷贝、`static` 成员变量与函数、`nullptr`、`auto` |

### Chapter 100 — 高级 C++ 特性示例

| 文件 | 知识点 |
|------|--------|
| [100_templates.cpp](chapter100/100_templates.cpp) | **模板**：函数模板、多类型参数模板、类模板（含非类型参数）、模板特化、`static_assert` + `type_traits` 编译期检查 |
| [101_smart_pointers.cpp](chapter100/101_smart_pointers.cpp) | **智能指针**：`shared_ptr`（引用计数、`make_shared`）、`unique_ptr`（所有权转移、`make_unique`）、`weak_ptr`（打破循环引用）、自定义删除器 |
| [102_move_semantics.cpp](chapter100/102_move_semantics.cpp) | **移动语义**：右值引用 `&&`、`std::move`、移动构造函数、移动赋值运算符、拷贝 vs 移动对比、左值/右值引用重载分发 |
| [103_lambda.cpp](chapter100/103_lambda.cpp) | **Lambda 表达式**：基本语法、捕获列表（值/引用/`[=]`/`[&]`/混合）、`mutable` lambda、泛型 lambda（C++14）、`std::function` 存储、与 STL 算法配合（`sort`/`for_each`/`count_if`/`transform`/`accumulate`） |
| [104_inheritance.cpp](chapter100/104_inheritance.cpp) | **继承与多态**：基类/派生类、`public` 继承、虚函数 `virtual`、`override`、`final`、纯虚函数与抽象类、多态集合（`unique_ptr<Animal>`）、虚析构函数 |
| [105_exceptions.cpp](chapter100/105_exceptions.cpp) | **异常处理**：`try`/`catch`/`throw`、多层 catch 与继承层次匹配、`catch(...)`、rethrow、自定义异常类、标准异常（`out_of_range`）、`noexcept`、RAII 异常安全 |

---

## C++ 特性汇总

| 类别 | 特性 |
|------|------|
| **基础** | 基本 I/O (`cin`/`cout`/`getline`)、变量与类型、作用域与遮蔽、引用 |
| **字符串与容器** | `std::string` 操作、`std::vector`、`std::deque`、`std::list`、C 风格数组、迭代器 |
| **函数** | 声明/定义/重载、传值/传指针/传引用、`static` 局部变量、`inline`、默认实参、递归、命令行参数 |
| **类与面向对象** | `class`/`struct`、构造函数（default/参数化/`= default`）、构造函数初始值列表、`this` 指针 / 返回 `*this`、`friend` 友元函数与类、访问控制（`public`/`private`）、`const` 成员函数、方法重载与链式调用、类内类型别名（`typedef`/`using`） |
| **IO 库** | `ifstream`、`istringstream`、`ostringstream`、流状态管理 |
| **泛型算法** | `count`、`accumulate`、`fill_n`、`sort`、`unique`、`stable_sort`、`back_inserter`、自定义谓词 |
| **模板** | 函数模板、类模板（含非类型参数）、模板特化、`static_assert`、`type_traits` |
| **智能指针** | `shared_ptr`、`unique_ptr`、`weak_ptr`、自定义删除器 |
| **移动语义** | 右值引用 `&&`、`std::move`、移动构造/赋值、拷贝 vs 移动 |
| **Lambda** | 基本 lambda、捕获列表、`mutable`、泛型 lambda、`std::function` |
| **继承与多态** | `virtual`、`override`、`final`、纯虚函数、抽象类、虚析构函数 |
| **异常处理** | `try`/`catch`/`throw`、自定义异常、`noexcept`、RAII |
| **其他** | 范围 `for` 循环、`decltype`、`auto`、分离编译、include 守卫、单例设计模式 |

---

## 尚未覆盖的主题

以下特性已通过 [chapter100](chapter100/) 补充：模板、智能指针、移动语义、Lambda、继承与多态、异常处理。

仍未覆盖的特性：

- 关联容器（`map` / `set` / `unordered_map` 等）
- `constexpr` 函数与变量
- 可变参数模板
- 第 4、5、11+ 章

---

## License

MIT
