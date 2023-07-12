#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>


auto remove_dublicates = [](const std::vector<int> &values)
{
    std::unordered_set<int> numbers;
    auto result = std::make_unique<std::vector<int>>();

    numbers.insert(values.begin(),values.end());

    for(const auto& value : numbers)
    {
        if(numbers.count(value) == 1) result->push_back(value);
    }

    return result;
};



int main()
{
    std::vector<int> vec = {1,7,10,4,4,6,7,1,9,10};   

    auto unique_numbers = remove_dublicates(vec);

    for (const auto& number : *unique_numbers)
    {
        std::cout << number << " ";
    }
    std::cout << "\n";
}

