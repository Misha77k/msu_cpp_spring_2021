#include "MyFormat.hpp"

void CorrectTests()
{
    assert (format("") == "");
    assert (format("{0}", "a") == "a");
    assert (format("{0}+{0}={1}", "one", "2") == "one+one=2");
    assert (format("{0} any text {1} {0}", "read", "write", "qw") == "read any text write read");
    assert (format("{0}+{1}+{2}+{3}={4}", "0", "1", "2", "3", "6") == "0+1+2+3=6");
}

void ExceptTests()
{
    bool flag;
    std::string a;
    
    try {
        a = format("{}", "1");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);
 
    try {
        a = format("{a}", "1");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);

    try {
        a = format("{0}{1}", "1");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);

    try {
        a = format("{0", "1");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);

    try {
        a = format("{0}}", "1", "2");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);

    try {
        a = format("{0}{1}{2}", "1", "2");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);

    try {
        a = format("{0}{1}{5}", "1", "2", "3");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);

    try {
        a = format("{0", "1");
        flag = false;
    }
    catch(const MyError& err) {
        std::cout << err << std::endl;
        flag = true;
    }
    assert (flag);
}

int main()
{
    std::cout << "CorrectTests" << std::endl;
    CorrectTests();
    std::cout << "Success" <<std::endl;

    std::cout << "ExceptTests" << std::endl;
    ExceptTests();
    std::cout << "Success" << std::endl;

    return 0;
}

