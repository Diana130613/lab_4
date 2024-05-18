#ifndef String_H
#define String_H
#include <iostream>
using namespace std;

class String {
protected:
    char* data;
    int length;
    static int stringCopyConstructorCalls;
public:
    String() : data(nullptr), length(0) {}

    String(const char* str) 
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }

    String(char c) 
    {
        length = 1;
        data = new char[length + 1];
        data[0] = c;
        data[1] = '\0';
    }

    String(const String& other) 
    {
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
        stringCopyConstructorCalls++;
    }

    int getLength() const 
    {
        return length;
    }

    void clear() 
    {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    virtual ~String() 
    {
        delete[] data;
    }
};
#endif