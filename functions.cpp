//
// Created by Dave Smith on 1/28/23.
//

#include <fstream>
#include "functions.h"

vector<vector<std::string>> generateIndex(const std::string& data)
{
    vector<std::string> strings = split(data, " ");

    vector<vector<std::string>> index(26, vector<std::string>());
    for(int i = 0; i < strings.size(); i++)
    {
        std::string t = strings.at(i);
        if(!contains(index[charToIndex(t[0])], t))
            index[charToIndex(t[0])].push_back(t);
    }
    return index;
}
int charToIndex(char c)
{
    return toupper(c) - 'A';
}
bool openFile(std::ifstream &fin, const std::string& filename)
{
    fin.open(filename);
    return !(fin.fail());
}
vector<std::string> getIndex(char c, const vector<vector<std::string>>& index)
{
    return index[charToIndex(c)];
}
void print(const vector<vector<std::string>>& index)
{
    for(int i=0; i < index.size(); i++)
    {
        std::cout << static_cast<char>(i + 'A') << ": ";
        for(int j = 0 ;j < index[i].size(); j++) {
            std::string s = index[i].at(j);
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
}

bool contains(const vector<std::string>& vector, const std::string& string)
{
    for(int i = 0; i < vector.size(); i++) {
        std::string t = vector.at(i);
        if (tolower(t) == tolower(string))
            return true;
    }
    return false;
}
std::string tolower(const std::string& string)
{
    std::string s;
    for(char c : string)
        s.push_back(tolower(c));
    return s;
}


std::string removePunctuation(const std::string& string)
{
    int i = string.size() -1;
    if(!isalpha(string[i]))
        return string.substr(0, i);
    else
        return string;
}


std::string getFileContent(const std::string &filename)
{
    std::ifstream fin;
    std::string s, next;
    if(!openFile(fin, filename))
        exit(28);
    while(getline(fin, next))
        s += next + " ";
    fin.close();
    return s;
}

vector<std::string> split(const std::string& string, const std::string& delimiter)
{
    vector<std::string> v;
    std::string s = string;
    while(s.size() > 0)
    {
        int idx = s.find(delimiter);
        if(idx != std::string::npos)
        {
            v.push_back(s.substr(0, idx));
            s = s.substr(idx+1);
        }
        else
            break;
    }
    if(!s.empty())
        v.push_back(s);
    return v;
}