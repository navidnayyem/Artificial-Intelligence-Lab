#include<stdio.h>
#include<conio.h>
#include<string.h>

struct word_data
{
    char word[20];
    float frequency;
    float probability;
};

float p_spam = 0.4;
float p_ham = 0.6;

int main()
{
    int i, j, k, s_f, h_f, t, s_total = 660, h_total = 815;
	char array[][20] = { "Hello", "You", "Thank", "Please" , "Buy" , "Shipment" , "Purchase" , "Receive" , "How" , "Are" };
    struct word_data database[100];


    float p_word_given_class = p_spam;
    float p_word_given_notClass = p_ham;

    float p_word_given_class1 = p_ham;
    float p_word_given_notClass1 = p_spam;

    printf("For SPAM Dictionary:\n");

    for(i=0; i<10; i++)
    {
        printf("next word is \" %s \"\n", array[i]);
        printf("Enter no of frequency: ");
        scanf("%f", &s_f);
        strcpy(database[i].word, array[i]);
        database[i].frequency = s_f;
        database[i].probability = s_f / s_total;
    }

    printf("    Word    |    Frequency    |    Probability    \n");
    for(i=0; i<10; i++)
    {
        printf("    %s    |   %f    |    %f    \n", database[i].word, database[i].frequency, database[i].probability);
        float pps =((p_word_given_class * p_spam)/((p_word_given_class * p_spam)) + ((p_word_given_notClass) * p_ham));
        printf("Posterior Probability of Spam: %f\n" ,pps);
    }

    printf("For HAM Dictionary:\n");
    for(i=0; i<10; i++)
    {
        printf("next word is \" %s \"\n", array[i]);
        printf("Enter no of frequency: ");
        scanf("%f", &h_f);
        strcpy(database[i].word, array[i]);
        database[i].frequency = h_f;
        database[i].probability = h_f / h_total;
    }

    printf("    Word    |    Frequency    |    Probability    \n");
    for(i=0; i<10; i++)
    {
        printf("    %s    |   %f    |    %f    \n", database[i].word, database[i].frequency, database[i].probability);
        float pph =((p_word_given_class1 * p_ham)/((p_word_given_class1 * p_ham)) + ((p_word_given_notClass1) * p_spam));
        printf("Posterior Probability of Ham: %f\n" ,pph);
    }
    return 0;
}
