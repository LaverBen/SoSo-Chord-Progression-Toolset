#include <file_creator.h>

arg_code hash_arg (std::string const& arg)
{
    if (arg == "r" || arg == "record") return eRecord;
    if (arg == "a" || arg == "ammend") return eAmmend;
    if (arg == "o" || arg == "overwrite") return eOverwrite;
    if (arg == "d" || arg == "display") return eDisplay;
    if (arg == "q" || arg == "quit") return eQuit;
    if (arg == "h" || arg == "help" || arg == "options") return eHelp;
}

void file_creator::perform_action(std::string arg)
{
    switch (hash_arg(arg))
    {
        case eRecord:
            this->record();
        case eAmmend:
            this->ammend();
        case eOverwrite:
            this->overwrite();
        case eDisplay:
            this->display();
        case eQuit:
            this->quit();
        case eHelp:
            this->help();
    }
}

void file_creator::record()
{

}

void file_creator::ammend()
{

}

void file_creator::overwrite()
{

}

void file_creator::display()
{

}

void file_creator::quit()
{

}

void file_creator::help()
{

}