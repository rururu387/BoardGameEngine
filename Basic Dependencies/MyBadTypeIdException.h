#pragma once
#include <exception>

class MyBadTypeIdEx : public std::exception
{
    char* str;
public:
    MyBadTypeIdEx(const char* str);
    MyBadTypeIdEx();
    virtual const char* what() const throw()
    {
        return str;
    }
};

MyBadTypeIdEx::MyBadTypeIdEx() : std::exception()
{}

MyBadTypeIdEx::MyBadTypeIdEx(const char* _str) : std::exception()
{
    str = const_cast<char*>(_str);
}
