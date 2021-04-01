#ifndef HPP_MYPARSER
#define HPP_MYPARSER

#include <iostream>
#include <string>
#include <functional>

class TokenParser
{
public:   
    size_t begin = 0;
    size_t pos = 0;
    std::function<void ()> start_callback_func;
    std::function<void ()> end_callback_func;
    std::function<void (const int64_t &token)> digit_callback_func;
    std::function<void (const std::string &token)> string_callback_func;

    TokenParser() = default;
    
    void SetStartCallback(std::function <void ()> callback);
    void SetEndCallback(std::function <void ()> callback);
    void SetDigitTokenCallback(std::function <void (const int64_t &token)> callback);
    void SetStringTokenCallback(std::function <void (const std::string &token)> callback);
    bool IsDigit(const std::string &token);
    std::string GetToken(const std::string &str);
    void Parse(const std::string &str);
};

#endif
