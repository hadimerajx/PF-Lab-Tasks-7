#include <stdio.h>

int main() {
    int sales[3][5];
    int branch_totals[3] = {0};
    int product_totals[5] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Enter sales for Branch %d, Product %d: ", i + 1, j + 1);
            scanf("%d", &sales[i][j]);
            branch_totals[i] += sales[i][j];
            product_totals[j] += sales[i][j];
        }
    }

    printf("\nTotal sales per branch:\n");
    int best_branch = 0;
    int max_branch_sales = branch_totals[0];
    for (int i = 0; i < 3; i++) {
        printf("Branch %d: %d\n", i + 1, branch_totals[i]);
        if (branch_totals[i] > max_branch_sales) {
            max_branch_sales = branch_totals[i];
            best_branch = i;
        }
    }

    printf("\nTotal sales per product:\n");
    int lowest_product = 0;
    int min_product_sales = product_totals[0];
    for (int j = 0; j < 5; j++) {
        printf("Product %d: %d\n", j + 1, product_totals[j]);
        if (product_totals[j] < min_product_sales) {
            min_product_sales = product_totals[j];
            lowest_product = j;
        }
    }

    printf("\nBest-selling branch: Branch %d\n", best_branch + 1);
    printf("Product with lowest sales overall: Product %d\n", lowest_product + 1);
}