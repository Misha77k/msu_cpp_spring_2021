#include "Allocator.hpp"
#include <iostream>

void Test1()
{
    Allocator obj1;
    obj1.makeAllocator(10);
    char* a = obj1.alloc(4);
    assert (a == obj1.start);
}

void Test2()
{
    Allocator obj2;
    obj2.makeAllocator(20);
    char* a = obj2.alloc(10);
    a = obj2.alloc(5);
    assert (a == obj2.start + 10);
}

void Test3()
{
    Allocator obj3;
    obj3.makeAllocator(20);
    char* a = obj3.alloc(15);
    a = obj3.alloc(4);
    obj3.reset();
    assert (obj3.offset == 0);
}

void Test4()
{
    Allocator obj4;
    obj4.makeAllocator(100);
    char* a = obj4.alloc(45);
    a = obj4.alloc(60);
    assert (a == nullptr);
}

void Test5()
{
    Allocator obj5;
    char* a = obj5.alloc(10);
    assert (a == nullptr);
}

void Test6()
{
    Allocator obj6;
    obj6.makeAllocator(0);
    assert (obj6.start == nullptr);
}

void Test7()
{
    Allocator obj7;
    for (int i = 0; i < 10; i++)
        obj7.makeAllocator(10*(i+1));
    assert ((obj7.offset == 0) && (obj7.start != nullptr));    
}

void Test8()
{
    Allocator obj8;
    obj8.alloc(10);
    obj8.makeAllocator(20);
    assert (obj8.start != nullptr);
}
