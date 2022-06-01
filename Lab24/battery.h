#ifndef UNTITLED_BATTERY_H
#define UNTITLED_BATTERY_H

#include "reader.h"

typedef struct {
    char *model;
    char *size;
    char *type_battery;
    int price;
    int voltage;

} Battery;

Battery *AddBattery(Battery *data, int *N);

Battery *BatteryErase(Battery *data, int to_del, int *n);

void sorter(Battery *data, int n, int flag);

void print(Battery *data, int n);

int DataSave(Battery *data, int size);

Battery *DataLoad(int *getSize);

#endif //UNTITLED_BATTERY_H
