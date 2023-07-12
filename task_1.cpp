#include <initializer_list>
#include <iostream>

int main()
{
    auto numbers  = {1,2,3,4,5};


    for (const auto &i : numbers)
    {
        std::cout << i << " ";
    }
}
