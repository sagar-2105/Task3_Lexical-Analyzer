#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of keywords to check
char keywords[][10] = {"int", "float", "if", "else", "while", "return", "char", "for", "double"};
int numKeywords = 9;

// Function to check if a word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/=%<>&|!";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *file;
    char ch, word[100];
    int index = 0;

    // Open the input file
    file = fopen("input.c", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(file)) != EOF) {
        // If character is a letter or digit, add to word buffer
        if (isalnum(ch)) {
            word[index++] = ch;
        } else {
            // Word boundary: process the word collected so far
            if (index > 0) {
                word[index] = '\0'; // Null-terminate the string
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
                index = 0;
            }

            // Check if it's an operator
            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            }
        }
    }

    fclose(file);
    return 0;
}
