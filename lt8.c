#include <stdio.h>

int main() {
    int stock[3][4][5];
    int building_totals[3] = {0};
    int max_shelf_total = -1;
    int fullest_building = 0;
    int fullest_shelf = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%d", &stock[i][j][k]);
                building_totals[i] += stock[i][j][k];
            }
        }
    }

    printf("\nTotal stock per building:\n");
    for (int i = 0; i < 3; i++) {
        printf("Building %d: %d\n", i + 1, building_totals[i]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int shelf_sum = 0;
            for (int k = 0; k < 5; k++) {
                shelf_sum += stock[i][j][k];
            }
            if (shelf_sum > max_shelf_total) {
                max_shelf_total = shelf_sum;
                fullest_building = i + 1;
                fullest_shelf = j + 1;
            }
        }
    }

    printf("\nFullest shelf: Building %d, Shelf %d (Total items: %d)\n", fullest_building, fullest_shelf, max_shelf_total);

    printf("\nSlots needing restock (fewer than 5 items):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                if (stock[i][j][k] < 5) {
                    printf("[%d][%d][%d] needs restock\n", i + 1, j + 1, k + 1);
                }
            }
        }
    }
}