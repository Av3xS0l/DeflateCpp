//
// Created by pgust on 21.12.2024.
//

#ifndef DATAREADER_H
#define DATAREADER_H
#include <fstream>
#include <string>
#include <iostream>


class DataReader {
    unsigned char byte;
    short int pos;
    std::ifstream file;

public:
    explicit DataReader(const std::string &fileName);

    int getBits(int count);
};


#endif //DATAREADER_H
