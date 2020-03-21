#include<stdio.h>

int V,E;
int Adj[10][10];

int main(){
    int i,j,S,D;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges: ");
    scanf("%d", &E);

    for(i=0;i<=V;i++){
            for(j=0;j<=V;j++){
                    Adj[i][j] = 0;
            }
    }

    for(i=0;i<E;i++){
        printf("Enter Source: ");
        scanf("%d", &S);
        printf("Enter Destination: ");
        scanf("%d", &D);
        Adj[S][D] = 1;
    }

     for(i=1;i<=V;i++) {
            for(j=1;j<=V;j++) {
                printf("%d ", Adj[i][j]);
            }
            printf("\n");
     }
}
