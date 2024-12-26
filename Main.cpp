#include "Main.h"
#include "LZ77.h"
#include "DataReader.h"
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
                    cerr << "Invalid uncompressed block header "<< endl;
                    exit(202);
                }
                for (int i = 0; i < LEN; i++) {
                    outBuffer.push_back(static_cast<unsigned char>(stream.getBits(8)));
                }
                break;
            case 1:
                // compressed with static huffman codes
                break;
            case 2:
                // compressed with dynamic huffman
                break;
            default:
                cerr << "Invalid block type" << endl;
                exit(201);
        }
    } while (BFINAL == 0);
}
