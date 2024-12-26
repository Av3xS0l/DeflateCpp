//
// Created by pgust on 21.12.2024.
//

#include "DataReader.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

DataReader::DataReader(const string &fileName) {
    this->byte = 0;
    this->pos = 0;
    file.open(fileName, ios::binary | ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file " << fileName << endl;
        exit(101);
    }
}

int DataReader::getBits(const int count) {
    int bitBuff = 0;
    pos = -1;
    for (int i = 0; i < count; i++, pos--) {
        if (pos < 0) {
            pos = 7;
            try {
                file.read(reinterpret_cast<istream::char_type *>(&byte), 1);
            } catch (...) {
                cerr << "Position out of file bounds";
                exit(102);
            }

        }
        bitBuff <<= 1;
        bitBuff += byte & 0b10000000 ? 1 : 0;
        byte <<= 1;
    }
    return bitBuff;
}
