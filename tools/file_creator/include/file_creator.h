#ifndef FILE_CREATOR_H
#define FILE_CREATOR_H

#include <iostream>

class file_creator
{
    private:
        bool file_test(std::string song_name, std::string artist);
        void record();
        void ammend();
        void overwrite();
        void display();
        void quit();
        void help();
        void not_recognised();

    public:
        void perform_action(std::string arg);

};

enum arg_code {
    eRecord,
    eAmmend,
    eOverwrite,
    eDisplay,
    eQuit,
    eHelp,
    eError
};

#endif