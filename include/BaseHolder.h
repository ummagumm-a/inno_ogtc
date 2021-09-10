#ifndef BASE_HOLDER_H
#define BASE_HOLDER_H

#include <iostream>

class BaseHolder
{
public:
    virtual ~BaseHolder() = 0;

    virtual void showThing(std::ostream& os) const = 0;
};

#endif
