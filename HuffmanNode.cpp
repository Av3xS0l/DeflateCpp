//
// Created by pgust on 21.12.2024.
//

#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(const int symbol, const int freq) {
    this->symbol = symbol;
    this->freq = freq;
    this->left = nullptr;
    this->right = nullptr;
}

bool HuffmanNode::operator<(const HuffmanNode &other) const {
    return this->freq < other.freq;
}