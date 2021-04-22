#ifndef HPP_BigInt
#define HPP_BigInt

#include <iostream>
#include <string>
#include <math.h>

class BigInt
{
private:
    const  int base = 10;
    int len;
    bool sign;
    int* ptr;
public:
    BigInt()=default;
    BigInt(const std::string& str);
    BigInt(const BigInt& obj);
    BigInt(BigInt&& obj);
    BigInt operator=(const BigInt& obj);
    BigInt operator=(int32_t n);
    BigInt operator=(BigInt&& obj);
    BigInt operator-() const;
    ~BigInt();
    
    friend std::string get_str_from_bigint(const BigInt& obj1);
    friend BigInt operator+(const BigInt& obj1, const BigInt& obj2);
    friend BigInt operator-(const BigInt& obj1, const BigInt& obj2);
    friend BigInt operator+(const BigInt& obj1, int32_t obj2);
    friend BigInt operator-(const BigInt& obj1, int32_t obj2);
    friend BigInt operator*(const BigInt& obj1, const BigInt& obj2);
    friend BigInt operator*(const BigInt& obj1, int32_t obj2);
    friend bool operator==(const BigInt& obj1, const BigInt& obj2);
    friend bool operator!=(const BigInt& obj1, const BigInt& obj2);
    friend bool operator<(const BigInt& obj1, const BigInt& obj2);
    friend bool operator>(const BigInt& obj1, const BigInt& obj2);
    friend bool operator<=(const BigInt& obj1, const BigInt& obj2);
    friend bool operator>=(const BigInt& obj1, const BigInt& obj2);
    friend std::ostream& operator<<(std::ostream& out, const BigInt& obj);
};

#endif
