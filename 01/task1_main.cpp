#include <iostream>
#include "task1.cpp"


int main()
{
    std::cout << "Test 1" << std::endl;
    Allocator obj;
    obj.makeAllocator(10);
    obj.makeAllocator(7);
    char* a = obj.alloc(5);
    a = obj.alloc(1);
    obj.reset();
    a = obj.alloc(3);
    std::cout << std::endl;
    
    std::cout << "Test 2" << std::endl;
    Allocator obj1;
    obj1.makeAllocator(-1);
    std::cout << std::endl;
   
    std::cout << "Test 3" << std::endl;
    Allocator obj2;
    a = obj2.alloc(5);
    std::cout << std::endl;
   
    std::cout << "Test 4" << std::endl;
    Allocator obj3;
    obj3.reset();
    std::cout << std::endl;
   
    std::cout << "Test 5" << std::endl;
    Allocator obj4;
    obj4.makeAllocator(50);
    std::cout << "Mem Start: " << &obj4.start << std::endl;
    a = obj4.alloc(56);
    std::cout << "Mem Used: " << &a << std::endl;
   
    return 0;
}
