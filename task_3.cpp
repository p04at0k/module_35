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
