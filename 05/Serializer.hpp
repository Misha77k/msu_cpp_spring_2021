#pragma once
#include <iostream>
#include <sstream>

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static constexpr char Separator = ' ';
public:
    explicit Serializer(std::ostream& out)
        : out_(out)
    {
    }

    template <class T>
    Error save(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT... args)
    {
        return process(args...);
    }
private:
    std::ostream& out_;
    Error func(bool arg)
    {
        if (arg == true)
            out_ << "true" << Separator;
        if (arg == false)
            out_ << "false" << Separator;
        return Error::NoError;
    }

    Error func(uint64_t arg)
    {
        out_ << arg << Separator;
        return Error::NoError;
    }

    template<class T, class... ArgsT>
    Error process(T obj, ArgsT... args)
    {
        func(obj);
        return process(args...);
    } 

    template<class T>
    Error process(T x)
    {
        return func(x);
    }
};

class Deserializer
{
public:
    explicit Deserializer(std::istream& in)
        : in_(in)
    {
    }

    template <class T>
    Error load(T& object)
    {
        return object.deserialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT&... args)
    {
        return process(args...);
    }
private:
    std::istream& in_;
    Error func(bool& value)
    {
        std::string text;
        in_ >> text;
        if (text == "true") {
            value = true;
            return Error::NoError;
        }
        if (text == "false") {
            value = false;
            return Error::NoError;
        }
        return Error::CorruptedArchive;
        
    }
    Error func(uint64_t& value)
    {
        std::string text;
        in_ >> text;
        if (text.find_first_not_of("0123456789") != std::string::npos)
            return Error::CorruptedArchive;
        try
        {
            value = std::stoull(text);
            return Error::NoError;
        }
        catch(...)
        {
            return Error::CorruptedArchive;
        }
             
    }
    template<class T, class... ArgsT>
    Error process(T& obj, ArgsT&... args)
    {
        if (func(obj) == Error::CorruptedArchive)
            return Error::CorruptedArchive;
        return process(args...);
    }
    template<class T>
    Error process(T& x)
    {
        return func(x);
    }
};
