#include <iostream>

#include "Tree.h"

using namespace std;


// add an element as a child of existing node
// returns the address of the new node
shared_ptr<Node> Tree::add_elem(const shared_ptr<BaseHolder>& elem,
                                const shared_ptr<Node>& node)
{
    auto new_node = make_shared<Node>(); 
    new_node->el = elem;
    node->children.push_back(new_node);

    t_size++;
    return new_node;
}

// use when adding very first element
// otherwise does nothing
// returns the address of the new node
shared_ptr<Node> Tree::init(const shared_ptr<BaseHolder>& elem)
{
    if (non_init)
    {
        head->el = elem;
        non_init = false;

        return head;
    }

    return nullptr;
}

// a help function for traverse
void traverse_help(const shared_ptr<Node>& node) 
{
    node->el->showThing(cout);

    if (!node->children.empty())
        for (int i = 0; i < node->children.size(); ++i)
            traverse_help(node->children[i]);
}

// perform a pre-order traversal on the tree,
// printing each value containing in the node
void Tree::traverse() const
{
    traverse_help(head);
}

void save_tree_help(ofstream& os, int id, int pid) {}

void Tree::save_tree(string filename) const
{
    ofstream outfile(filename);
    if (outfile.is_open())
    {
    }
}
        


// return size of the tree
size_t Tree::size() const
{
    return t_size;
}
