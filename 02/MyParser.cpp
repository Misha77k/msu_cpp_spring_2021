#include "MyParser.hpp"

void TokenParser::SetStartCallback(std::function<void ()> callback)
{
    start_callback_func = callback;
} 

void TokenParser::SetEndCallback(std::function<void ()> callback)
{
    end_callback_func = callback;
}

void TokenParser::SetDigitTokenCallback(std::function<void (const uint64_t &token)> callback)
{
    digit_callback_func = callback;
}

void TokenParser::SetStringTokenCallback(std::function<void (const std::string &token)> callback)
{
    string_callback_func = callback;
}

bool TokenParser::IsDigit(const std::string &token)
{
    if (token.find_first_not_of("0123456789") == std::string::npos) {
        return true;
    }
    else return false;
}

std::string TokenParser::GetToken(const std::string &str)
{
    pos = str.find_first_of(" \t\n", begin);
    if (pos != std::string::npos) {
        size_t delta = pos - begin;
        begin = pos + 1;
        return str.substr(pos-delta, delta);
    }
    return str.substr(begin, str.size()-begin);   
}

void TokenParser::Parse(const std::string &str)
{
    std::string token;
    if (start_callback_func)
        start_callback_func();

    while (pos != std::string::npos) {
        token = GetToken(str);
        if (!token.empty()) {
            if (IsDigit(token)) {
                uint64_t num = std::stoull(token, nullptr, 10);
                if (digit_callback_func)
                    digit_callback_func(num);
            }
            else {
                if (string_callback_func)
                    string_callback_func(token);
                }
            }
    }

    if (end_callback_func)
        end_callback_func();
}

