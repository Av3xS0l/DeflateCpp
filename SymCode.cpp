//
// Created by av3xs0l on 12/20/24.
//

#include "SymCode.h"
#include <cmath>

SymCode::SymCode(const int type, const int value) {
    this->type = type;
    switch (type) {
        case 0:
            this->code = value;
            break;
        case 1:
            symLen(value - 3);
            break;
        case 2:
            symDis(value - 1);
            break;
        default: break;
    }
}


void SymCode::symLen(const int value) {
    if (value + 3 == 258) {
        this->code = 285;
    } else {
        if (value < 7) {
            this->code = 257 + value;
        } else {
            this->extra = static_cast<int>(floor(log(value) / log(2))) - 2;
            this->extraValue = value % (1 << this->extra);
            this->code = 265 + (this->extra - 1) * 4 + ((value - (1 << (this->extra + 2))) / (1 << this->extra));
        }
    }
}

void SymCode::symDis(const int value) {
    if (value < 4) {
        this->code = value;
    } else {
        this->extra = static_cast<int>(floor(log(value) / log(2))) - 1;
        const int rangeStart = (1 << (this->extra + 1));
        this->code = 4 + (this->extra - 1) * 2 + ((value - rangeStart) / (1 << this->extra));
        this->extraValue = value % (1 << (this->extra));
    }
}

int SymCode::recoverValue(const int type, const int code, const int extra, const int extraValue) {
    if (type == 1) {
            if (code == 285) {
                return 258;
            }
            if (extra == 0) {
                return code - 254;
            }
            return 3 + (1 << (extra + 2)) + ((code - 265) % 4) * (1 << extra) + extraValue;
    }
    return 1 + (1 << (extra + 1)) + ((code - 4) % 2) * (1 << extra) + extraValue;
}

