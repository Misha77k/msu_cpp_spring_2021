#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

struct MyError;
struct MyError
{
    std::string message_;
    MyError(const std::string message): message_(message)
    {
    }
};

std::ostream& operator<<(std::ostream& out, const MyError& err);
std::ostream& operator<<(std::ostream& out, const MyError& err)
{
    out << err.message_;
    return out;
}

template <class T>
std::string args_to_string(const T &a) {
    std::stringstream tmp;
    tmp << a;
    std::string res;
    tmp >> res;
    return res;
}

template<class... ArgsT>
std::string format(std::string str, ArgsT&&... args);
template<class... ArgsT>
std::string format(std::string str, ArgsT&&... args)
{
    int count = 0;
    size_t i = 0;
    std::string s = "";
    std::vector<std::string> res {args_to_string(std::forward<ArgsT> (args))...};
    std::string result = "";
    while (i < str.length()) {
        if (str[i] == '{') {
            if (i != str.length() - 2) {
                count++;
                size_t k = i + 1;
                while (str[k] != '}') {
                    if (!isdigit(str[k]))
                        throw MyError("ERR1: Wrong Using of {}");
                    s = s + str[k];
                    k ++;
                }
                if (k != i + 1) {
                    size_t num = atoi(s.c_str());
                    if (num < res.size()) {
                        result += res[num];
                        i = k + 1;
                        s = "";
                    }
                    else throw MyError("ERR2: Wrong Argument in {}");
                }
                else throw MyError("ERR3: No Argument");
            }
            else throw MyError("ERR4: Wrong Using of {}");
        }
        else {
            if (str[i] != '}') {
                result += str[i];
                i++;
            } 
            else throw MyError("ERR5: Wrong Using of }");
        }
    }
    return result;
}
