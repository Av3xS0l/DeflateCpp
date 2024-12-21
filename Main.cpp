#include "Main.h"
#include "LZ77Item.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int option;
    cout << "File name: ";
    string inFileName, outFileName;
    cin >> inFileName;
    cout << "Output file name: ";
    cin >> outFileName;
    cout << "Operation (1 for compress, 2 for decompress): ";
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

void compress(string inFile, string outFile) {

}


void decompress(string inFile, string outFile) {
}
