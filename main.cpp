#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "BaseHolder.h"
#include "IntHolder.h"
#include "CharArrayHolder.h"
#include "DoubleHolder.h"
#include "Tree.h" //#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>

using namespace std;
/*
BOOST_CLASS_EXPORT(IntHolder);
BOOST_CLASS_EXPORT(DoubleHolder);
BOOST_CLASS_EXPORT(CharArrayHolder);

void save(const shared_ptr<Tree>& tree)
{
    text_oarchive oa{ss};
    oa << tree;
} 

shared_ptr<Tree> load()
{
    text_iarchive ia{ss};
    shared_ptr<Tree> tree;
    ia >> tree; 
    tree->traverse();

    return tree;
}

*/

//void save(string filename)
//{
//    ofstream outfile;
//    outfile.open(filename);
//
//    if (outfile.is_open())
//    {
//        i1->serialize(outfile);
//        i2->serialize(outfile);
//        i3->serialize(outfile);
//        i4->serialize(outfile);
//        i5->serialize(outfile);
//        ca1->serialize(outfile);
//        ca2->serialize(outfile);
//        ca3->serialize(outfile);
//        ca4->serialize(outfile);
//        d1->serialize(outfile);
//    }
//    outfile.close();
//}

void load(string filename)
{
    ifstream infile;
    infile.open(filename);

    string line;
    if (infile.is_open())
    {
        while (infile >> line)
        {
            if (line == "IntHolder:")
            {
                infile >> line;
                shared_ptr<BaseHolder> i = make_shared<IntHolder>(stoi(line));
                i->showThing(cout);
            }
            else if (line == "CharArrayHolder:")
            {
                char arr[10];
                for (int i = 0; i < 10; ++i)
                {
                    infile >> arr[i];
                }

                shared_ptr<BaseHolder> i = make_shared<CharArrayHolder>(arr);
                i->showThing(cout);
            }
            else if (line == "DoubleHolder:")
            {
                infile >> line;
                
                shared_ptr<BaseHolder> i = make_shared<DoubleHolder>(stod(line));
                i->showThing(cout);
            }
            else
                cout << "skdfjlekw\n";
        }
    }
    
    infile.close();
}


int main()
{
//    load("outfile.txt");
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

//    ofstream outfile;
//    outfile.open("outfile.txt");
//
//    if (outfile.is_open())
//    {
//        i1->serialize(outfile);
//        i2->serialize(outfile);
//        i3->serialize(outfile);
//        i4->serialize(outfile);
//        i5->serialize(outfile);
//        ca1->serialize(outfile);
//        ca2->serialize(outfile);
//        ca3->serialize(outfile);
//        ca4->serialize(outfile);
//        d1->serialize(outfile);
//    }
//    outfile.close();

//    cout << sizeof(*i1) << endl;
//    cout << sizeof(*ca1) << endl;
//    cout << sizeof(*d1) << endl;

//    cout << sizeof(IntHolder) << endl;
//    cout << sizeof(CharArrayHolder) << endl;
//    cout << sizeof(DoubleHolder) << endl;

    auto tree1 = make_shared<Tree>(i1);
    auto tree2 = make_shared<Tree>(i2);
    auto tree3 = make_shared<Tree>(i3);
    auto tree4 = make_shared<Tree>(i4);
    auto tree5 = make_shared<Tree>(i5);
    auto tree6 = make_shared<Tree>(ca1);
    auto tree7 = make_shared<Tree>(ca2);
    auto tree8 = make_shared<Tree>(ca3);
    auto tree9 = make_shared<Tree>(ca4);
    auto tree10 = make_shared<Tree>(d1);

    tree1->add_elem(tree5);
    tree1->add_elem(tree7);
    tree1->add_elem(tree10);

    tree5->add_elem(tree6);

    tree10->add_elem(tree8);
    tree10->add_elem(tree3);
    tree10->add_elem(tree4);

    tree6->add_elem(tree9);
    tree6->add_elem(tree2);

    ofstream outfile;
    outfile.open("outtree.txt");
    if (outfile.is_open())
        tree1->serialize(outfile);
    outfile.close();
//    tree1->traverse();
//
//    tree1->bin_size();

//    string path = "saved_tree.txt";
//    ofstream fout;
//    fout.open(path, ofstream::app);
//
//    if (fout.is_open())
//    {
//        fout.write((char*) &tree, tree.bin_size());
//    }
//
//    fout.close();

    return 0;
}

