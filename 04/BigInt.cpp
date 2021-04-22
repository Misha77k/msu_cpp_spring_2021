#include "BigInt.hpp"


BigInt::BigInt(const std::string& str)
{
    if (str.empty()) {
        len = 0;
        sign = true;
        ptr = nullptr;
        std::cout << "empty" << std::endl;
    }
    else {
        std::string s = str;
        if (str[0] == '-') {
            sign = false;
            s = str.substr(1);
        }
        else sign = true;
        if ((str[0] == '-' && s[0] == '0') || (s.find_first_not_of("0123456789") != std::string::npos))
            throw std::invalid_argument("Incorrect Data");
        int ord = int(log10(base));
        if (s.length() % ord == 0)
            len = int(s.length() / ord);
        else len = int(s.length() / ord) + 1;
        int j = 0;
        int i = len;
        ptr = new int[len];
        for (i = len; i >= ord; i -= ord) {
            ptr[j] = atoi(s.substr(i - ord, ord).c_str());
            j += 1;
        }
    }
}

BigInt::BigInt(const BigInt& obj)
{
    len = obj.len;
    sign = obj.sign;
    ptr = new int[len];
    for (int i = 0; i < len; i++)
        ptr[i] = obj.ptr[i];
}

BigInt::BigInt(BigInt&& obj)
{
    len = obj.len;
    sign = obj.sign;
    ptr = obj.ptr;
    obj.ptr = nullptr;
    obj.sign = true;
    obj.len = 0;
}

BigInt::~BigInt()
{
    delete[] ptr;
}

BigInt BigInt::operator=(const BigInt& obj)
{
    len = obj.len;
    sign = obj.sign;
    if (ptr != nullptr)
        delete[] ptr;
    ptr = new int[len];
    for (int i = 0; i < len; i++) 
        ptr[i] = obj.ptr[i];
    return *this;
}

BigInt BigInt::operator=(int32_t obj)
{
    if (obj >= 0)
        sign = true;
    else sign = false;
    if (ptr != nullptr)
        delete[] ptr;
    len = 0;
    int32_t a = obj;
    while (obj) {
        a /= base;
        len++;
    }
    ptr = new int[len];
    for (int i = 0; i < len; i++) {
        ptr[i] = obj % base;
        obj /= base;
    }
    return *this;
}

BigInt BigInt::operator=(BigInt&& obj)
{
    if (&obj == this)
        return *this;
    if (ptr != nullptr)
        delete[] ptr;
    len = obj.len;
    sign = obj.sign;
    for (int i = 0; i < len; i++)
        ptr[i] = obj.ptr[i];
    obj.ptr = nullptr;
    return *this;
}

BigInt BigInt::operator-() const
{
    BigInt res(*this);
    res.sign = !sign;
    return res;
}

BigInt operator+(const BigInt& obj1, const BigInt& obj2)
{
    BigInt res;
    if (obj1.sign == obj2.sign) {
        res.len = std::max(obj1.len, obj2.len) + 1;
        if (obj1.sign)
            res.sign = true;
        else res.sign = false;
        int* new_ptr = new int[res.len];
        for (int i = 0; i < res.len; i++)
            new_ptr[i] = 0;
        for (int j = 0; j < std::min(obj1.len, obj2.len); j++) {
            int sum = obj1.ptr[j] + obj2.ptr[j];
            new_ptr[j] = (new_ptr[j] + sum) % res.base;
            if (sum >= res.base)
                new_ptr[j+1] += 1;
        }
        if (obj1.len > obj2.len) {
            for (int j = obj2.len; j < obj1.len; j++) {
                int sum = new_ptr[j] + obj1.ptr[j];
                new_ptr[j] = sum % res.base;
                if (sum >= res.base)
                    new_ptr[j+1] += 1;
            }
        }
        else {
            for (int j = obj1.len; j < obj2.len; j++) {
                int sum = new_ptr[j] + obj2.ptr[j];
                new_ptr[j] = sum % res.base;
                if (sum >= res.base)
                    new_ptr[j+1] += 1;
            }
        }
        if (new_ptr[res.len - 1] == 0)
            res.len -= 1;
        res.ptr = new int[res.len];
        for (int i = 0; i < res.len; i++)
            res.ptr[i] = new_ptr[i];
        delete[] new_ptr;
        return res;
    }
    else {
        if (obj1.sign) {
            return (obj1 - (-obj2));
        }
        else {
            return (obj2 - (-obj1));       
        }  
    }
}

