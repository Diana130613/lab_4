#include <iostream>
#include <cstring>
#include "String.h"
#include "Decimal_String.h"

int main() {
    String* strings[4];

    strings[0] = new String("Hello");
    strings[1] = new Decimal_String("42");
    strings[2] = new String('X');
    strings[3] = new Decimal_String("15");

    for (int i = 0; i < 4; ++i) 
    {
        cout << "String " << i << " length: " << strings[i]->getLength() << endl;
    }

    for (int i = 0; i < 4; ++i) 
    {
        delete strings[i];
    }
    return 0;
}