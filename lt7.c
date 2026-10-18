#include <stdio.h>

int main() {
    int marks[3][4][5];
    float dept_totals[3] = {0};
    float max_dept_avg = -1;
    int best_dept = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%d", &marks[i][j][k]);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        float max_student_avg = -1;
        int topper_student = 0;
        
        printf("\nDepartment %d:\n", i + 1);
        
        for (int j = 0; j < 4; j++) {
            float student_sum = 0;
            int failed = 0;
            
            for (int k = 0; k < 5; k++) {
                student_sum += marks[i][j][k];
                if (marks[i][j][k] < 40) {
                    failed = 1;
                }
                dept_totals[i] += marks[i][j][k];
            }
            
            float student_avg = student_sum / 5.0;
            printf("  Student %d Average: %.2f", j + 1, student_avg);
            if (failed) {
                printf(" - FAIL");
            }
            printf("\n");
            
            if (student_avg > max_student_avg) {
                max_student_avg = student_avg;
                topper_student = j + 1;
            }
        }
        
        printf("  Topper: Student %d\n", topper_student);
    }

    for (int i = 0; i < 3; i++) {
        float dept_avg = dept_totals[i] / (4.0 * 5.0);
        if (dept_avg > max_dept_avg) {
            max_dept_avg = dept_avg;
            best_dept = i + 1;
        }
    }

    printf("\nDepartment with highest overall average: Department %d\n", best_dept);
}