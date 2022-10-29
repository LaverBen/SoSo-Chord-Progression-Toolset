#include <iostream>

int main()
{
    std::cout << "SoSo Toolset\n" << "============\n" << "File Creator Tool\n";
    std::cout << "View options with 'h', 'help' or 'options'\n";

    std::string arg;

    do {
        std::cin >> arg;
    }
    while (arg != "q" && arg != "quit");
}