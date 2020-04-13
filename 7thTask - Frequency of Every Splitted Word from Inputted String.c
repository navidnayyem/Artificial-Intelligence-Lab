#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    system("COLOR E0"); // terminal colour
    char dictionary[][20] = {"How", "You", "Give", "Discuss" , "Deal" , "Explain" , "Chance" , "Opportunity" , "Regards" , "Thank"};
    char string[256], text[256], words[100][256], temp[256];
    int i, j, k, n, count;
    i = j = k = n = 0;

    //get the input string from the user
    printf("Enter a String: ");
    fgets(string, 256, stdin);
    string[strlen(string) - 1] = '\0';

    //copying each and every word from the string
    while (string[i] != '\0') {
            if (string[i] == ' ') {
                    words[j][k] = '\0';
                    k = 0;
                    j++;
            } else {
                    words[j][k++] = string[i];
            }
            i++;
    }

    words[j][k] = '\0';
    n = j;

    //sort the words in the given string
    for (i = 0; i < n; i++) {
            strcpy(temp, words[i]);
            for (j = i + 1; j <= n; j++) {
                    if (strcmp(words[i], words[j]) > 0) {
                            strcpy(temp, words[j]);
                            strcpy(words[j], words[i]);
                            strcpy(words[i], temp);
                    }
            }
    }

    printf("\nFrequency of Words:\n");
    i = 0;

    //find the frequency of each word and print the results
    while (i <= n) {
            count = 1;
            if (i != n) {
                    for (j = i + 1; j <= n; j++) {
                            if (strcmp(words[i], words[j]) == 0) {
                                    count++;
                            }
                    }
            }

            printf("%s\t%d\n", words[i], count); //count - indicates the frequecy of word[i]
            i = i + count; // skipping to the next word to process
    }

    printf("\n");
    return 0;
}
