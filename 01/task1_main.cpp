#include <iostream>
#include "task1.cpp"

void Test1()
{
    Allocator obj1;
    obj1.makeAllocator(10);
    char* a = obj1.alloc(4);
    assert(a == obj1.start);
}

void Test2()
{
    Allocator obj2;
    obj2.makeAllocator(20);
    char* a = obj2.alloc(10);
    a = obj2.alloc(5);
    assert(a == obj2.start + 10);
}

void Test3()
{
    Allocator obj3;
    obj3.makeAllocator(20);
    char* a = obj3.alloc(15);
    a = obj3.alloc(4);
    obj3.reset();
    assert(obj3.offset == 0);
}

void Test4()
{
    Allocator obj4;
    obj4.makeAllocator(100);
    char* a = obj4.alloc(45);
    a = obj4.alloc(60);
    assert(a == nullptr);
}

void Test5()
{
   Allocator obj5;
   char* a = obj5.alloc(10);
   assert(a == nullptr);
}

void Test6()
{
   Allocator obj6;
   obj6.makeAllocator(-5);
   assert(obj6.start == nullptr);
}

int main()
{
    std::cout << "Test 1" << std::endl;
    Test1();
    std::cout << "Success" << std::endl;

    std::cout << "Test 2" << std::endl;
    Test2();
    std::cout << "Success" << std::endl;

    std::cout << "Test 3" << std::endl;
    Test3();
    std::cout << "Success" << std::endl;

    std::cout << "Test 4" << std::endl;
    Test4();
    std::cout << "Success" << std::endl;

    std::cout << "Test 5" << std::endl;
    Test5();
    std::cout << "Success" << std::endl;

    std::cout << "Test 6" << std::endl;
    Test6();
    std::cout << "Success" << std::endl;
   
    return 0;
}
