#ifndef INT_HOLDER_H
#define INT_HOLDER_H

#include <iostream>

#include "BaseHolder.h"

class IntHolder : public BaseHolder
{
public:
    IntHolder(int i) : thing(i) {};

    void showThing(std::ostream& os) const
    {
        os << thing << std::endl;
    }

private:
    int thing;
};

#endif
