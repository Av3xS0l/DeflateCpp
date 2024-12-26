//
// Created by av3xs0l on 12/20/24.
//

#ifndef SYMCODE_H
#define SYMCODE_H


class SymCode {
private:
    int code;
    int extra = 0;
    int extraValue = 0;
    int type;

    void symLen(int value);

    void symDis(int value);

public:
    SymCode(int type, int value);

    static int recoverValue(int type, int code, int extra, int extraValue);
};


#endif //SYMCODE_H
