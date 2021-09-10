#ifndef DOUBLE_HOLDER_H
#define DOUBLE_HOLDER_H

#include <iostream>

#include "BaseHolder.h"

class DoubleHolder : public BaseHolder
{
public:
    DoubleHolder(double d) : thing(d) {}

    void showThing(std::ostream& os) const
    {
        os << thing << std::endl;
    }
private:
    double thing;
};

#endif
