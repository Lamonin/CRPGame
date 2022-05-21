#include "crpgdata.h"

void Data::DataHandler::OpenFile(const std::string &path) {
    std::cout << std::filesystem::current_path().string() << std::endl;
    std::ifstream reader(std::filesystem::current_path().string()+"/"+path);

    if (!reader.is_open())
    {
        assert("DataHandler.Openfile: Incorrect path!");
        return;
    }

    std::string result;
    std::string line;
    while (std::getline(reader, line))
    {
        result += line;
    }

    file = json::parse(result);
}

std::vector<std::string> SplitString(const std::string &str, char delim) {
    std::vector<std::string> out;
    std::string stringPart;
    for (int i = 0; i < str.length(); i++) {
        if (str[i]==delim)
        {
            if (stringPart.length()>0)
                out.push_back(stringPart);
            stringPart = "";
            continue;
        }

        stringPart += str[i];
    }
    return out;
}
