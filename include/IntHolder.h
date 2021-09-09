#ifndef INT_HOLDER_H
#define INT_HOLDER_H

#include "BaseHolder.h"

class IntHolder : public BaseHolder<int> 
{
public:
    IntHolder(int i) : BaseHolder(i) {};
};

#endif
