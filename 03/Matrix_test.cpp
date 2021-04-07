#include "Matrix.hpp"

void DefaultTest()
{
    Matrix obj1(2, 2);
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++) {
            obj1[i][j] = 5;
            assert (obj1[i][j] == 5);
        }
}

void OperatorCheckTest()
{
    Matrix obj2(4, 3);
    Matrix m(4, 3);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++) {
            obj2[i][j] = 1; 
            m[i][j] = 2;
        }
    obj2 *= 7;
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++) 
            assert (obj2[i][j] == 7);
    Matrix m1 = obj2 + m;
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++)
            assert (m1[i][j] == 9);
    
    Matrix m2(4, 3);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++)      
            if (i == j)
                m2[i][j] = 9;
            else m2[i][j] = 0;
    assert (!(m1 == m2));
} 

void ExceptTest1()
{
    try {
        Matrix obj3(0, 5);
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
    }
}

void ExceptTest2()
{
    try {
        Matrix obj4(6, 9);
        Matrix obj4_(7, 8);
        Matrix m = obj4 + obj4_;
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
    }    
}

void GetRowsColsTest()
{
    Matrix obj5(20, 95);
    for (size_t i = 0; i < 20; i++)
        for (size_t j = 0; j < 95; j++)
            obj5[i][j] = -12;
    Matrix m = obj5 + obj5;
    assert (m.GetRows() == 20);
    assert (m.GetCols() == 95);
}

void OutputTest()
{
    Matrix obj6(4, 6);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 6; j++)
            if ((i + j) % 2 == 0)
                obj6[i][j] = 7;
            else obj6[i][j] = -4;
     std::cout << obj6;    
}

int main()
{
    std::cout << "DefaultTest" << std::endl;
    DefaultTest();
    std::cout << "Success" << std::endl;
    
    std::cout << "OperatorCheckTest" << std::endl;
    OperatorCheckTest();
    std::cout << "Success" << std::endl;

    std::cout << "ExceptTest1" << std::endl;
    ExceptTest1();
    std::cout << "Success" << std::endl;

    std::cout << "ExceptTest2" << std::endl;
    ExceptTest2();
    std::cout << "Success" << std::endl;

    std::cout << "GetRowsColsTest" << std::endl;
    GetRowsColsTest();
    std::cout << "Success" << std::endl;

    std::cout << "OutputTest" << std::endl;
    OutputTest();
    std::cout << "Success" << std::endl;    
}
