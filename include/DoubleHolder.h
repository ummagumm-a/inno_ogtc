#ifndef DOUBLE_HOLDER_H
#define DOUBLE_HOLDER_H

#include "BaseHolder.h"

class DoubleHolder : public BaseHolder<double> 
{
public:
    DoubleHolder(double d) : BaseHolder(d) {}
};

#endif
