//
// Created by Vadim on 03.12.2021.
//

#include "Functions.h"

double XPow2(struct funcdata data) {
    return data.x * data.x * data.vars[0] + data.vars[1] * data.x + data.vars[2];
}

double Line(struct funcdata data) {
    return data.x * data.vars[0] + data.vars[1];
}
