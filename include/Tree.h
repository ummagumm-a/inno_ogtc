#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>

#include "BaseHolder.h"

struct Node
{
    template <typename T>
    std::shared_ptr<BaseHolder<T>> el;
    template <typename T>
    std::vector<std::shared_ptr<Node<T>>> children;
};

class Tree
{
public:
    Tree() : t_size(0) {}

    template <typename T>
    std::shared_ptr<Node<T>> add_elem(const std::shared_ptr<BaseHolder<T>>& elem,
                                      const std::shared_ptr<Node<T>>& node);

    template <typename T>
    std::shared_ptr<Node<T>> init(const std::shared_ptr<BaseHolder<T>>& elem);

    size_t size() const;
private:
    template <typename T>
    Node<T> head;

    size_t t_size;
};

#endif
