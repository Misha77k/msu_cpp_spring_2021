#include "Serializer.hpp"

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer)
    {
        return deserializer(a, b, c);
    }    
};

void DefaultTest()
{
    Data x {1, true, 2};
    std::stringstream str1;
    Serializer serializer(str1);
    assert(serializer.save(x) == Error::NoError);
}

void CheckTest()
{
    Data x { 1, true, 2 };
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    Data y { 0, false, 0 };
    Deserializer deserializer(stream);
    assert(deserializer.load(y) == Error::NoError);
    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}

void UintExceptTest()
{
    Data x {0, false, 0};
    auto stream1 = std::stringstream("1 false -5");
    Deserializer d1(stream1);
    Error err1 = d1.load(x);
    assert (err1 == Error::CorruptedArchive);
    
    auto stream2 = std::stringstream("18446744073709551616 false 5");
    Deserializer d2(stream2);
    Error err2 = d2.load(x);
    assert(err2 == Error::CorruptedArchive);        

    auto stream3 = std::stringstream("18446744073709551615 false 5");
    Deserializer d3(stream3);
    Error err3 = d3.load(x);
    assert(err3 == Error::NoError);

    auto stream4 = std::stringstream("1 false qwerty");
    Deserializer d4(stream4);
    Error err4 = d4.load(x);
    assert(err4 == Error::CorruptedArchive);
}

void BoolExceptTest()
{
    Data x {0, false, 0};
    auto stream1 = std::stringstream("1 false");
    Deserializer d1(stream1);
    Error err1 = d1.load(x);
    assert (err1 == Error::CorruptedArchive);

    auto stream2 = std::stringstream("1 asd 5");
    Deserializer d2(stream2);
    Error err2 = d2.load(x);
    assert(err2 == Error::CorruptedArchive);

    auto stream3 = std::stringstream("3 1 5");
    Deserializer d3(stream3);
    Error err3 = d3.load(x);
    assert(err3 == Error::CorruptedArchive);

    auto stream4 = std::stringstream("1 false true");
    Deserializer d4(stream4);
    Error err4 = d4.load(x);
    assert(err4 == Error::CorruptedArchive);

    auto stream5 = std::stringstream("1 true 23");
    Deserializer d5(stream5);
    Error err5 = d5.load(x);
    assert(err5 == Error::NoError);
    assert(x.a == 1);
    assert(x.b == true);
    assert(x.c == 23);
}

int main()
{
    std::cout << "DefaultTest" << std::endl;
    DefaultTest();
    std::cout << "Success" << std::endl;

    std::cout << "CheckTest" << std::endl;
    CheckTest();
    std::cout << "Success" << std::endl;

    std::cout << "UintExceptTest" << std::endl;
    UintExceptTest();
    std::cout << "Success" << std::endl;

    std::cout << "BoolExceptTest" << std::endl;
    BoolExceptTest();
    std::cout << "Success" << std::endl;

}

