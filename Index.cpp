//
// Created by Dave Smith on 1/29/23.
//

#include "Index.h"


Index::Index(const std::string &filename) {
// getfilecontent pass into generate index

    data = generateIndex(getFileContent(filename));
}

void Index::addWord(const std::string &word) {

}

std::ostream &operator<<(std::ostream &out, const Index &c) {

    print(c.data);
    return out;
}

std::vector<std::string> Index::operator[](unsigned int index) {
    return data.at(index);
}
