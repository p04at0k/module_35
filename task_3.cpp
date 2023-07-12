#include <iostream>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;

auto recursiveGetFileNamesByExtension = [](const fs::path &path,const std::string &extension)
{

    for(const auto& p: fs::recursive_directory_iterator(path))
    {
        if (fs::is_regular_file(path) == false && p.path().extension().compare(extension) == false)
        {
           std::cout <<  fs::path(p).filename() << "\n";
        }
    }  
};

int main()
{
    bool input = true;
    std::string path_name,extension;

    std::cout << "Input your path: \n";
    std::cin >> path_name;
    std::cout << "Input desired extension: \n";
    std::cin >> extension;
    std::cout << "\n";

    while(input)
    {
        try
        {
            if (fs::exists(path_name) == false) throw std::invalid_argument("Wrong path!");

            recursiveGetFileNamesByExtension(path_name,extension);
            input = false;
        }

        catch (const std::invalid_argument& x)
        {
            std::cout << x.what() << "\n";
            std::cout << "Input the correct path: \n";
            std::cin >> path_name;
            std::cout << "\n";
        }

    }


    
}


/*
Поработать с файловой системой, используя новую библиотеку std::filesystem.


Что нужно сделать

В нашем арсенале теперь есть возможность рекурсивно проходить по каталогам,
то есть получить список всех файлов, каталогов (и подкаталогов), которые содержатся по указанному пути. 
 Для этого в стандартной библиотеке есть std::filesystem::recursive_directory_iterator, принимающий на вход путь, который он будет обходить рекурсивно. 
 На каждом шаге он будет выдавать очередной путь, это может быть как каталог, так и обычный файл. Например, код


for(auto& p: fs::recursive_directory_iterator("D:\\dir1"))
        std::cout << p.path() << '\n';

выведет полные пути ко всем файлам и подкаталогам в директории D:\dir1.
Вызов p.path() возвращает объект типа std::filesystem::path, который позволяет:

    Определить, файл это или каталог при помощи метода is_regular_file().
    Получить расширение для обычного файла при помощи метода extension().

При помощи метода compare() можно сравнить расширение с произвольной строкой: p.path().extension().compare(“.torrent”).


Создайте лямбда-функцию, которая принимает на вход путь в файловой системе и искомое расширение в виде строки, 
а возвращает список имён файлов, которые имеют данное расширение(). Объявление нашей функции может начинаться так:

auto recursiveGetFileNamesByExtension =[](std::filesystem::path path,const std::string extension)
*/