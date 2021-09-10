#include <iostream>
#include <fstream>
#include <memory>

#include "BaseHolder.h"
#include "IntHolder.h"
#include "CharArrayHolder.h"
#include "DoubleHolder.h"
#include "Tree.h"

using namespace std;

int main()
{
    char arr1[10] = "FULCRUM";
    char arr2[10] = "C++";
    char arr3[10] = "TEST";
    char arr4[10] = "LINUX";
    shared_ptr<BaseHolder> i1 = make_shared<IntHolder>(1);
    shared_ptr<BaseHolder> i2 = make_shared<IntHolder>(7);
    shared_ptr<BaseHolder> i3 = make_shared<IntHolder>(9);
    shared_ptr<BaseHolder> i4 = make_shared<IntHolder>(6);
    shared_ptr<BaseHolder> i5 = make_shared<IntHolder>(2011);

    shared_ptr<BaseHolder> ca1 = make_shared<CharArrayHolder>(arr1);
    shared_ptr<BaseHolder> ca2 = make_shared<CharArrayHolder>(arr2);
    shared_ptr<BaseHolder> ca3 = make_shared<CharArrayHolder>(arr3);
    shared_ptr<BaseHolder> ca4 = make_shared<CharArrayHolder>(arr4);

    shared_ptr<BaseHolder> d1 = make_shared<DoubleHolder>(3.14);

//    Tree tree;
//    auto n1 = tree.init(i1);
//
//    auto n2 = tree.add_elem(i5, n1);
//    auto n3 = tree.add_elem(ca2, n1);
//    auto n4 = tree.add_elem(d1, n1);
//
//    auto n5 = tree.add_elem(ca1, n2);
//    auto n6 = tree.add_elem(ca3, n4);
//    auto n7 = tree.add_elem(i3, n4);
//    auto n8 = tree.add_elem(i4, n4);
//
//    auto n9 = tree.add_elem(ca4, n5);
//    auto n10 = tree.add_elem(i2, n5);
//
//    tree.traverse();
    
    ofstream myfile("out.txt");
    if (myfile.is_open())
    {
        i1->showThing(cout);
        ca1->showThing(cout);
        d1->showThing(cout);
    }

    return 0;
}

