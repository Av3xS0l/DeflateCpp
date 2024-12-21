//
// Created by av3xs0l on 12/20/24.
//

#ifndef LZ77ITEM_H
#define LZ77ITEM_H
#include <utility>


class LZ77Item {
    int distance;
    int length;

public:
    LZ77Item(int distance, int length);

    explicit LZ77Item(int literal);

    std::pair<int, int> getVals();
};


#endif //LZ77ITEM_H
