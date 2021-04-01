#include "MyParser.hpp"

using hello_func = std::function<void ()>;
using digit_func = std::function<void (const int64_t &token)>;
using str_func = std::function<void (const std::string &token)>;
int count = 0;

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

digit_func DigitPrint(const int64_t &token)
{
    std::cout << "Digit: " << token << std::endl;
    return 0;
}

digit_func DigitCounter(const int64_t &token)
{
    std::cout << count + 1 << " number is " << token << std::endl;
    count++;
    return 0;
}

str_func StringPrint(const std::string &token)
{
    std::cout << "String: " << token << std::endl;
    return 0;
}

str_func WhyString(const std::string &token)
{
    size_t pos = token.find_first_not_of("0123456789");
    std::cout << "This string has a letter: " << token[pos] << std::endl;
    return 0;
}
void DefaultTest()
{
    TokenParser obj1;
    std::string text("hello world 12345 !");
    obj1.Parse(text);
    assert (obj1.pos == std::string::npos);
}

void EmptyStrTest()
{
    TokenParser obj2;
    std::string text("");
    obj2.Parse(text);
    assert (obj2.pos == std::string::npos);
}

void DefaultCallbackTest()
{
    TokenParser obj3;
    std::string text("Hello   world!");
    obj3.SetStartCallback(StartParse);
    obj3.SetEndCallback(EndParse);
    obj3.Parse(text);
    assert (obj3.pos == std::string::npos);
}

void PrintFuncCallbackTest()
{
    TokenParser obj4;
    std::string text("qwerty 	7593 like45 1town 14 !!!");
    obj4.SetStartCallback(StartParse);
    obj4.SetEndCallback(EndParse);
    obj4.SetDigitTokenCallback(DigitPrint);
    obj4.SetStringTokenCallback(StringPrint);
    obj4.Parse(text);
    assert (obj4.pos == std::string::npos);
}

void DigitCounterTest()
{
    TokenParser obj5;
    std::string text("1728 tok 719 qwua ye23u 821 192 \n  8hdg");
    obj5.SetDigitTokenCallback(DigitCounter);
    obj5.Parse(text);
    assert ((count == 4) && (obj5.pos == std::string::npos));
}

void StringSpecialFuncTest()
{
    TokenParser obj6;
    std::string text("just 12do it74 6183 cool");
    obj6.SetStringTokenCallback(WhyString);
    obj6.Parse(text);
    assert (obj6.pos == std::string::npos);
}

void AllTest()
{
    TokenParser obj7;
    count = 0;
    std::string text("tek\n 019 - eid 8391 3315\nrue82  839e 77");
    obj7.SetStringTokenCallback(WhyString);
    obj7.SetDigitTokenCallback(DigitCounter);
    obj7.Parse(text);
    assert ((count == 4) && (obj7.pos == std::string::npos));
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

    std::cout << "PrintFuncCallbackTest" << std::endl;
    PrintFuncCallbackTest();
    std::cout << "Success" << std::endl;

    std::cout << "DigitCounterTest" << std::endl;
    DigitCounterTest();
    std::cout << "Success" << std::endl;

    std::cout << "StringSpecialFuncTest" << std::endl;
    StringSpecialFuncTest();
    std::cout << "Success" << std::endl;

    std::cout << "AllTest" << std::endl;
    AllTest();
    std::cout << "Success" << std::endl;

    return 0;
}

