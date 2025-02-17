#include <iostream>
#include <fstream>
#include <regex>

auto pattern = std::string{"<([A-Z][a-zA-Z0-9]*)\\b[^>]*>"};

std::smatch findCustomTagOccurrence(const std::string &text)
{
    auto r = std::regex{pattern};
    std::smatch match;
    regex_search(text, match, r);

    // TO DO - Handle no ocurrence
    // TO DO - Handle multiple ocurrences

//    cout << match[1] << endl;

    return match;
}

std::string readFile(const std::string &filepath)
{
    auto file = std::ifstream{filepath};
    // TO DO - handle no file
    auto content = std::string{};
    std::string lineContent;

    while (getline(file, lineContent))
    {
        content += lineContent;
        content += "\n";
    }

    return content;
}

std::string getPath(std::string name)
{
    auto path = "./";
    auto type = ".html";
    auto pathToFile = path + name + type;
    return pathToFile;
}

int main()
{

    auto filepath = getPath("demo");
    auto mainHTML = readFile(filepath);

    auto componentMatch = findCustomTagOccurrence(mainHTML);
    auto componentName = componentMatch[1].str();
    std::cout << "replacing componentName: "<< componentName << std::endl;
    auto componentFile = getPath(componentName);
    auto componentHTML = readFile(componentFile);

    auto replaced = std::regex_replace(mainHTML, std::regex(pattern), componentHTML);
    std::cout << "replaced:\n" << replaced << std::endl;
}
