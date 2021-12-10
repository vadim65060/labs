#include <stdio.h>
#include "FuncAreaCalculate.h"

#define PrintAndReadD(s, doubleVar) {printf("%s",s);scanf("%lf",&(doubleVar));}
#define PrintAndReadI(s, intVar) {printf("%s",s);scanf("%i",&(intVar));}

int main() {
    int select = -1;
    do {
        PrintAndReadI("1: y=a*x^2+b*x+c\n2: y=a*x+b\nselect:", select);
    } while (select < 1 || select > 3);
    struct funcdata _funcdata;
    switch (select) {
        case 1: {
            double vars[3];
            PrintAndReadD("a=", vars[0]);
            PrintAndReadD("b=", vars[1]);
            PrintAndReadD("c=", vars[2]);
            _funcdata.vars = vars;
            _funcdata.func = &XPow2;
            break;
        }

        case 2: {
            double vars[2];
            PrintAndReadD("a=", vars[0]);
            PrintAndReadD("b=", vars[1]);
            _funcdata.vars = vars;
            _funcdata.func = &Line;
            break;
        }
        default:
            printf("invalid data");
            return 0;
    }
    size_t n;
    {
        int temp;
        PrintAndReadI("n=", temp);
        n = temp;
    }
    double l, r, eps;
    PrintAndReadD("l=", l);
    PrintAndReadD("r=", r);
    PrintAndReadD("eps=", eps);
    printf("Left:%lf\n", AreaCalculateLeftRectangle(_funcdata, l, r, n));
    printf("Middle:%lf\n", AreaCalculateMiddleRectangle(_funcdata, l, r, n));
    printf("UnknownFunc:%lf\n", UnknownAreaCalculateFunc(_funcdata, l, r, n));
    printf("epsFunc:%lf\n", AreaCalculateForEps(_funcdata, l, r, eps, &AreaCalculateMiddleRectangle));
}
