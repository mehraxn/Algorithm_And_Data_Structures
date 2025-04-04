#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 100

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char text_file_path[] = "text.txt";
    char word_file_path[] = "words.txt";

    // Array to store the words to be counted
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_WORDS] = {0}; // Array to store counts of each word
    int num_words = 0;

    // Read words from the word file
    FILE *word_file = fopen(word_file_path, "r");
    if (!word_file) {
        perror("Could not open the words file");
        return 1;
    }

    while (fscanf(word_file, "%s", words[num_words]) == 1 && num_words < MAX_WORDS) {
        to_lowercase(words[num_words]);
        num_words++;
    }

    fclose(word_file);

    // Open the text file for reading
    FILE *text_file = fopen(text_file_path, "r");
    if (!text_file) {
        perror("Could not open the text file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    // Read each line from the text file
    while (fgets(line, sizeof(line), text_file)) {
        char *token;
        // Convert the line to lowercase
        to_lowercase(line);

        // Tokenize the line to extract words
        token = strtok(line, " ,.;:!?\"\n");
        while (token) {
            // Compare with each word from the list and update the count if they match
            for (int i = 0; i < num_words; i++) {
                if (strcmp(token, words[i]) == 0) {
                    word_count[i]++;
                }
            }
            token = strtok(NULL, " ,.;:!?\"\n");
        }
    }

    fclose(text_file);

    // Print the word counts
    for (int i = 0; i < num_words; i++) {
        printf("%s - %d occurrence(s)\n", words[i], word_count[i]);
    }

    return 0;
}
