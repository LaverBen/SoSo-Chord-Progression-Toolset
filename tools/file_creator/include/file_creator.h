#ifndef FILE_CREATOR_H
#define FILE_CREATOR_H

#include <iostream>

class file_creator
{
    private:
        void record();
        void ammend();
        void overwrite();
        void display();
        void quit();
        void help();

    public:
        file_creator();
        void perform_action(std::string arg);

};

enum arg_code {
    eRecord,
    eAmmend,
    eOverwrite,
    eDisplay,
    eQuit,
    eHelp
};

#endif