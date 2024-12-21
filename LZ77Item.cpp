//
// Created by av3xs0l on 12/20/24.
//
#include "LZ77Item.h"
#include <utility>

LZ77Item::LZ77Item(const int distance, const int length) {
    this->distance = distance;
    this->length = length;
}

LZ77Item::LZ77Item(const int literal) {
    this->distance = -1;
    this->length = literal;
}

std::pair<int, int> LZ77Item::getVals() {
    return std::make_pair(distance, length);
}
