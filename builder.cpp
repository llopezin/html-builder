#include <iostream>
#include <fstream>
#include <regex>

using namespace std;
string pattern = "<([A-Z][a-zA-Z0-9]*)\\b[^>]*>";

smatch findCustomTagOccurrence(string text)
{
    regex r(pattern);
    smatch match;
    regex_search(text, match, r);

    // TO DO - Handle no ocurrence
    // TO DO - Handle multiple ocurrences

    cout << match[1] << endl;

    return match;
}

string readFile(ifstream &file)
{
    string content;
    string lineContent;

    while (getline(file, lineContent))
    {
        content += lineContent;
    }

    file.close();
    return content;
}

ifstream getFile(string name)
{
    string path = "./";
    string type = ".html";
    string pathToFile = path + name + type;
    ifstream file(pathToFile);

    // TO DO - handle no file

    return file;
}

int main()
{

    ifstream file = getFile("demo");
    string mainHTML = readFile(file);

    smatch componentMatch = findCustomTagOccurrence(mainHTML);
    string componentName = componentMatch[1].str();
    ifstream componentFile = getFile(componentName);
    string componentHTML = readFile(componentFile);

    string replaced = regex_replace(mainHTML, regex(pattern), componentHTML);
}