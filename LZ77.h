//
// Created by av3xs0l on 12/20/24.
//

#ifndef LZ77_H
#define LZ77_H
#include <utility>
#include <vector>


class LZ77 {
    int distance;
    int length;

public:
    LZ77(int distance, int length);

    explicit LZ77(int literal);

    std::pair<int, int> getVals();

    static std::vector<LZ77> encode(std::vector<unsigned char> data);
};


#endif //LZ77_H
