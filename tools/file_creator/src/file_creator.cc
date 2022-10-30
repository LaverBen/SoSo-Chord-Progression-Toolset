#include "file_creator.h"

arg_code hash_arg (std::string const& arg)
{
    if (arg == "r" || arg == "record")
    {
        return eRecord;
    }
    else if (arg == "a" || arg == "ammend")
    {
        return eAmmend;
    }
    else if (arg == "o" || arg == "overwrite")
    {
        return eOverwrite;
    }
    else if (arg == "d" || arg == "display")
    {
        return eDisplay;
    }
    else if (arg == "q" || arg == "quit")
    {
        return eQuit;
    }
    else if (arg == "h" || arg == "help" || arg == "options")
    {
        return eHelp;
    }
    else
    {
        return eError;
    }
}

void file_creator::perform_action(std::string arg)
{
    switch (hash_arg(arg))
    {
        case eRecord:
            this->record();
            break;
        case eAmmend:
            this->ammend();
            break;
        case eOverwrite:
            this->overwrite();
            break;
        case eDisplay:
            this->display();
            break;
        case eQuit:
            this->quit();
            break;
        case eHelp:
            this->help();
            break;
        case eError:
            this->not_recognised();
            break;
    }
}

void file_creator::record()
{
    std::cout << "Recording new song...\n";
}

void file_creator::ammend()
{
    std::cout << "Ammend song\n";
}

void file_creator::overwrite()
{
    std::cout << "Overwrite song\n";
}

void file_creator::display()
{
    std::cout << "Display song\n";
}

void file_creator::quit()
{
    std::cout << "Quitting...\n";
}

void file_creator::help()
{
    std::cout << "Usage:\n" << "Arguments:\n";
    std::cout << "'r' or 'record'\t\t" << "Record a new song\n";
    std::cout << "'a' or 'ammend'\t\t" << "Ammend a song\n";
    std::cout << "'o' or 'overwrite'\t" << "Overwrite a song\n";
    std::cout << "'d' or 'display'\t" << "Display a song\n";
    std::cout << "'q' or 'quit'\t\t" << "Quit\n";
}

void file_creator::not_recognised()
{

}