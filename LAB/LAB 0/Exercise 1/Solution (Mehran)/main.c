#include <stdio.h>
#include <string.h>

typedef struct word {
    char struct_word[20];
    int occurrence;
} mehran;

void read_words(mehran word[], char *second_file);
void to_lower(char*);
void read_and_update(mehran array[], char *second_file);

int main() {
    mehran Word[20];

    char first_file[] = "../first_file.txt";
    char second_file[] = "../second_file.txt";

    read_words(Word, second_file);
    read_and_update(Word, first_file);

    for (int i = 0; i < 20 && Word[i].struct_word[0] != '\0'; i++) {
        printf("Struct %d: word = %s, occurrence = %d\n", i + 1, Word[i].struct_word, Word[i].occurrence);
    }

    return 0;
}

void read_words(mehran word[], char *second_file) {
    FILE *second = fopen(second_file, "r");

    if (!second) {
        printf("ERROR REGARDING READING AND OPENING OF THE FILE: %s.\n", second_file);
        return;
    }

    int i = 0;
    while (i < 20 && fscanf(second, "%19s", word[i].struct_word) == 1) {
        to_lower(word[i].struct_word);  // Convert to lowercase to ensure uniformity
        word[i].occurrence = 0;
        i++;
    }

    fclose(second);
}

void to_lower(char *string) {
    while (*string) {
        if ((*string) >= 'A' && (*string) <= 'Z') {
            *string += 'a' - 'A';
        }
        string++;
    }
}

void read_and_update(mehran array[], char *first_file) {
    FILE *first = fopen(first_file, "r");

    if (!first) {
        printf("ERROR REGARDING READING THE FIRST FILE.\n");
        return;
    }

    char temp[20];
    while (fscanf(first, "%19s", temp) == 1) {
        to_lower(temp);

        for (int i = 0; i < 20 && array[i].struct_word[0] != '\0'; i++) {
            if (strcmp(array[i].struct_word, temp) == 0) {
                array[i].occurrence++;
            }
        }

        temp[0] = '\0';
    }

    fclose(first);
}
