#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word_data{
    char word[100];
    int frequency;
};

// prior probabilities
float p_spam = 0.4;
float p_ham = 0.6;

float spam_likelihood(char *word){//search in the spam dictionary and return the likelihood
    float like, total = 660;
    printf("\nFor SPAM: ");
    FILE *of;
    of = fopen("SPAM.txt", "w");

    if(of == NULL){
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }

    struct word_data inp1 = {"Hello", 40};
    struct word_data inp2 = {"You", 30};
    struct word_data inp3 = {"Thank", 20};
    struct word_data inp4 = {"Please", 70};
    struct word_data inp5 = {"Buy", 100};
    struct word_data inp6 = {"Shipment", 130};
    struct word_data inp7 = {"Purchase", 120};
    struct word_data inp8 = {"Receive", 90};
    struct word_data inp9 = {"How", 40};
    struct word_data inp10 = {"Are", 20};

    fwrite(&inp1, sizeof(struct word_data), 1, of);
    fwrite(&inp2, sizeof(struct word_data), 1, of);
    fwrite(&inp3, sizeof(struct word_data), 1, of);
    fwrite(&inp4, sizeof(struct word_data), 1, of);
    fwrite(&inp5, sizeof(struct word_data), 1, of);
    fwrite(&inp6, sizeof(struct word_data), 1, of);
    fwrite(&inp7, sizeof(struct word_data), 1, of);
    fwrite(&inp8, sizeof(struct word_data), 1, of);
    fwrite(&inp9, sizeof(struct word_data), 1, of);
    fwrite(&inp10, sizeof(struct word_data), 1, of);

    fclose(of);
    FILE *inf;
    struct word_data inp;
    inf = fopen ("SPAM.txt", "r");
    if(inf == NULL){
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }
    fclose (inf);

    //search file
    FILE *fp1 = fopen("SPAM.txt", "a+");
    int stat = 0, countNumber = 0;

    fseek(of, 0, SEEK_SET);   // move file position indicator to beginning of file
    while(fread(&inp, sizeof(struct word_data), 1, fp1) == 1){
        countNumber++;        // counts number of times the file is searched
        if (!strcmp(inp.word, word)) {
            stat = 1;
            break;
        }
    }

    if(stat == 1){
        printf("FOUND\n");
        printf("Frequency: %d\n", inp.frequency);
        like = inp.frequency/total; //likelihood count
        printf("Likelihood of %s: %f\n" ,inp.word,like);
    } else {
        printf("Not Found");
    }
    return like;
    fclose(fp1);
}

float ham_likelihood(char *word){ //search in the ham dictionary and return the likelihood
    float like, total = 815;
    printf("\nFor HAM: ");
    FILE *of;
    of = fopen("HAM.txt", "w");

    if(of == NULL){
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }

    struct word_data inp1 = {"Hello", 70};
    struct word_data inp2 = {"You", 90};
    struct word_data inp3 = {"Thank", 85};
    struct word_data inp4 = {"Please", 120};
    struct word_data inp5 = {"Buy", 30};
    struct word_data inp6 = {"Shipment", 40};
    struct word_data inp7 = {"Purchase", 20};
    struct word_data inp8 = {"Receive", 20};
    struct word_data inp9 = {"How", 140};
    struct word_data inp10 = {"Are", 200};

    fwrite(&inp1, sizeof(struct word_data), 1, of);
    fwrite(&inp2, sizeof(struct word_data), 1, of);
    fwrite(&inp3, sizeof(struct word_data), 1, of);
    fwrite(&inp4, sizeof(struct word_data), 1, of);
    fwrite(&inp5, sizeof(struct word_data), 1, of);
    fwrite(&inp6, sizeof(struct word_data), 1, of);
    fwrite(&inp7, sizeof(struct word_data), 1, of);
    fwrite(&inp8, sizeof(struct word_data), 1, of);
    fwrite(&inp9, sizeof(struct word_data), 1, of);
    fwrite(&inp10, sizeof(struct word_data), 1, of);

    fclose(of);
    FILE *inf;
    struct word_data inp;
    inf = fopen ("HAM.txt", "r");
    if(inf == NULL){
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }
    fclose(inf);

    //search file
    FILE *fp1 = fopen("HAM.txt", "a+");
    int stat = 0, countNumber = 0;

    fseek(of, 0, SEEK_SET); //move file position indicator to beginning of file
    while (fread(&inp, sizeof(struct word_data), 1, fp1) == 1) {
        countNumber++; //counts number of times the file is searched
        if(!strcmp(inp.word, word)){
            stat = 1;
            break;
        }
    }

    if(stat == 1){
        printf("FOUND\n");
        printf("Frequency: %d\n" , inp.frequency);
        like = inp.frequency/total; //likelihood count
        printf("Likelihood of %s: %f\n", inp.word,like);
    } else {
        printf("Not Found");
    }
    return like;
    fclose(fp1);
}

float prob_spam(char *word){
    float p_word_given_class = spam_likelihood(word);
    float p_word_given_notClass = ham_likelihood(word);
    printf("\n--------------------------");
    //Posterior Probability(Bayes Rule)
    float pos_pro_spam = ((p_word_given_class * p_spam) / (((p_word_given_class * p_spam)) + ((p_word_given_notClass) * p_ham)));
    printf("\nP(SPAM|%s) : %f\n", word, pos_pro_spam);
    printf("--------------------------\n");
    return pos_pro_spam;
}

float prob_ham(char *word){
    float p_word_given_class = ham_likelihood(word);
    float p_word_given_notClass = spam_likelihood(word);
    printf("\n--------------------------");
    //Posterior Probability(Bayes Rule)
    float pos_pro_ham = ((p_word_given_class * p_ham) / (((p_word_given_class * p_ham)) + ((p_word_given_notClass) * p_spam)));
    printf("\nP(HAM|%s) : %f\n", word, pos_pro_ham);
    printf("--------------------------\n\n");
    return pos_pro_ham;
}

int main(){
    system("COLOR F0"); // terminal colour
    char message[256];
    printf("***E-Mail Filtering - SPAM or HAM***\n-------------------------------------\n");
    printf("Enter a New Incoming Email: ");
    fgets(message, 256, stdin);
    message[strlen(message) - 1] = '\0';
    char word[100][100];
    int i,j,k;
    float spamity = 1,hamity = 1;

    for(i = 0,j = 0,k = 0;i<=(strlen(message));i++){
        if(message[i] == ' ' || message[i] == '\0'){
            word[k][j] = '\0';
            k++;
            j = 0;
        }else{
            word[k][j] = message[i];
            j++;
        }
    }

    printf("\nSplitting Words:-\n\n");
    for(i=0;i<k;i++){
        printf("Word [%d] %s\n", i, word[i]);
        printf("--------------------------");
        char str[100];
        strncpy(str,word[i],100);
        spamity = spamity * prob_spam(str);
        hamity = hamity * prob_ham(str);
    }

    printf("Spamity: %f\n",spamity);
    printf("Hamity: %f\n",hamity);
    printf("\n-------------------------------------");
    if(spamity > hamity){
        printf("\n|||---The Email is a Spam Email---|||\n");
    } else {
        printf("\n|||---The Email is a Ham Email---|||\n");
    }
    printf("-------------------------------------\n");
    return 0;
}
