#ifndef STR_PRAC_H_
#define STR_PRAC_H_
#include <iostream>
using std::istream;
using std::ostream;

class String
{
    private:
        char *str;
        int len;
        static int num_str;
        static const int CINLIM = 80;
    public:
        String(const char *s);
        String();
        String(const String &);
        ~String();

        int length() const { return len; }
        static int HowMany();

        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char &operator[](int i) const;

        friend bool operator<(const String &st1, const String &st2);
        friend bool operator>(const String &st1, const String &st2);
        friend bool operator==(const String &st1, const String &st2);
        friend ostream & operator<<(ostream &os, String &st2);
        friend istream &operator>>(istream &is, String &st2);
};

#endif