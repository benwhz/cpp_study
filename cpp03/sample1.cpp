#include <iostream>

void references()
{
    int& y = *(new int(5)); // y is a reference to a dynamically allocated int
    std::cout << "y: " << y << std::endl; // Output: y: 5
    std::cout << "y pointer: " << &y << std::endl;
    delete &y; // Free the dynamically allocated memory
    // Note: After this point, y is a dangling reference and should not be used.

    int x = 10;
    int& ref = x; // ref is a reference to x
    ref = 20;     // modifies x through the reference
    // Now x is 20
    std::cout << "x: " << x << std::endl; // Output: x: 20
    std::cout << "ref pointer: " << &ref << " x pointer: " << &x << std::endl;

    int z = 30;
    int &a = x; // Error: declaration of reference variable 'a' requires an initializer
    a = z; // Error: lvalue required as left operand of assignment

    //int& z = 0; // Error: cannot bind non-const lvalue reference to an rvalue
    const int& cz = 0; // OK: can bind const lvalue reference to an rvalue
    std::cout << "cz: " << cz << std::endl; // Output: cz: 0

    int&& r1 = 5; // OK: r1 is an rvalue reference to a temporary int
    std::cout << "r1: " << r1 << std::endl; // Output: r1: 5
    r1 = 10; // OK: modifies the temporary int
    std::cout << "r1 after modification: " << r1 << std::endl; // Output: r1 after modification: 10

    //int&& r2 = x; // Error: cannot bind rvalue reference to an lvalue
}

void func(int&& val)
{
    std::cout << "Inside func, val: " << val << std::endl;
    val += 10;
    std::cout << "Inside func after modification, val: " << val << std::endl;
}
void funca(int& val)
{
    std::cout << "Inside funca, val: " << val << std::endl;
    val += 10;
    std::cout << "Inside funca after modification, val: " << val << std::endl;
}

void rvalue_references()
{
    int x = 20;

    func(10); // OK: 10 is an rvalue

    //funca(30); // Error: cannot bind rvalue reference to an lvalue

    funca(x); // Error: cannot bind rvalue reference to an lvalue
    std::cout << "x after funca: " << x << std::endl; // Output: x after funca: 30
    func(std::move(x)); // OK: std::move casts x to an rvalue
}

int& getRef()
{
    //int* p = new int(42);
    //return *p; // Returning a reference to a dynamically allocated int
    return *(new int(42));
}

int main()
{
    rvalue_references();

    int& ref = getRef();
    ref = 100; // Modifies the dynamically allocated int
    std::cout << "ref: " << ref << std::endl; // Output: ref: 100
    delete &ref; // Free the dynamically allocated memory

    return 0;
}