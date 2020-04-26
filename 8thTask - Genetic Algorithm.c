#include<stdio.h>
#include<stdlib.h>

int sample[30];
int *ptr1 = sample;
int a,b,l,n;
int i,j;

int Fitness(int *ptr1,int l,int F[],int x){
    int i,j,diff,goodness,attack = 0;
    goodness = l*(l-1)/2;
    printf("\nGoodness: %d which is the Worst Case Scenario\n\n",goodness);
    for(i=1;i<=l;i++){
        for(j=i+1;j<=l;j++){
            diff = (j-i);
            if(sample[i]+(-diff) == sample[j] || sample[i] == sample[j] || sample[i]+diff == sample[j]){
                attack++;
            }
        }
        printf("Fitness of Population %d: %d\n", i,goodness-attack);
        F[i-1]=attack;
    }
    return (goodness-attack);
}

void Sorting(int n,int m,int A[][m])
{
    int item,index;
    for(i=1;i<n;i++)
    {
        item = A[i][1];
        index = A[i][0];
        j = i - 1;
        while(j >= 0 && A[j][1] > item)
        {
            A[j+1][1] = A[j][1];//attack
            A[j+1][0] = A[j][0];//index
            j = j - 1;
        }
        A[j+1][1] = item;
        A[j+1][0] = index;
    }
}

void CrossOver(int B[][l],int n){
    printf("\nCrossOver\n");
    printf("----------\n");
    for(i=0;i<n;i=i+2){
        int co_p = rand() % (l-2) + 1; // point value must be in between 0 to n-1
        if (co_p == l){ // when crossover point is equal to string length
            co_p--; // decrement crossover point by 1
        }
        printf("CrossOver Point for Inter Samples: %d\n", co_p);
        for(j=co_p+1;j<l;j++){
            int x = B[i][j];
            B[i][j] = B[i+1][j];
            B[i+1][j] = x;
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
            printf("P%d --> ", i+1);
        for(j=0;j<l;j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}

void Mutation(int B[][l],int n){
    printf("\nMutation\n");
    printf("----------\n");
    for(i=0;i<n;i++){
        int random_index = rand() % (l-2) + 1;
        if (random_index == l){
            random_index--;
        }
        int rand_val = rand() % l + 1;
        printf("Random Index for P%d: %d, Random Value for P%d: %d\n", i+1, random_index, i+1, rand_val);
        B[i][random_index] = rand_val;
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("P%d --> ",i+1);
        for(j=0;j<l;j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}

int main(){
    system("COLOR E0"); // terminal colour
    printf("***Genetic Algorithm***\n");
    printf("------------------------\n\n");
    printf("Enter the Number of Populations: ");
    scanf("%d", &n);
    printf("Enter the String Length: ");
    scanf("%d", &l);
    printf("\n");

    int F[n];
    int Z[n][l];

    //generate the populations by using the number of population and string length of each population
    for(a=1;a<=n;a++){
        for(b=1;b<=l;b++){
            sample[b] = rand() % n + 1;
            int x = sample[b];
            printf("%d ",sample[b]);
            Z[a-1][b-1]=x;
        }
        printf("\n");
    }

    Fitness(ptr1,n,F,n); // fitness function

    int A[n][2];
    int B[n][l]; // generated and sorted population

    for(i=0;i<n;i++)
    {
        A[i][0]=i;
        A[i][1]=F[i];
    }

    Sorting(n,2,A);
    printf("\nThe Population Samples after sorting with Fitness Values\n");

    for(i=0;i<n;i++)
    {
        int x = A[i][0];
        printf("P%d --> ", i+1);
        for(j=0;j<l;j++)
        {
            printf("%d ", Z[x][j]);
            B[i][j] = Z[x][j];
        }
        printf("\n");
    }

    CrossOver(B,n);
    Mutation(B,n);
}
