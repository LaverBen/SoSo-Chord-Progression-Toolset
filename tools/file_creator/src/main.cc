#include "file_creator.h"
#include <iostream>

int main()
{
    std::cout << "============\n" << "SoSo Toolset\n" << "============\n" << "File Creator Tool\n";
    std::cout << "View options with 'h', 'help' or 'options'\n";

    std::string arg;
    file_creator fc;

    do
    {
        std::cout << "SoSo File Creator: ";
        std::getline(std::cin, arg);
        fc.perform_action(arg);
    }
    while (arg != "q" && arg != "quit");
}