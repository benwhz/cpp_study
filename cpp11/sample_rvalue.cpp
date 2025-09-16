#include <utility>  // for std::move
#include <vector>
#include <iostream>

#include <string>
#include <cstring>

int move_() {
    std::string str1 = "hello world";
    std::string str2 = std::move(str1);  // 移动 str1 的内容到 str2，str1 变为空

    std::cout << "str1: '" << str1 << "', str2: '" << str2 << "'" << std::endl;
    // 输出：str1: '', str2: 'hello world'
    return 0;
}

class MyClass {
public:
    MyClass() { std::cout << "Constructor\n"; }
    MyClass(const MyClass&) { std::cout << "Copy\n"; }
    MyClass(MyClass&&) noexcept { std::cout << "Move\n"; }  // 移动构造函数
};


class String {
public:
    // 构造函数
    String(const char* str = "") {
        std::cout << "Call Normal Constructor" << std::endl;
        size_ = strlen(str);
        data_ = new char[size_ + 1];
        strcpy_s(data_, size_ + 1, str);
    }

    // 拷贝构造函数（深拷贝）
    String(const String& other) {
        std::cout << "Call Copy Constructor" << std::endl;
        size_ = other.size_;
        data_ = new char[size_ + 1];
        strcpy_s(data_, size_ + 1, other.data_); // 昂贵的拷贝
    }

    // ⭐ 移动构造函数（新功能）
    String(String&& other) noexcept {
        std::cout << "Call Move Constructor" << std::endl;
        // 1. 从临时对象中“窃取”资源
        data_ = other.data_;
        size_ = other.size_;

        // 2. 将临时对象置于“空”状态
        other.data_ = nullptr;
        other.size_ = 0;
    }

    // 析构函数
    ~String() {
        delete[] data_;
    }

private:
    char* data_;
    size_t size_;
};

String create_string() {
    String str("Hello world");
    return str;
}

int main() {
    MyClass obj;
    std::vector<MyClass> vec;
    vec.reserve(2);

    vec.push_back(obj);           // 使用拷贝
    // 输出: Constructor \n Copy
    vec.push_back(std::move(obj));  // 使用移动，避免拷贝，扩容会调用两次移动构造函数
    // 输出: Constructor \n Move

    move_();

    String a = create_string(); // 这里会发生什么？

    return 0;
}