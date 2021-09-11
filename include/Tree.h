#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>
#include <string>

//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/serialization/export.hpp>
//#include <sstream>

#include "BaseHolder.h"

using namespace std;
//std::stringstream ss;

class Tree
{
public:
    Tree(const shared_ptr<BaseHolder>& elem) 
        : 
        el(elem)
    {}
    

    void add_elem(const shared_ptr<Tree>& elem);

    void traverse() const;

    size_t bin_size() const;

    void serialize_help(ostream& os, int parent) const;

    void serialize(std::ostream& os) const;

private:
    shared_ptr<BaseHolder> el;
    vector<shared_ptr<Tree>> children;
};

#endif
