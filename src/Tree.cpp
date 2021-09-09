#include "Tree.h"

using namespace std;

// add an element as a child of existing node
// returns the address of the new node
shared_ptr<Node<T>> Tree::add_elem(const shared_ptr<BaseHolder<T>>& elem,
                                   const shared_ptr<Node<T>>& node);
{
    auto new_node = make_shared<Node<T>>(); 
    new_node->el = elem;
    node->children.push_back(new_node);

    size++;
    return new_node;
}

// use when adding very first element
// otherwise does nothing
// returns the address of the new node
shared_ptr<Node<T>> Tree::init(const shared_ptr<BaseHolder<T>>& elem)
{
    if (head.children.empty())
    {
        auto new_node = make_shared<Node<T>>(); 
        new_node->el = elem;
        head->children.push_back(new_node);
    }
};

size_t Tree::size() const
{
    return t_size;
}