BigInt operator-(const BigInt& obj1, const BigInt& obj2)
{
    BigInt res;
    if ((obj1.sign) && (!obj2.sign))
        return (obj1 + (-obj2));
    if ((!obj1.sign) && (obj2.sign)) {
        BigInt new_res = obj2 + (-obj1);
        return -new_res;
    }
    if (obj1 >= obj2) {
        res.sign = true;
    }
    else {
        res.sign = false;
    }
    res.len = std::max(obj1.len, obj2.len);
    int* new_ptr = new int[res.len];
    for (int i = 0; i < res.len; i++)
        new_ptr[i] = 0;
    if (((res.sign) && (obj1.sign)) || ((!res.sign) && (!obj2.sign))){
        for (int i = 0; i < std::min(obj1.len, obj2.len); i++) {
            if (obj1.ptr[i] >= obj2.ptr[i]) {
                new_ptr[i] += (obj1.ptr[i] - obj2.ptr[i]);
            }
            else {
                new_ptr[i] += (obj1.ptr[i] + res.base - obj2.ptr[i]);
                new_ptr[i+1] -= 1;
            }
        }
        if (obj1.len > obj2.len) {
            for (int j = obj2.len; j < obj1.len; j++) {
                if (obj1.ptr[j] >= -new_ptr[j]) {
                    int sum = new_ptr[j] + obj1.ptr[j];
                    new_ptr[j] = sum % res.base;
                }
                else {
                    int sum = new_ptr[j] + obj1.ptr[j] + res.base;
                    new_ptr[j] = sum % res.base;
                    new_ptr[j + 1] -= 1;
                }
            }
        }
        else {
            for (int j = obj1.len; j < obj2.len; j++) {
                int sum = new_ptr[j] + obj2.ptr[j];
                new_ptr[j] = sum % res.base;
            }
        }
    }
    else {
        for (int i = 0; i < std::min(obj1.len, obj2.len); i++) {
            if (obj2.ptr[i] >= obj1.ptr[i]) {
                new_ptr[i] += (obj2.ptr[i] - obj1.ptr[i]);
            }
            else {
                new_ptr[i] += (obj2.ptr[i] + res.base - obj1.ptr[i]);
                new_ptr[i+1] -= 1;
            }
        }
        if (obj2.len > obj1.len) {
            for (int j = obj1.len; j < obj2.len; j++) {
                if (obj2.ptr[j] >= -new_ptr[j]) {
                    int sum = new_ptr[j] + obj2.ptr[j];
                    new_ptr[j] = sum % res.base;
                }
                else {
                    int sum = new_ptr[j] + obj2.ptr[j] + res.base;
                    new_ptr[j] = sum % res.base;
                    new_ptr[j + 1] -= 1;
                }
            }
        }
        else {
            for (int j = obj2.len; j < obj1.len; j++) {
                int sum = new_ptr[j] + obj1.ptr[j];
                new_ptr[j] = sum % res.base;
            }
        }
    }
    int i = res.len - 1;
    while (new_ptr[i] == 0) {
        res.len -= 1;
        i -= 1;
    }
    res.ptr = new int[res.len];
    for (int i = 0; i < res.len; i++)
        res.ptr[i] = new_ptr[i];
    delete[] new_ptr;
    return res;
}

BigInt operator*(const BigInt& obj1, const BigInt& obj2)
{
    BigInt res;
    res.len = obj1.len + obj2.len;
    if (obj1.sign == obj2.sign)
        res.sign = true;
    else res.sign = false;
    if (((obj1.ptr[0] == 0) && (obj1.len == 1)) || ((obj2.ptr[0] == 0) && (obj2.len == 1))) {
        res.len = 1;
        res.ptr = new int[res.len];
        res.ptr[0] = 0;
        return res;
    }
    int* new_ptr = new int[res.len];
    for (int i = 0; i < res.len; i++)
        new_ptr[i] = 0;
    int shift = 0;
    for (int i = 0; i < obj2.len; i++) {
        shift = 0;
        for (int j = 0; j < obj1.len; j++) {
            int t = obj1.ptr[j] * obj2.ptr[i] + shift;
            new_ptr[i + j] += t % res.base;
            if (new_ptr[i + j] >= res.base) {
                new_ptr[i + j] %= res.base;
                new_ptr[i + j + 1] += 1;
            }
            shift = t / res.base;
        }
        new_ptr[i + obj1.len] += shift;
    }
    int i = res.len - 1;
    while (new_ptr[i] == 0) {
        res.len -= 1;
        i -= 1;
    }
    res.ptr = new int[res.len];
    for (int i = 0; i < res.len; i++)
        res.ptr[i] = new_ptr[i];
    delete[] new_ptr;
    return res;  
}
BigInt operator+(const BigInt& obj1, int32_t obj2)
{
    std::string s = std::to_string(obj2);
    BigInt new_obj2(s);
    return (obj1 + new_obj2);
}

