#include <utility>  // for std::move
#include <vector>
#include <iostream>

#include <string>

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

int main() {
    MyClass obj;
    std::vector<MyClass> vec;
    vec.push_back(obj);           // 使用拷贝
    // 输出: Constructor \n Copy
    vec.push_back(std::move(obj));  // 使用移动，避免拷贝
    // 输出: Constructor \n Move

    move_();
    return 0;
}