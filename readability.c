#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strcspn
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_SIZE 14096
int count_letters(char string_text[]);
int count_words(char string_text[]);
int count_sentences(char string_text[]);

int main() {
    char* input = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    if (input == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter text (all on one line):\n");

    if (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
        // Remove trailing newline character, if present, using strcspn
        input[strcspn(input, "\n")] = '\0';

        printf("You entered: %s\n", input);
    } else {
        perror("Error reading input");
        free(input);
        return 1;
    }

    //printf("the string is: %s\n", input);
    // count up letters, word, and sentences
    int letters = count_letters(input); // this will be a function not a 0
    int words = count_words(input);
    int sentences = count_sentences(input);
    //printf("How many letters %d\n", letters);
    //printf("How many words %d\n", words);
    //printf("How many sentences %d\n", sentences);

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    //printf("%f\n", L);
    //printf("%f\n", S);

    float calc = round(0.0588 * L - 0.296 * S - 15.8);
    

    int CLI = (int) calc;

    //printf("The reading level is this: %d\n", CLI);
    if (CLI < 1) {
        printf("The reading level is Before Grade 1\n");
    } else if (CLI >= 1 && CLI <= 16) {
        printf("The reading level is Grade %d\n", CLI);
    } else if (CLI > 16) {
        printf("The reading level is Grade 16+\n");
    } else {
        printf("well crap\n");
    }
    



    free(input);
    return 0;
}

int count_letters(char string_text[]){
    int letters = 0;
    for (int i =0; string_text[i] != '\0'; i++){
        if (isalpha(string_text[i])){
            letters ++;
        }
       
    }
    return letters;
}

int count_words(char string_text[]){
    int words = 1;
    for (int i = 0; string_text[i] != '\0'; i++){
        if (isspace(string_text[i])) {
            words ++;
        }
    }
    return words;
}

int count_sentences(char string_text[]){
    int sentences = 0;
    for (int i = 0; string_text[i] != '\0'; i++){
        if (string_text[i] == '.' || string_text[i] =='?' || string_text[i] =='!') {
            sentences ++;
        }
    }
    return sentences;
}




// prompt the user for text
// get the average number of lettters per 100 words
// get average of senteces per 100 words
// Claculate the  Coleman-liau index