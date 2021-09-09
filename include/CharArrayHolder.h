#ifndef CHAR_ARRAY_HOLDER_H
#define CHAR_ARRAY_HOLDER_H

#include <algorithm>
#include "BaseHolder.h"

class CharArrayHolder : public BaseHolder<char[10]> 
{
public: 
    CharArrayHolder(char c_arr[10]) 
    {
        std::copy(c_arr, c_arr + 10, thing);
    }
};

#endif