BigInt operator-(const BigInt& obj1, int32_t obj2)
{
    std::string s = std::to_string(obj2);
    BigInt new_obj2(s);
    return (obj1 - new_obj2);
}

BigInt operator*(const BigInt& obj1, int32_t obj2)
{
    std::string s = std::to_string(obj2);
    BigInt new_obj2(s);
    return (obj1 * new_obj2);
}

bool operator==(const BigInt& obj1, const BigInt& obj2)
{
    if ((obj1.len != obj2.len) || (obj1.sign != obj2.sign))
        return false;
    for (int i = 0; i < obj1.len; i++) {
        if (obj1.ptr[i] != obj2.ptr[i])
            return false;
    }
    return true;
}

bool operator<(const BigInt& obj1, const BigInt& obj2)
{
    if ((!obj1.sign) && (obj2.sign))
        return true;
    if ((!obj2.sign) && (obj1.sign))
        return false;
    if ((obj1.sign) && (obj1.sign == obj2.sign)) {
        if (obj2.len > obj1.len)
            return true;
        if (obj1.len > obj2.len)
            return false;
        for (int i = obj1.len - 1; i >= 0; i--) {
            if (obj2.ptr[i] > obj1.ptr[i])
                return true;
            if (obj1.ptr[i] > obj2.ptr[i])
                return false;
        }
    }
    if ((!obj1.sign) && (obj1.sign == obj2.sign)) {
        if (obj2.len > obj1.len)
            return false;
        if (obj1.len > obj2.len)
            return true;
        for (int i = obj1.len - 1; i >= 0; i--) {
            if (obj2.ptr[i] > obj1.ptr[i])
                return false; 
            if (obj1.ptr[i] > obj2.ptr[i])
                return true;
        }
    }
    return false;
}

bool operator<=(const BigInt& obj1, const BigInt& obj2)
{
    if ((!obj1.sign) && (obj2.sign))
        return true;
    if ((!obj2.sign) && (obj1.sign))
        return false;
    if ((obj1.sign) && (obj1.sign == obj2.sign)) {
        if (obj2.len > obj1.len)
            return true;
        if (obj1.len > obj2.len)
            return false;
        for (int i = obj1.len - 1; i >= 0; i--) {
            if (obj2.ptr[i] > obj1.ptr[i])
                return true;
            if (obj1.ptr[i] > obj2.ptr[i])
                return false;
        }
    }
    if ((!obj1.sign) && (obj1.sign == obj2.sign)) {
        if (obj2.len > obj1.len)
            return false;
        if (obj1.len > obj2.len)
            return true;
        for (int i = obj1.len - 1; i >= 0; i--) {
            if (obj2.ptr[i] > obj1.ptr[i])
                return false;
            if (obj1.ptr[i] > obj2.ptr[i])
                return true;
        }
    }
    return true;
}

bool operator!=(const BigInt& obj1, const BigInt& obj2)
{
    return !(obj1 == obj2);
}

bool operator>(const BigInt& obj1, const BigInt& obj2)
{
    return (-obj1 <= -obj2);
}

bool operator>=(const BigInt& obj1, const BigInt& obj2)
{
    return (-obj1 < -obj2);
}

std::string get_str_from_bigint(const BigInt& obj1)
{
    std::string s;
    if (!obj1.sign)
        s = "-";
    else s = "";
    for (int i = 0; i < obj1.len; i++) {
        s = s + std::to_string(obj1.ptr[obj1.len - 1 - i]);
    }
    return s;
}

std::ostream& operator<<(std::ostream& out, const BigInt& obj)
{
    std::string s;
    if (!obj.sign) {
        s = "-";
    }
    else s = "";
    for (int i = 0; i < obj.len; i++) {
        s = s + std::to_string(obj.ptr[obj.len - 1 - i]);
     }
     out << s << std::endl;
     return out;
}
