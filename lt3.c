#include <stdio.h>

int main() {
    float temp[7][4];
    char *times[] = {"Morning", "Noon", "Evening", "Night"};
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter temperature for Day %d, %s: ", i + 1, times[j]);
            scanf("%f", &temp[i][j]);
        }
    }

    float max_temp = temp[0][0];
    float min_temp = temp[0][0];
    int max_day = 0, max_time = 0;
    int min_day = 0, min_time = 0;

    float noon_sum = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (temp[i][j] > max_temp) {
                max_temp = temp[i][j];
                max_day = i;
                max_time = j;
            }
            if (temp[i][j] < min_temp) {
                min_temp = temp[i][j];
                min_day = i;
                min_time = j;
            }
        }
        noon_sum += temp[i][1];
    }

    float noon_avg = noon_sum / 7.0;

    printf("\nHottest reading: %.2f on Day %d at %s\n", max_temp, max_day + 1, times[max_time]);
    printf("Coldest reading: %.2f on Day %d at %s\n", min_temp, min_day + 1, times[min_time]);

    printf("\nWeekly Noon Average: %.2f\n", noon_avg);
    printf("Days with noon temperature above weekly average:\n");
    for (int i = 0; i < 7; i++) {
        if (temp[i][1] > noon_avg) {
            printf("Day %d (Noon Temp: %.2f)\n", i + 1, temp[i][1]);
        }
    }
}