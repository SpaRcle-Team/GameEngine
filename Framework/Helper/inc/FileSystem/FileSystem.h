//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_FILESYSTEM_H
#define GAME_FILESYSTEM_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <random>
#include <ostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <Psapi.h>

#include <fstream>
#include <vector>
#include <istream>
#include <filesystem>

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

namespace fs = std::filesystem;

namespace Framework {
    namespace Helper {
        class FileSystem {
        private:
            FileSystem();
            ~FileSystem();
        public:
            static bool Delete(std::string file) { return remove(file.c_str()); }
            static std::vector<std::string> GetAllFilesInDir(std::string folder) {
                std::vector<std::string> files = {};
                for (const auto& entry : fs::directory_iterator(folder))
                    files.push_back(entry.path().string());
                return files;
            }
            static size_t FileSize(std::string filename) { return std::filesystem::file_size(filename); }
            static bool FileExists(std::string name) {
                if (FILE* file = fopen(name.c_str(), "r")) {
                    fclose(file);
                    return true;
                }
                else {
                    return false;
                }
            }
            static bool DirExists(const std::string& dirName_in)
            {
                DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
                if (ftyp == INVALID_FILE_ATTRIBUTES)
                    return false;  //something is wrong with your path!

                if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
                    return true;   // this is a directory!

                return false;    // this is not a directory!
            }
            static char* ReadAllBytes(const char* filename, int* read)
            {
                std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
                std::ifstream::pos_type pos = ifs.tellg();

                // What happens if the OS supports really big files.
                // It may be larger than 32 bits?
                // This will silently truncate the value/
                int length = pos;

                // Manuall memory management.
                // Not a good idea use a container/.
                char* pChars = new char[length];
                ifs.seekg(0, std::ios::beg);
                ifs.read(pChars, length);

                // No need to manually close.
                // When the stream goes out of scope it will close the file
                // automatically. Unless you are checking the close for errors
                // let the destructor do it.
                ifs.close();
                *read = length;
                return pChars;
            }
            static std::vector<unsigned char> LoadBinaryFile(std::string filename) {
                size_t bytesAvailable = FileSize(filename.c_str());

                std::ifstream inf(filename.c_str());
                if (inf)
                {
                    //unsigned char* mDataBuffer = new unsigned char[bytesAvailable];
                    std::vector<unsigned char> mDataBuffer = std::vector<unsigned char>(bytesAvailable);
                    inf.read((char*)(&mDataBuffer[0]), bytesAvailable);
                    size_t counted = inf.gcount();
                    return mDataBuffer;
                }

                return std::vector<unsigned char>();
            }
            static const std::string GetPathToExe();
        };
    }
}

#endif //GAME_FILESYSTEM_H
