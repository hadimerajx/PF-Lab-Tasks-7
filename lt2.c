#include <stdio.h>

int main() {
    int marks[6][4];
    float student_totals[6] = {0};
    float subject_totals[4] = {0};
    float max_avg = -1;
    int best_subject = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter marks for Student %d, Subject %d: ", i + 1, j + 1);
            scanf("%d", &marks[i][j]);
            student_totals[i] += marks[i][j];
            subject_totals[j] += marks[i][j];
        }
    }

    printf("Student Results \n");
    for (int i = 0; i < 6; i++) {
        float avg = student_totals[i] / 4.0;
        printf("Student %d -> Total: %.2f, Average: %.2f\n", i + 1, student_totals[i], avg);
    }

    printf("Subject Class Averages \n");
    for (int j = 0; j < 4; j++) {
        float avg = subject_totals[j] / 6.0;
        printf("Subject %d Average: %.2f\n", j + 1, avg);
        if (avg > max_avg) {
            max_avg = avg;
            best_subject = j + 1;
        }
    }

    printf("\nBest performing subject: Subject %d\n", best_subject);
}