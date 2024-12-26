#include "Main.h"
#include "LZ77.h"
#include "DataReader.h"
#include "SymCode.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    int option;
    cout << "File name:";
    string inFileName, outFileName;
    cin >> inFileName;
    cout << "Output file name:";
    cin >> outFileName;
    cout << "Operation (1 for compress, 2 for decompress):";
    cin >> option;
    switch (option) {
        case 1:
            compress(inFileName, outFileName);
            break;
        case 2:
            decompress(inFileName, outFileName);
            break;
        default:
            cout << "Invalid option passed" << endl;
            break;
    }
    return 0;
}

void compress(const string &inFile, const string &outFile) {
    // Reading the bytes from the file
    ifstream inFileStream;
    vector<unsigned char> inBuffer;


    inFileStream.open(inFile);
    if (!inFileStream.is_open()) {
        cerr << "Error opening file " << inFile << endl;
        exit(11);
    }
    for (int i = 0; i < inFile.length(); i++) {
        inBuffer.push_back(inFileStream.get());
    }

    // LZ77 compression
}


void decompress(const string &inFile, const string &outFile) {
    DataReader stream = DataReader(inFile);
    vector<unsigned char> outBuffer;

    int BFINAL;
    int BTYPE;
    int LEN;
    int NLEN;
    int HLIT;
    int HDIST;
    int HCLEN;
    constexpr int ORDER[] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
    int codeLenAlpha[19] = {};

    do {
        BFINAL = stream.getBits(1);
        BTYPE = stream.getBits(2);
        switch (BTYPE) {
            case 0:
                // no compression
                stream.getBits(5);
                LEN = stream.getBits(16);
                NLEN = stream.getBits(16);
                if (LEN != ~NLEN) {
                    cerr << "Invalid uncompressed block header " << endl;
                    exit(202);
                }
                for (int i = 0; i < LEN; i++) {
                    outBuffer.push_back(static_cast<unsigned char>(stream.getBits(8)));
                }
                break;

            case 1:
                // compressed with static huffman codes
                int curCode;
                int curVal;
                bool eof = false;
                bool nextDist = false;
                int extra;
                int extraVal;
                int LEN;
                int DIST;

            // I know that nested if statements are not good, but who really cares
                do {
                    if (!nextDist) {
                        // Lengths
                        // 7 bit code
                        curCode = stream.getBits(7);
                        if (curCode <= 0b0010111) {
                            if (curCode == 0) {
                                eof = true;
                                continue;
                            }
                            curVal = 256 + curCode;
                            nextDist = true;
                            if (curVal <= 264) {
                                extra = 0;
                                extraVal = 0;
                            } else {
                                extra = (curVal - 261) / 4;
                                extraVal = stream.getBits(extra);
                            }
                            LEN = SymCode::recoverValue(1, curVal, extra, extraVal);
                        } else {
                            // 8 bit code
                            curCode = (curCode << 1) + stream.getBits(1);
                            if (curCode <= 0b10111111) {
                                curVal = curCode - 0b00110000;
                                outBuffer.push_back(curVal);
                            } else if (curCode <= 0b11000111) {
                                curVal = 280 + curCode - 0b11000000;
                                nextDist = true;

                                if (curVal > 284) {
                                    extra = 0;
                                    extraVal = 0;
                                } else {
                                    extra = (curVal - 261) / 4;
                                    extraVal = stream.getBits(extra);
                                }
                                LEN = SymCode::recoverValue(1, curVal, extra, extraVal);
                            } else {
                                // 9 bit code
                                curCode = (curCode << 1) + stream.getBits(1);
                                curVal = 144 + curCode - 0b110010000;
                                outBuffer.push_back(curVal);
                            }
                        }
                    } else {
                        // Distance
                        curCode = stream.getBits(5);
                        if (curCode < 4) {
                            extra = 0;
                            extraVal = 0;
                        } else {
                            extra = (curCode - 2) / 2;
                            extraVal = stream.getBits(extra);
                        }
                        DIST = SymCode::recoverValue(2, curVal, extra, extraVal);
                        for (int i = 0; i < LEN; i++) {
                            outBuffer.push_back(outBuffer[outBuffer.size() - 1] - DIST);
                        }
                    }
                } while (!eof);
                break;

            case 2:
                // compressed with dynamic huffman
                HLIT = stream.getBits(5);
                HDIST = stream.getBits(5);
                HCLEN = stream.getBits(4);
                for (int i = 0; i < 19; i++) {
                    codeLenAlpha[ORDER[i]] = stream.getBits(3);
                }
                break;

            default:
                cerr << "Invalid block type" << endl;
                exit(201);
        }
    } while (BFINAL == 0);
}
