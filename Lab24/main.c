#include <stdio.h>
#include <stdlib.h>
#include "battery.h"

int main() {
    int size = 0;
    Battery *data_array = DataLoad(&size);
    while (1) {

        puts("1. Add battery");
        puts("2. Delete existing battery.");
        puts("3. Sort by any column.");
        puts("4. Print existing data_array.");
        puts("5. No save and exit.");
        puts("6. Save and exit.\n");

        int option = ReadInt("Your choice:");

        switch (option) {
            case 1:
                data_array = AddBattery(data_array, &size);
                printf("%d", size);
                puts("Updated data_array:");
                print(data_array, size);

                break;
            case 2:
                if (!data_array) {
                    puts("You don't have any data_array yet.\n");
                    break;
                }

                int to_del;
                to_del = ReadInt("Enter number of the line which you want to delete:");
                BatteryErase(data_array, to_del - 1, &size);
                if (!size) {
                    puts("\nAll data_array is clear.");
                    puts("---------done---------\n");
                } else {
                    puts("Updated data_array:");
                    print(data_array, size);
                }
                break;

            case 3:
                if (!data_array) {
                    puts("You don't have any data yet.\n");
                    break;
                }

                int sort_menu;
                do {
                    puts("\n1. Sort by the model.");
                    puts("2. Sort by the size.");
                    puts("3. Sort by the price.");
                    puts("4. Sort by the voltage.");
                    puts("5. Sort by the type.");

                    sort_menu = ReadInt("Your choice (add '-' to reverse sorting):");
                    if (sort_menu < -6 || sort_menu > 6) {
                        puts("Incorrect input. Try again.\n");
                        sort_menu = -100;
                    } else {
                        sorter(data_array, size, sort_menu);
                        puts("Updated data:");
                        print(data_array, size);
                    }
                } while (sort_menu == -100);
                break;

            case 4:
                puts("Exisitng data:");
                print(data_array, size);
                break;

            case 5:
                puts("\nShutting down . . .");
                exit(0);

            case 6:
                if (!DataSave(data_array, size)) {
                    puts("\nShutting down . . .");
                    exit(0);
                }
                break;

            default:
                puts("Incorrect input. Try again.\n");
        }
    }
}
