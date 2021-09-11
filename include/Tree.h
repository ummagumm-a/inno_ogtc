#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>

#include "BaseHolder.h"

using namespace std;

class Tree
{
public:
    Tree() = default;

    Tree(const shared_ptr<BaseHolder>& elem) 
        : 
        el(elem)
    {}

    // add a child to this node
    void add_elem(const shared_ptr<Tree>& elem);

    // perform a pre-order traversal on this tree,
    // printing contents of each node
    void traverse() const;

    // a helper function for serialization
    void serialize_help(ostream& os, int parent) const;

    // save this tree to a text file
    void serialize(std::ostream& os) const;

public:
    // element in the node
    shared_ptr<BaseHolder> el;
    // children of the node
    vector<shared_ptr<Tree>> children;
};

#endif
