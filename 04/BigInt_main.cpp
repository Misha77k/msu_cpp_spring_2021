#include "BigInt.hpp"

void DefaultTest()
{
    std::string str1 = "54321";
    BigInt a(str1);
    BigInt c = -a;
    std::cout << c << std::endl;
    assert (-c == a);
}

void InputTest()
{
    std::string str1 =  "18446744073709551615555555";
    BigInt a(str1);
    std::cout << a << std::endl;
    assert (get_str_from_bigint(a) == "18446744073709551615555555");
    std::string str2 = "12wqg82";
    try {
        BigInt b(str2);
    }
    catch(const std::invalid_argument &err) {
        std::cout << err.what() << std::endl;
    }
    std::string str3 = "013";
    try {
        BigInt c(str3);
    }
    catch(const std::invalid_argument &err) {
        std::cout << err.what() << std::endl;
    }
}

void OperationCheckTest1()
{
    std::string str1 = "5674";
    std::string str2 = "45";
    BigInt a(str1);
    BigInt b(str2);
    BigInt c = a * b;
    assert (get_str_from_bigint(c) == "255330");
    BigInt d = b * 1621;
    assert (get_str_from_bigint(d) == "72945");
    BigInt e = c + d;
    assert (get_str_from_bigint(e) == "328275");
    BigInt f1 = c - d;
    assert (get_str_from_bigint(f1) == "182385");
    BigInt f2 = d - c;
    assert (get_str_from_bigint(f2) == "-182385");
}

void OperationCheckTest2()
{
    std::string str1 = "999999999";
    std::string str2 = "1";
    std::string str3 = "2000000000";
    std::string str4 = "1";
    BigInt a(str1);
    BigInt b(str2);
    BigInt c(str3);
    BigInt d(str4);
    BigInt e1 = a + b;
    assert (get_str_from_bigint(e1) == "1000000000");
    BigInt e2 = c - d;
    assert (get_str_from_bigint(e2) == "1999999999");
    std::string str5 = "123456789";
    BigInt f(str5);
    BigInt e3 = f * 0;
    std::cout << e3 << std::endl;
    assert (get_str_from_bigint(e3) == "0");
    BigInt f3("-11111111111111111111111");
    BigInt f4("22222222222222222222222");
    BigInt f5 = f3 * f4;
    assert (get_str_from_bigint(f5) == "-246913580246913580246908641975308641975308642");
}

void CompareTest()
{
    std::string str1 = "1234567899";
    std::string str2 = "1234567845";
    BigInt a1(str1);
    BigInt a2(str2);
    assert (a1 > a2);
    std::string str3 = "1234567899";
    BigInt a3(str3);
    assert (a1 == a3);
    BigInt a4("-1111111111111");
    BigInt a5("-1111111111511");
    assert (a5 < a4);    
}

int main()
{
    std::cout << "DefaultTest" << std::endl;
    DefaultTest();
    std::cout << "Success" << std::endl;
    
    std::cout << "InputTest" << std::endl;
    InputTest();
    std::cout << "Success" << std::endl;      
    
    std::cout << "OperationCheckTest1" << std::endl;
    OperationCheckTest1();
    std::cout << "Success" << std::endl;

    std::cout << "OperationCheckTest2" << std::endl;
    OperationCheckTest2();
    std::cout << "Success" << std::endl;

    std::cout << "CompareTest" << std::endl;
    CompareTest();
    std::cout << "Success" << std::endl;

    return 0;
}
