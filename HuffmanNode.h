//
// Created by pgust on 21.12.2024.
//

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H


class HuffmanNode {
    int symbol;
    int freq;

public:
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(int symbol, int freq);

    bool operator<(const HuffmanNode &other) const;
};


#endif //HUFFMANNODE_H
