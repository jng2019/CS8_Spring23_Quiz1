//
// Created by Dave Smith on 1/29/23.
//

#ifndef CS8_SPRING23_QUIZ1_INDEX_H
#define CS8_SPRING23_QUIZ1_INDEX_H

#include "functions.h"

class Index
{
private:
    std::vector<std::vector<std::string>> data;
public:
    Index(const std::string &filename);
    void addWord(const std::string &word);
    friend std::ostream & operator << (std::ostream &out, const Index &c);
    std::vector<std::string> operator[](unsigned int index);
};


#endif //CS8_SPRING23_QUIZ1_INDEX_H
