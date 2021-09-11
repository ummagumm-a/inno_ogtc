#include <iostream>

#include "Tree.h"

using namespace std;

// add an element as a child of existing node
// returns the address of the new node
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

size_t Tree::bin_size() const
{
    auto size = sizeof(Tree) 
              + sizeof(el) 
              + sizeof(*el) 
              + sizeof(vector<shared_ptr<Tree>>) 
              + sizeof(shared_ptr<Tree>) * children.size();

    if (!children.empty())
        for (const auto& child : children)
            size += child->bin_size();

    cout << size << endl;
    return size;
}

void Tree::serialize_help(ostream& os, int parent) const
{
    static int count = 0;
    int id = ++count;

    os << id << " " << parent << " ";

    el->serialize(os);

    for (const auto& child : children)
    {
        child->serialize_help(os, id);
    }
}

void Tree::serialize(std::ostream& os) const
{
    serialize_help(os, 0);
}


