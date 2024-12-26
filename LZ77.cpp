//
// Created by av3xs0l on 12/20/24.
//
#include "LZ77.h"
#include <utility>

constexpr int WINDOW_SIZE = 32768000;

using namespace std;

LZ77::LZ77(const int distance, const int length) {
    this->distance = distance;
    this->length = length;
}

LZ77::LZ77(const int literal) {
    this->distance = -1;
    this->length = literal;
}

pair<int, int> LZ77::getVals() {
    return make_pair(distance, length);
}

vector<LZ77> LZ77::encode(vector<unsigned char> data) {
    // The bad implementation that works.
    // TODO: work on the hashChain implementation


}

