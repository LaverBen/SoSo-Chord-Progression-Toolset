#include "file_creator.h"
#include <filesystem>
#include <fstream>

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

bool file_creator::file_test(std::string song_name, std::string artist)
{
    const std::filesystem::path file_repo_path = "repo";
    std::filesystem::file_status status = std::filesystem::file_status{};
    std::string new_song = "'" + song_name + "'" + " - " + artist;

    if(std::filesystem::status_known(status) ? std::filesystem::exists(status) : std::filesystem::exists(file_repo_path))
    {
        std::cout << "Directory exists\n";
    }
    else
    {
        std::cout << "No file repository exists, creating file repository...\n";
        std::filesystem::create_directory(file_repo_path);
        std::ofstream WriteFileList("repo/FileList.txt");
        WriteFileList.close();
    }

    std::ifstream CreateFileList("repo/FileList.txt");

    std::string song_entry;
    while (std::getline(CreateFileList, song_entry))
    {
        std::cout << "Comparing: " << new_song;
        std::cout << " with: " << song_entry << std::endl;
        if(new_song.compare(song_entry) == 0)
        {
            return false;
        }
    }

    return true;
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
    std::string song_name;
    std::string artist;

    std::cout << "Song name: ";
    std::getline(std::cin, song_name);
    std::cout << "Artist: ";
    std::getline(std::cin, artist);

    if(!file_test(song_name, artist))
    {
        std::cout << "Song already exists - use 'o' or 'overwrite' to overwrite a song\n";
        return;
    }

    std::ofstream WriteFileList("repo/FileList.txt", std::fstream::app);
    WriteFileList << "'" << song_name << "' - " << artist << "\n";
    WriteFileList.close();

    std::cout << "Recording chords for: '" << song_name << "' - " << artist << std::endl;
    std::cout << "Recording new song...\n" << "Use 's' or 'save' to save result\n";
    std::cout << "Use 'q' or 'quit' to quit without saving\n";
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