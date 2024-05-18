#ifndef Decimal_String_H
#define Decimal_String_H
#include "String.h"

class Decimal_String : public String 
{
public:
    Decimal_String() : String() {}
    Decimal_String(const char* str) : String(str) 
    {
        if (!isValid(str)) 
        {
            clear();
        }
    }
    Decimal_String(const Decimal_String& other) : String(other) {}
    ~Decimal_String() {}

    bool canBeInt() const 
    {
        for (int i = 0; i < length; ++i) {
            if (!isdigit(data[i])) {
                return false;
            }
        }
        return true;
    }
    Decimal_String& operator=(const Decimal_String& other) 
    {
        if (this != &other) {
            clear();
            String::operator=(other);
        }
        return *this;
    }

    Decimal_String operator-(const Decimal_String& other) const 
    {
        char* result = new char[length + 1]();
        int carry = 0;

        for (int i = length - 1; i >= 0; --i) {
            int diff = (data[i] - '0') - carry;

            if (i < other.length) 
            {
                diff -= (other.data[i] - '0');
            }

            if (diff < 0) 
            {
                diff += 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            result[i] = diff + '0';
        }
        Decimal_String result_str(result);
        delete[] result;
        return result_str;
    }
private:
    bool isValid(const char* str) 
    {
        for (int i = 0; i < length; ++i) 
        {
            if (!isdigit(str[i])) 
            {
                return false;
            }
        }
        return true;
    }
};
#endif