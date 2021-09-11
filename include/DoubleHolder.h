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

    void serialize(std::ostream& os) const
    {
        os << "DoubleHolder: ";
        os << thing << '\n';
    }

private:
    double thing;
};

#endif
