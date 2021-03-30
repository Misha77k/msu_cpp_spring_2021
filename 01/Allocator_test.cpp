#include "Allocator.hpp"

void DefaultTest()
{
    Allocator obj1;
    obj1.makeAllocator(10);
    char* a = obj1.alloc(4);
    assert (a != nullptr);
}

void AllocCorrectTest()
{
    Allocator obj2;
    obj2.makeAllocator(20);
    char* a = obj2.alloc(10);
    assert(a != nullptr);
    a = obj2.alloc(5);
    assert (a == obj2.start + 10);
}

void CheckResetTest()
{
    Allocator obj3;
    obj3.makeAllocator(20);
    char* a = obj3.alloc(15);
    assert (a != nullptr);
    a = obj3.alloc(4);
    obj3.reset();
    assert ((obj3.offset == 0) && (a != nullptr));
}

void AllocWrongTest()
{
    Allocator obj4;
    obj4.makeAllocator(100);
    char* a = obj4.alloc(45);
    assert (a != nullptr);
    a = obj4.alloc(60);
    assert (a == nullptr);
}

void OnlyAllocTest()
{
    Allocator obj5;
    char* a = obj5.alloc(10);
    assert (a == nullptr);
}

void MakeAllocator0Test()
{
    Allocator obj6;
    obj6.makeAllocator(0);
    assert (obj6.start == nullptr);
}

void ManyAllocTest()
{
    Allocator obj7;
    char* a;
    for (int i = 0; i < 10; i++){
        obj7.makeAllocator(10*(i+1));
        a = obj7.alloc(10*(i+1));
        assert (a != nullptr);
    }    
}

void AllocBeforeMakeAllocatorTest()
{
    Allocator obj8;
    char* a = obj8.alloc(10);
    obj8.makeAllocator(20);
    assert ((obj8.start != nullptr) && (a == nullptr));
}

void BoundConditionTest()
{
    Allocator obj9;
    obj9.makeAllocator(10);
    char* a = obj9.alloc(10);
    assert (a != nullptr);
    a = obj9.alloc(1);
    assert (a == nullptr);
    obj9.reset();
    a = obj9.alloc(10);
    assert (a != nullptr);
}

int main()
{
    std::cout << "DefaultTest" << std::endl;
    DefaultTest();
    std::cout << "Success" << std::endl;

    std::cout << "AllocCorrectTest" << std::endl;
    AllocCorrectTest();
    std::cout << "Success" << std::endl;

    std::cout << "CheckResetTest" << std::endl;
    CheckResetTest();
    std::cout << "Success" << std::endl;

    std::cout << "AllocWrongTest" << std::endl;
    AllocWrongTest();
    std::cout << "Success" << std::endl;

    std::cout << "OnlyAllocTest" << std::endl;
    OnlyAllocTest();
    std::cout << "Success" << std::endl;

    std::cout << "MakeAllocator0Test" << std::endl;
    MakeAllocator0Test();
    std::cout << "Success" << std::endl;
    
    std::cout << "ManyAllocTest" << std::endl;
    ManyAllocTest();
    std::cout << "Success" << std::endl;
    
    std::cout << "AllocBeforeMakeAllocatorTest" << std::endl;
    AllocBeforeMakeAllocatorTest();
    std::cout << "Success" << std::endl;

    std::cout << "BoundConditionTest" << std::endl;
    BoundConditionTest();
    std::cout << "Success" << std::endl;

    return 0;
}
