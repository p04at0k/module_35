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

/*
Цель задания

Поработать с новыми структурами данных.


Что нужно сделать

Так как std::unordered_set позволяет нам быстро определять, есть ли указанный ключ в контейнере, мы можем использовать его для фильтрации уникальных чисел.

Создайте лямбда-выражение, принимающее на вход std::vector<int>, в котором содержатся числа, которые могут повторяться. 
Внутри лямбды создайте unordered_set и при помощи него определяйте, сколько раз текущее число вам встречалось раньше. 
В результате верните std::unique_ptr<std::vector<int>>, содержащий числа без повторов. 
При проходе по контейнеру используйте новый формат цикла for и ключевое слово auto. 

*/