# inno_ogtc

## Description
Test task to Inno Oil and Gas Technology Center.

## Setup and run guide
<ol>
<li>git clone git@github.com:ummagumm-a/inno_ogtc.git</li>
<li>mkdir build && cd build</li>
<li>cmake ..</li>
<li>cmake --build .</li>
<li>./inno_ogtc</li>
</ol>

##Code description
First part of the task is to create a simple hierarchy of container classes. It is done in classes *Holder.

Second part is to create a tree data structure holding pointers to the base class for holders BaseHolder. 
I've created a class Tree containing a node element and a vector of its children (which are Tree*).

Third part is to save and to recover the tree. I've implemented an algorithm of saving tree contents and structure to 
a text file outtree.txt. Each line of this file describes a node in the tree in the format:
*<node_id> <parent_id> <type of element in the node> <value of the element in the node>*. Function `load()` then recovers
the tree from this file.
