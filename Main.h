#ifndef DEFLATE_LIBRARY_H
#define DEFLATE_LIBRARY_H

#include <string>
int main();


void compress(const std::string& inFile, const std::string& outFile);

void decompress(const std::string& inFile, const std::string& outFile);


#endif //DEFLATE_LIBRARY_H