#include "battery.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_INPUT_LENGTH 11

Battery *CreateBattery(Battery *data, int *N) {
    int i = *N;
    (*N)++;
    if (data == NULL)
        data = (Battery *) malloc(sizeof(Battery));
    else
        data = (Battery *) realloc(data, sizeof(Battery) * (*N));
    data[i].size = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    data[i].model = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    data[i].type_battery = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    data[i].voltage = -1;
    data[i].price = -1;
    return data;
}

Battery *AddBattery(Battery *data, int *N) {
    int i = *N;
    printf("%d\n", i);
    data = CreateBattery(data, N);
    printf("Enter model: ");
    scanf("%s", data[i].model);
    //puts("---------done---------\n");
    int checker = 1;
    do {
        printf("Enter size(AA or AAA):");
        scanf("%s", data[i].size);
        if ((strcmp(data[i].size, "AA") == 0) || (strcmp(data[i].size, "AAA") == 0)) {
            checker = 0;
        } else {
            puts("Incorrect input. Only AA or AAA.\n");
        }
    } while (checker);
    fflush(stdin);
    data[i].price = ReadInt("Enter the price:");
    fflush(stdin);
    data[i].voltage = ReadInt("Enter the voltage:");
    fflush(stdin);
    printf("Enter type:");
    scanf("%s", data[i].type_battery);
    fflush(stdin);
    return data;
}

void print(Battery *data, int n) {
    for (int i = 0; i < n; i++) {

        printf("\nid: %d\nmodel: %s\nsize: %s\nprise:%d\nvoltage: %d\ntype: %s\n", i + 1, data[i].model, data[i].size,
               data[i].price, data[i].voltage, data[i].type_battery);
    }
    puts("\n---------------------------------\n");
}

Battery *BatteryErase(Battery *data, int to_del, int *n) {
    free(data[to_del].size);
    free(data[to_del].model);
    free(data[to_del].type_battery);
    memmove(&data[to_del], &data[to_del + 1], ((*n) - to_del) * sizeof(Battery));
    --(*n);
    if ((*n) > 0)
        data = (Battery *) realloc(data, sizeof(Battery) * (*n));
    return data;
}

void DeleteData(Battery *data, int size) {
    for (int i = 0; i < size; ++i) {
        free(data[i].size);
        free(data[i].model);
        free(data[i].type_battery);
    }
    free(data);
}

int DataSave(Battery *data, int size) {
    FILE *file = fopen("..\\data.dat", "w");
    if (!file) {
        puts("Some troubles with file 'data.dat'. Check it out.");
        puts("---------------------------------\n");
        return 1;
    }

    fprintf(file, "%i\n", size);
    for (int i = 0; i < size; ++i) {
        fprintf(file, "%s %s %s %i %i\n", data[i].model, data[i].size, data[i].type_battery, data[i].price,
                data[i].voltage);
    }
    fclose(file);
    return 0;
}

Battery *DataLoad(int *getSize) {
    FILE *file = fopen("..\\data.dat", "r");
    if (!file || fscanf(file, "%i", getSize) == 0) {
        puts("The file 'data.dat' is empty.\nYou can create new data by adding lines.");
        puts("---------------------------------\n");
        return NULL;
    }
    Battery *data = NULL;
    for (int i = 0; i < *getSize;) {
        data = CreateBattery(data, &i);
        int t = i - 1;
        fscanf(file, "%s%s%s%i%i", data[t].model, data[t].size, data[t].type_battery, &data[t].price,
               &data[t].voltage);
    }
    fclose(file);
    print(data, *getSize);
    return data;
}

void sorter(Battery *data, int n, int flag) {
    int i, j;
    Battery k;
    switch (flag) {
        case 1:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].model[1] < data[j].model[1]) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case 2:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    printf("%d, %d", data[i].size, sizeof data[j].size);
            if (strcmp(data[i].size, data[j].size) < 0) {
                k = data[i];
                data[i] = data[j];
                data[j] = k;
            }
            break;

        case 3:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].price < data[j].price) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case 4:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].voltage < data[j].voltage) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case 5:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].type_battery[1] < data[j].type_battery[1]) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;


        case -1:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].model[1] > data[j].model[1]) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case -2:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (strcmp(data[i].size, data[j].size) > 0) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case -3:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].price > data[j].price) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case -4:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].voltage > data[j].voltage) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;

        case -5:
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (data[i].type_battery[1] > data[j].type_battery[1]) {
                        k = data[i];
                        data[i] = data[j];
                        data[j] = k;
                    }
            break;
        default:
            break;
    }
}

