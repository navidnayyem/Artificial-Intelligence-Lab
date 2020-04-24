#include<stdio.h>
#include<stdlib.h>

int sample[30],sample_1[30],sample_2[30];
int *ptr1 = sample;
int *ptr2 = sample_1;
int *ptr3 = sample_2;
int a,b,l,n;

int fitness(int *ptr1,int l,int F[],int x){
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

void sorting(int n,int m,int A[][m])
{
    int i,j,item,index;
    for(i=1;i<n;i++)
    {
        item = A[i][1];
        index = A[i][0];
        j=i-1;
        while(j>=0 && A[j][1]>item)
        {
            A[j+1][1]=A[j][1];//attack
            A[j+1][0]=A[j][0];//index
            j=j-1;
        }
        A[j+1][1]=item;
        A[j+1][0]=index;
    }
}

void CrossOver(int *ptr1,int *ptr2,int *ptr3,int n){
    int i,inter_sample_1[30],inter_sample_2[30];
    int random_index = rand() % n + 1;

    // divide all populations into half and also the samples into two parts by the random_index
    for(i=1;i<=n/2;i++){
        sample_1[i] = sample[random_index] / 2;
        sample_2[i] = sample[random_index] / 2;
    }

    for(i=1;i<=n;i++){
        if(i<=random_index){
            inter_sample_1[i] = sample_1[i];
            inter_sample_2[i] = sample_2[i];
        } else {
            inter_sample_1[i] = sample_2[i];
            inter_sample_2[i] = sample_1[i];
        }
    }

    //loop to copy
    printf("\nAfter CrossOver:\n");
    for(i=1;i<=n;i++){
        printf("P%d --> %d\n", i, sample_1[i]);
        printf("P%d --> %d\n", i, sample_2[i]);
    }
}

void mutation(int *ptr1,int n){
    printf("\nAfter Mutation:\n");
    for(int i=1;i<=n;i++){
        int rand_index = rand() % n + 1;
        int rand_val = rand() % n + 1;
        sample[rand_index] = rand_val;
        printf("Random Index: %d , Random Value: %d, P%d --> %d\n",rand_index, rand_val, i, sample[rand_index]);
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

    int Z[n][l];
    int F[n];
    int i,j;

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

    fitness(ptr1,n,F,n);

    int A[n][2];

    for(i=0;i<n;i++)
    {
        A[i][0]=i;
        A[i][1]=F[i];
    }

    sorting(n,2,A);
    printf("\nAfter Sorting Population Sample with Fitness Values\n");

    for(i=0;i<n;i++)
    {
        int x = A[i][0];
        printf("P%d --> ",i+1);
        for(j=0;j<l;j++)
        {
            printf("%d ",Z[x][j]);
        }
        printf("\n");
    }

    CrossOver(ptr1,ptr2,ptr3,n);
    mutation(ptr1,n);
}
