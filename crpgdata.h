#ifndef CRPGAME_CRPGDATA_H
#define CRPGAME_CRPGDATA_H

#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include "json.hpp"

using namespace nlohmann;

std::vector<std::string> SplitString(const std::string &str, char delim);

namespace Data
{
    class DataHandler
    {
    private:
        json file;
    public:
        DataHandler() = default;
        virtual ~DataHandler() = default;

    public:
        void OpenFile(const std::string& path);

        template <typename T>
        void GetValue(const std::string &key, T &var)
        {
            json::json_pointer p(key);


            try {
                var = file[p];
            }
            catch (...)
            {
                std::cout << "Invalid key!";
            }
        }
    };
}



#endif //CRPGAME_CRPGDATA_H
