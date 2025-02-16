#include <iostream>
#include <fstream>

using namespace std;

void readFile(ifstream &file)
{
    string content;
    while (getline(file, content))
    {
        cout << content;
    }
    file.close();
}

void getFile(string name)
{
    ifstream Banana("./Banana.html");
}

int main()
{
    cout << "Hello" << endl;
}