#include <iostream>
#include "Utils.h"
#include "BaseHolder.h"
#include "IntHolder.h"
#include "CharArrayHolder.h"
#include "DoubleHolder.h"

using namespace std;

int main()
{
    BaseHolder<int>* i1 = new IntHolder(5);
    char arr1[10] = "peepeepoo";
    BaseHolder<char[10]>* ca1 = new CharArrayHolder(arr1);
    BaseHolder<double>* d1 = new DoubleHolder(5.8);
    BaseHolder<double>* d2 = new DoubleHolder(5.8);
    
    cout << i1->getThing() << endl;
    Utils::print_arr(ca1->getThing());
    cout << d1->getThing() << endl;
    cout << d2->getThing() << endl;
    

    return 0;
}

