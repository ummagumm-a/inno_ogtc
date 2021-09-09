#include <iostream>
#include "Utils.h"

void Utils::print_arr(const char arr[10]) 
{
    for (int i = 0; i < 10; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

