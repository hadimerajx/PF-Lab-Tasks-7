#include <stdio.h>

int main() {
    int rooms[4][6];
    int max_vacancies = -1;
    int best_floor = 0;
    int found_consecutive = 0;
    int target_floor = -1;
    int target_start_room = -1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("Enter status for Floor %d, Room %d (1 for occupied, 0 for vacant): ", i + 1, j + 1);
            scanf("%d", &rooms[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        int current_vacancies = 0;
        int consecutive_count = 0;
        int current_start = -1;
        int has_consecutive_on_floor = 0;
        int floor_start_room = -1;

        for (int j = 0; j < 6; j++) {
            if (rooms[i][j] == 0) {
                current_vacancies++;
                if (consecutive_count == 0) {
                    current_start = j + 1;
                }
                consecutive_count++;
            } else {
                consecutive_count = 0;
            }

            if (consecutive_count >= 3 && !has_consecutive_on_floor) {
                has_consecutive_on_floor = 1;
                floor_start_room = current_start;
            }
        }

        if (current_vacancies > max_vacancies) {
            max_vacancies = current_vacancies;
            best_floor = i + 1;
        }

        if (has_consecutive_on_floor && !found_consecutive) {
            found_consecutive = 1;
            target_floor = i + 1;
            target_start_room = floor_start_room;
        }
    }

    printf("\nFloor with the most vacancies: Floor %d\n", best_floor);

    if (found_consecutive) {
        printf("Floor with 3 or more consecutive vacant rooms: Floor %d, starting at Room %d\n", target_floor, target_start_room);
    } else {
        printf("No floor has 3 or more consecutive vacant rooms.\n");
    }
}