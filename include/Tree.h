#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>
#include <string>

#include "BaseHolder.h"

using namespace std;

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

private:
    shared_ptr<BaseHolder> el;
    vector<shared_ptr<Tree>> children;
};

#endif
