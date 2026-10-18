#include <stdio.h>

int main() {
    char titles[5][50];
    int copies[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter title for book %d: ", i + 1);
        scanf(" %[^\n]", titles[i]);
        printf("Enter copies for book %d: ", i + 1);
        scanf("%d", &copies[i]);
    }

    printf("\n%-30s | %s\n", "Title", "Copies");
    printf("-----------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-30s | %d\n", titles[i], copies[i]);
    }

    printf("\nVowel counts in titles:\n");
    for (int i = 0; i < 5; i++) {
        int vowel_count = 0;
        for (int j = 0; titles[i][j] != '\0'; j++) {
            char ch = titles[i][j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowel_count++;
            }
        }
        printf("%s: %d\n", titles[i], vowel_count);
    }

    char search_char;
    printf("\nEnter a letter to search: ");
    scanf(" %c", &search_char);
    printf("Titles starting with '%c':\n", search_char);
    for (int i = 0; i < 5; i++) {
        if (titles[i][0] == search_char) {
            printf("%s\n", titles[i]);
        }
    }

    int max_copies = copies[0];
    int max_index = 0;
    for (int i = 1; i < 5; i++) {
        if (copies[i] > max_copies) {
            max_copies = copies[i];
            max_index = i;
        }
    }
    printf("\nBook with most copies: %s\n", titles[max_index]);
}