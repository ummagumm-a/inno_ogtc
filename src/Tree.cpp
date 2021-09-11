#include <iostream>

#include "Tree.h"

using namespace std;

// add an element as a child of existing node
void Tree::add_elem(const shared_ptr<Tree>& elem)
{
    children.push_back(elem);
}

// perform a pre-order traversal on the tree,
// printing each value containing in the node
void Tree::traverse() const
{
    el->showThing(cout);

    if (!children.empty())
        for (const auto& child : children)
            child->traverse();
}

//  a helper function for serialization
void Tree::serialize_help(ostream& os, int parent) const
{
    // a counter for id's of the nodes
    static int count = 0;
    int id = ++count;

    // write id of the node and id of its parent
    os << id << " " << parent << " ";

    // write info about element
    el->serialize(os);

    // write info for each of the children
    for (const auto& child : children)
        child->serialize_help(os, id);
}

// function for serialization
void Tree::serialize(std::ostream& os) const
{
    // just call helper function
    serialize_help(os, 0);
}


