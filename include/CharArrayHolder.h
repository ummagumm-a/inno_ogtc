#ifndef CHAR_ARRAY_HOLDER_H
#define CHAR_ARRAY_HOLDER_H

#include <algorithm>
#include <iostream>

#include "BaseHolder.h"

class CharArrayHolder : public BaseHolder
{
public: 
    CharArrayHolder(char c_arr[10]) 
    {
        std::copy(c_arr, c_arr + 10, thing);
    }

    void showThing(std::ostream& os) const
    {
        for (int i = 0; i < 10; ++i)
            os << thing[i] << " ";
        os << "\n";
    }

    void serialize(std::ostream& os) const
    {
        os << "CharArrayHolder: ";
        showThing(os);
    }
private:
    char thing[10];
};

#endif
