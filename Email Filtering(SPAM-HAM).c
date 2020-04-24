#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct spam_table
{
    char s_word[100];
    double s_frequency;
    double s_likelihood;
};

struct ham_table
{
    char h_word[100];
    double h_frequency;
    double h_likelihood;
};

// Given Prior Probabilities
double p_spam = 0.4;
double p_ham = 0.6;

void spam_posterior_probability(){
    double p_word_given_class = 4;
    double p_word = p_spam;
    double p_word_given_notClass = 6;
    double p_notClass = p_ham;
    double p_class = 1 - p_notClass;

    //P(spam|Word) = P(Word|spam)p(spam)/(P(Word|spam)p(spam) + p(Word|ham)p(ham))
    double P_SPAM =((p_word_given_class * p_spam) / ((p_word_given_class * p_spam) + (p_word_given_notClass * p_notClass)));
    printf("Posterior Probability of SPAM: %0.3lf\n" ,P_SPAM);
}

void ham_posterior_probability(){
    double p_word_given_class1 = 6;
    double p_word1 = p_ham;
    double p_word_given_notClass1 = 4;
    double p_notClass1 = p_spam;
    double p_class1 = 1 - p_notClass1;

    //P(ham|Word) = P(Word|ham)p(ham)/(P(Word|ham)p(ham) + p(Word|spam)p(spam))
    double P_HAM =((p_word_given_class1 * p_ham) / ((p_word_given_class1 * p_ham) + (p_word_given_notClass1 * p_notClass1)));
    printf("Posterior Probability of HAM: %0.3lf\n" ,P_HAM);
}

void spamity_hamity_calculation(){
    //Spamity = P(spam|Please) * P(spam|Buy) * P(spam|Shipment) // For sample input: Please Buy Shipment
    double spamity = 0; // couldnt write the formula
    //Hamity = P(ham|Please) * P(ham|Buy) * p(ham|Shipment) // For sample input: Please Buy Shipment
    double hamity = 0; // couldnt write the formula

    if (spamity > hamity){
        printf("\nThe Email is a Spam Email\n");
    } else {
        printf("\nThe Email is a Ham Email\n");
    }

}

int main(){
    system("COLOR F0"); // terminal colour
    char spam_dictionary_word[][20] = { "Hello", "You", "Thank", "Please" , "Buy" , "Shipment" , "Purchase" , "Receive" , "How" , "Are" };
    char ham_dictionary_word[][20] = { "Hello", "You", "Thank", "Please" , "Buy" , "Shipment" , "Purchase" , "Receive" , "How" , "Are" };
    struct spam_table s_database[100];
    struct ham_table h_database[100];
    char str1[256], str2[256], new_str[256], words1[100][256], words2[100][256], temp1[256], temp2[256];
    int i1,i2,j1,j2,k1,k2,n1,n2,count1,count2;
    i1 = j1 = k1 = n1 = 0;
    i2 = j2 = k2 = n2 = 0;

    //get the input string1 from the user
    printf("Enter String 1 for Spam: ");
    fgets(str1, 256, stdin);
    str1[strlen(str1) - 1] = '\0';

    //copying each and every word from the string 1
    while (str1[i1] != '\0') {
            if (str1[i1] == ' ') {
                    words1[j1][k1] = '\0';
                    k1 = 0;
                    j1++;
            } else {
                    words1[j1][k1++] = str1[i1];
            }
            i1++;
    }

    words1[j1][k1] = '\0';
    n1 = j1;

     //sort the words in the given string 1
    for (i1 = 0; i1 < n1; i1++) {
            strcpy(temp1, words1[i1]);
            for (j1 = i1 + 1; j1 <= n1; j1++) {
                    if (strcmp(words1[i1], words1[j1]) > 0) {
                            strcpy(temp1, words1[j1]);
                            strcpy(words1[j1], words1[i1]);
                            strcpy(words1[i1], temp1);
                    }
            }
    }
    printf("\nSPAM DICTIONARY\n\n");
    printf("\nWords\t    Frequency\t      Likelihood\n");
    printf("------------------------------------------\n");
    i1 = 0;

    //find the frequency of each word and print the results
    while (i1 <= n1) {
            count1 = 1;
            if (i1 != n1) {
                    for (j1 = i1 + 1; j1 <= n1; j1++) {
                            if (strcmp(words1[i1], words1[j1]) == 0) {
                                count1++;
                            }
                    }
            }
            double likelihood1 = count1;
            printf("%s\t\t%d\t\t%0.4lf\n", words1[i1], count1, likelihood1); //count - indicates the frequency of word[i]
            i1 = i1 + count1; // skipping to the next word to process
    }
    printf("\nTFrequency-->  %d\n",i1);

    printf("\n");

    //get the input string2 from the user
    printf("\nEnter String 2 for HAM: ");
    fgets(str2, 256, stdin);
    str2[strlen(str2) - 1] = '\0';

    //copying each and every word from the string 2
    while (str2[i2] != '\0') {
            if (str2[i2] == ' ') {
                    words2[j2][k2] = '\0';
                    k2 = 0;
                    j2++;
            } else {
                    words2[j2][k2++] = str2[i2];
            }
            i2++;
    }

    words2[j2][k2] = '\0';
    n2 = j2;

     //sort the words in the given string 2
    for (i2 = 0; i2 < n2; i2++) {
            strcpy(temp2, words2[i2]);
            for (j2 = i2 + 1; j2 <= n2; j2++) {
                    if (strcmp(words2[i2], words2[j2]) > 0) {
                            strcpy(temp2, words2[j2]);
                            strcpy(words2[j2], words2[i2]);
                            strcpy(words2[i2], temp2);
                    }
            }
    }
    printf("\nHAM DICTIONARY\n\n");
    printf("\nWords\t    Frequency\t      Likelihood\n");
    printf("------------------------------------------\n");
    i2 = 0;

    //find the frequency of each word and print the results
    while (i2 <= n2) {
            count2 = 1;
            if (i2 != n2) {
                    for (j2 = i2 + 1; j2 <= n2; j2++) {
                            if (strcmp(words2[i2], words2[j2]) == 0) {
                                    count2++;
                            }
                    }
            }
            double likelihood2 = count2;
            printf("%s\t\t%d\t\t%0.4lf\n", words2[i2], count2, likelihood2); //count - indicates the frequency of word[i]
            i2 = i2 + count2; // skipping to the next word to process
    }
    printf("\nTFrequency-->  %d",i2);

    printf("\n");

    printf("\nEnter New Incoming Email String: ");
    gets(new_str);

    spam_posterior_probability(new_str);
    ham_posterior_probability(new_str);
    spamity_hamity_calculation();

    return 0;
}
