//
// Created by av3xs0l on 12/20/24.
//

#ifndef SYMBOL_H
#define SYMBOL_H


class Symbol {
private:
    int code;
    int extra = 0;
    int extraValue = 0;
    int type;

    void symLen(int value);

    void symDis(int value);

public:
    Symbol(int type, int value);

    Symbol(int type, int code, int extra, int extraValue);

    int recoverValue();
};


#endif //SYMBOL_H
