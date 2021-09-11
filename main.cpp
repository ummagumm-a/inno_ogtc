#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <sstream>

#include "BaseHolder.h"
#include "IntHolder.h"
#include "CharArrayHolder.h"
#include "DoubleHolder.h"
#include "Tree.h" 

using namespace std;

// decode data that should be contained in each node
shared_ptr<BaseHolder> load_holder(const string& line_l)
{
    // create a pointer to the data
    shared_ptr<BaseHolder> b;
    // create a stream for simplicity
    stringstream is;
    is << line_l;

    string line;
    is >> line;

    // for each type of data read numbers or chars
    // and create an object of appropriate type
    if (line == "IntHolder:")
    {
        is >> line;
        b = make_shared<IntHolder>(stoi(line));
    }
    else if (line == "CharArrayHolder:")
    {
        char arr[10];
        for (int i = 0; i < 10; ++i)
        {
            is >> arr[i];
        }

        b = make_shared<CharArrayHolder>(arr);
    }
    else if (line == "DoubleHolder:")
    {
        is >> line;
        b = make_shared<DoubleHolder>(stod(line));
    }
    else
        cout << "skdfjlekw\n";

    return b;
}

// this function recursively restores a tree from a matrix with data.
shared_ptr<Tree> unserialize_help(vector<vector<string>> entries, int curr)
{
    // extract id of this node
    int id = stoi(entries[curr][0]);
    
    // decode the info containing in this node
    shared_ptr<BaseHolder> b = load_holder(entries[curr][2]);

    // create a node
    shared_ptr<Tree> t = make_shared<Tree>(b);

    // for each child of this node, decode it and add to children
    for (int i = 0; i < entries.size(); ++i)
        if (stoi(entries[i][1]) == id)
            t->children.push_back(unserialize_help(entries, i));

    // return a pointer to the decoded node
    return t;
}

// this function breaks data in the file into a matrix
// where each row has the form { id, parent_id, node_data }
// and calls a helper function which then decodes info in the matrix
shared_ptr<Tree> unserialize(std::istream& is)
{
    string id, 
           parent,
           line;
    
    vector<vector<string>> entries;
    while (is >> id >> parent)
    {
        getline(is, line);
        vector<string> tmp = { id, parent, line };
        entries.push_back(tmp);
    }

    return unserialize_help(entries, 0);
}

// this function saves the tree to a file
void save(string filename, shared_ptr<Tree> tree)
{
    ofstream outfile;
    outfile.open(filename);

    if (outfile.is_open())
        tree->serialize(outfile);

    outfile.close();              
}

// this function loads a tree from a file.
shared_ptr<Tree> load(string filename)
{
    ifstream infile;
    infile.open("outtree.txt");

    shared_ptr<Tree> l_tree;
    if (infile.is_open())
        l_tree = unserialize(infile);

    infile.close();

    return l_tree;
}

// here I create a sample tree as shown on the picture.
shared_ptr<Tree> create_sample_tree()
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

    return tree1;
}

int main()
{
//    auto tree = create_sample_tree();
//    save("outtree.txt", tree);

    auto tree = load("outtree.txt");

    tree->traverse();

    return 0;
}

