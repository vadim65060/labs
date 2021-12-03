//
// Created by Сергей on 03.12.2021.
//

#ifndef LAB13_1_FUNCTIONS_H
#define LAB13_1_FUNCTIONS_H

struct funcdata {
    double (*func)(struct funcdata);

    double x;
    double *vars;
};

double XPow2(struct funcdata data);

double Line(struct funcdata data);

#endif //LAB13_1_FUNCTIONS_H
