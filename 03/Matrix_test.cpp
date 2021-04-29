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
    Matrix m3(4, 3);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++) {      
            m2[i][j] = (i == j ? 9 : 0);
            m3[i][j] = (i == j ? 9 : 0);
        }
    assert (!(m1 == m2));
    assert (m2 == m3);
} 

void WrongDimTest()
{
    bool flag;
    try {
        Matrix obj3(0, 5);
        flag = false;
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
        flag = true;
    }
    assert (flag);
}

void WrongAddTest()
{
    bool flag;
    Matrix obj4(6, 9);
    Matrix obj4_(7, 8);
    try {
        Matrix m = obj4 + obj4_;
        flag = false;
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
        flag = true;
    }    
    assert (flag);
}

void OutOfRangeTest()
{
    bool flag;
    Matrix obj1(90, 90);
    try {
        obj1[100][0] = 12;
        flag = false;
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
        flag = true;
    }
    assert (flag);
    try {
        obj1[12][90] = 1;
        flag = false;
    }
    catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
        flag = true;
    }    
    assert (flag);
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

void GetElementTest()
{
    bool flag;
    int val1, val2, val3, val4;
    try {
        Matrix obj6(2, 2);
        for (size_t i = 0; i < 2; i++)
            for (size_t j = 0; j < 2; j++)
                obj6[i][j] = (i == j ? 2 : 1);
        val1 = obj6[0][0];
        assert (val1 == 2);
        val2 = obj6[0][1];
        assert (val2 == 1);
        val3 = obj6[1][0];
        assert (val3 == 1);
        val4 = obj6[1][1];
        assert (val4 == 2);
        flag = true;
    }
    catch (...) {
        flag = false;
    }
    assert (flag);
        
}

void OutputTest()
{
    bool flag;
    try {
        Matrix obj7(4, 6);
        for (size_t i = 0; i < 4; i++)
            for (size_t j = 0; j < 6; j++)
                if ((i + j) % 2 == 0)
                    obj7[i][j] = 7;
                else obj7[i][j] = -4;
        std::cout << obj7;
        flag = true; 
    }
    catch (...) {
        flag = false;
    }
    assert (flag);   
}

int main()
{
    std::cout << "DefaultTest" << std::endl;
    DefaultTest();
    std::cout << "Success" << std::endl;
    
    std::cout << "OperatorCheckTest" << std::endl;
    OperatorCheckTest();
    std::cout << "Success" << std::endl;

    std::cout << "WrongDimTest" << std::endl;
    WrongDimTest();
    std::cout << "Success" << std::endl;

    std::cout << "WrongAddTest" << std::endl;
    WrongAddTest();
    std::cout << "Success" << std::endl;

    std::cout << "OutOfRangeTest" << std::endl;
    OutOfRangeTest();
    std::cout << "Success" << std::endl;
 
    std::cout << "GetRowsColsTest" << std::endl;
    GetRowsColsTest();
    std::cout << "Success" << std::endl;

    std::cout << "GetElementTest" << std::endl;
    GetElementTest();
    std::cout << "Success" << std::endl;

    std::cout << "OutputTest" << std::endl;
    OutputTest();
    std::cout << "Success" << std::endl; 
}
