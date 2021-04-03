#include "MyParser.hpp"
#define N pow(2, 64)+1

using hello_func = std::function<void ()>;
using digit_func = std::function<void (const uint64_t &token)>;
using str_func = std::function<void (const std::string &token)>;
std::vector<uint64_t> ArrOfDig;
std::vector<std::string> ArrOfStr;

hello_func StartParse()
{
    std::cout << "Start Parsing" << std::endl;
    return 0;
}

hello_func EndParse()
{
    std::cout << "End Parsing" << std::endl;
    return 0;
}

digit_func DigitFunc(const uint64_t &token)
{
    ArrOfDig.push_back(token);
    return 0;
}

str_func StringFunc(const std::string &token)
{
    ArrOfStr.push_back(token);
    return 0;
}

void DefaultTest()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj1;
    std::string text("hello world 12345 !");
    obj1.Parse(text);
    assert (obj1.pos == std::string::npos);
}

void EmptyStrTest()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj2;
    std::string text("");
    obj2.SetStringTokenCallback(StringFunc);
    obj2.SetDigitTokenCallback(DigitFunc);
    obj2.Parse(text);
    assert ((ArrOfStr.size() == 0) && (ArrOfDig.size() == 0));
}

void DefaultCallbackTest()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj3;
    std::string text("Hello   world!");
    obj3.SetStartCallback(StartParse);
    obj3.SetEndCallback(EndParse);
    obj3.Parse(text);
    assert (obj3.pos == std::string::npos);
}

void OneStrSymbTest()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj4;
    std::string text("q");
    obj4.SetStartCallback(StartParse);
    obj4.SetEndCallback(EndParse);
    obj4.SetDigitTokenCallback(DigitFunc);
    obj4.SetStringTokenCallback(StringFunc);
    obj4.Parse(text);
    assert ((ArrOfStr.size() == 1) && (ArrOfDig.size() == 0));
}

void OneDigSymbTest()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj5;
    std::string text("5");
    obj5.SetStartCallback(StartParse);
    obj5.SetEndCallback(EndParse);
    obj5.SetDigitTokenCallback(DigitFunc);
    obj5.SetStringTokenCallback(StringFunc);
    obj5.Parse(text);
    assert ((ArrOfDig.size() == 1) && (ArrOfStr.size() == 0));
}

void AllTest1()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj6;
    std::string text("just 12do it74 6183	cool 7634");
    obj6.SetDigitTokenCallback(DigitFunc);
    obj6.SetStringTokenCallback(StringFunc);
    obj6.Parse(text);
    assert ((ArrOfDig.size() == 2) && (ArrOfStr.size() == 4));
}

void AllTest2()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    TokenParser obj7;
    std::string text("tek\n 019 - eid 8391 3315\nrue82  839e 77");
    obj7.SetStringTokenCallback(StringFunc);
    obj7.SetDigitTokenCallback(DigitFunc);
    obj7.Parse(text);
    assert ((ArrOfDig.size() == 4) && (ArrOfStr.size() == 5));
}

void BoundTest()
{
    ArrOfStr.clear();
    ArrOfDig.clear();
    std::stringstream ss;
    TokenParser obj8;
    ss << N;
    std::string text = ss.str();
    obj8.SetDigitTokenCallback(DigitFunc);
    obj8.SetStringTokenCallback(StringFunc);
    obj8.Parse(text);
    assert ((ArrOfDig.size() == 0) && (ArrOfStr.size() == 1));
}

int main()
{
    std::cout << "DefaultTest" << std::endl;
    DefaultTest();
    std::cout << "Success" << std::endl;

    std::cout << "EmptyStrTest" << std::endl;
    EmptyStrTest();
    std::cout << "Success" << std::endl;

    std::cout << "DefaultCallbackTest" << std::endl;
    DefaultCallbackTest();
    std::cout << "Success" << std::endl;

    std::cout << "OneStrSymbTest" << std::endl;
    OneStrSymbTest();
    std::cout << "Success" << std::endl;

    std::cout << "OneDigSymbTest" << std::endl;
    OneDigSymbTest();
    std::cout << "Success" << std::endl;

    std::cout << "AllTest1" << std::endl;
    AllTest1();
    std::cout << "Success" << std::endl;

    std::cout << "AllTest2" << std::endl;
    AllTest2();
    std::cout << "Success" << std::endl;

    std::cout << "BoundTest" << std::endl;
    BoundTest();
    std::cout << "Success" << std::endl;

    return 0;
}

