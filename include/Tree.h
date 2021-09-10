#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>
#include <string>

#include "BaseHolder.h"

using namespace std;

struct Node
{
    shared_ptr<BaseHolder> el;
    vector<shared_ptr<Tree>> children;
};

class Tree
{
public:
    Tree() 
        : t_size(0),
          non_init(true),
          head(make_shared<Node>())
    {}

    shared_ptr<Node> add_elem(const shared_ptr<BaseHolder>& elem,
                              const shared_ptr<Node>& node);

    shared_ptr<Node> init(const shared_ptr<BaseHolder>& elem);

    void traverse() const;

    void save_tree(string filename) const;

    size_t size() const;
private:
    shared_ptr<Tree> head;

    size_t t_size;
    bool non_init;
};

#endif
