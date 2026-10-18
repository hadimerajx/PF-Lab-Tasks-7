#include <stdio.h>

int main() {
    int seats[5][8];
    int total_free = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            printf("Enter status for Row %d, Seat %d (0 for empty, 1 for booked): ", i + 1, j + 1);
            scanf("%d", &seats[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        int row_free = 0;
        
        for (int j = 0; j < 8; j++) {
            if (seats[i][j] == 0) {
                printf(". ");
                row_free++;
                total_free++;
            } else {
                printf("X ");
            }
        }
        
        printf("Row %d free: %d\n", i + 1, row_free);
    }

    printf("Total free: %d\n", total_free);
}