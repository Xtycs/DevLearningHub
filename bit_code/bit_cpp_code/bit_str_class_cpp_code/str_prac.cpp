#include <cstring>
#include "str_prac.h"
using std::cin;
using std::cout;

int String::num_str = 0;

String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_str++;
}

String::String()
{
    len = 4;
    str = new char[1];
    std::strcpy(str, '\0');
    num_str++;
}

String::String(const String &s)
{
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    num_str++;
}

String::~String()
{
    delete[] str;
    num_str--;
}

int String::HowMany()
{
    return num_str;
}

String & String::operator=(const String &st)
{
    if (*this == st)
    {
        return *this;
    }
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char *str2)
{
    delete[] str;
    len = std::strlen(str2);
    str = new char[len + 1];
    std::strcpy(str, str2);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char& String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &str2)//友函数不要写解析符
{
    return (std::strcmp(st1.str, str2.str) < 0);
}

bool operator>(const String &str1, const String &str2)
{
    return str2 < str1;
}

bool operator==(const String &str1, const String &str2)
{
    return (std::strcmp(str1.str, str2.str) == 0);
}

ostream & operator<<(ostream &os, String &st2)
{
    os << st2.str;
    return os;
}

//quick and dirty String input
istream & operator>>(istream & is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
    {
        st = temp;//temp=st是错误的
    }

    while (is && is.get() != '\n')
    {
        continue;
    }
    return is;
}