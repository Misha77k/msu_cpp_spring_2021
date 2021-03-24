#include <iostream>
#include "task1.cpp"

int main()
{
   
    Allocator obj;
    std::cout << "Создай" << std::endl;
    obj.makeAllocator(10);
    obj.makeAllocator(7);
    char* a = obj.alloc(5);
    a = obj.alloc(1);
    obj.reset();
    a = obj.alloc(3);
   
    Allocator obj1;
    obj1.makeAllocator(-1);
   
    Allocator obj2;
    a = obj2.alloc(5);
   
    Allocator obj3;
    obj3.reset();
   
    Allocator obj4;
    obj4.makeAllocator(50);
    std::cout << "Mem Start: " << std::hex << &obj4.start << std::endl;
    a = obj4.alloc(56);
    std::cout << "Mem Used: " << std::hex << &a << std::endl;
   
    return 0;
}
