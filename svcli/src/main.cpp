// Auto Genrated C++ file by Flick CLI
// None
#include <svcliconfig.h>

#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>


void scanVerilogFiles(std::vector<std::string>& files)
{
    namespace fs = std::filesystem;

    auto currentDir = fs::current_path();
    for (const auto& file : fs::directory_iterator(currentDir))
    {
        if (file.is_directory())
        {
            continue;
        }
        if (file.path().filename().string().find(".sv") != std::string::npos)
        {
            files.push_back(file.path().filename());
        }
    }
};

bool compile(const std::vector<std::string>& files)
{
    std::string cmdString{"iverilog -g2005-sv"};
    for (const auto& file : files)
    {
        cmdString += (" " + file);
    };
    return std::system(cmdString.c_str()) == 0;
};

void runTestBenche() { system("./a.out"); };

void synthesize() {

};
void generateNetList() {

};

void generateNetListPNG() {}
int  main(int argc, char* argv[])
{
    std::printf("Copyright %s to %s v%s.\n", std::string(Project::PROJECT_NAME).c_str(),
                std::string(Project::COMPANY_NAME).c_str(),
                std::string(Project::VERSION_STRING).c_str());
    std::vector<std::string> files{};
    std::printf("Scanning Files...\n");
    scanVerilogFiles(files);
    if (files.size() == 0)
    {
        std::printf("No .sv files in current directory!\n");
        return 0;
    }
    std::printf("Compiling Files...\n");
    if (compile(files))
    {
        runTestBenche();
    }
    else
    {
        std::printf("Compilation Failed!\n");
    }

    return 0;
}
