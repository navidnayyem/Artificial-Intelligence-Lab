#include<stdio.h>
#include<stdlib.h>

int N,E;
int Adj[20][20];
int h[20];

void input(){
    int i,j,sr,d,pc;
    printf("A* Search Algorithm\n");
    printf("--------------------\n");
    printf("Enter the Number of Nodes: ");
    scanf("%d", &N);
    printf("Enter the Number of Edges: ");
    scanf("%d", &E);
    printf("\n");

    for(i=0;i<E;i++){
        printf("Enter Source, Destination and Path Cost: ");
        scanf("%d %d %d", &sr, &d, &pc); // input the source, destination and path cost(use space between input)
        Adj[sr][d] = Adj[d][sr] = pc; // assign the value of path cost to the source and destination
    }
    printf("\n");
    for(i=1;i<=N;i++){
        printf("Enter Heuristic Value of Node %d: ", i);
        scanf("%d", &h[i]);
    }
    printf("\n");
}

void A_Star(int s,int G){
    int current_node = s;
    int total_cost = 0;
    int index;
    while(current_node != G){
        int min_cost = 1000; //large value
        for(int i=1;i<=N;i++){
            if(Adj[current_node][i] != 0){ //adjacent
                    if(Adj[current_node][i] + h[i] < min_cost){
                        min_cost = Adj[current_node][i] + h[i] + total_cost;
                        index = i;
                    }
            }
        }
        total_cost = total_cost + Adj[current_node][index];
        current_node = index;
        printf(" %d",current_node); //printing current node
    }
    printf("\nTotal Path Cost: %d",total_cost); //printing total path cost
}

int main(){
    system("COLOR F0"); //terminal color
    input();
    int sn,gn;
    printf("Enter the Starting Node: ");
    scanf("%d", &sn);
    printf("Enter the Goal Node: ");
    scanf("%d", &gn);
    printf("\n-------------------------------\n");
    printf("Nodes: ");
    printf("%d",sn);
    A_Star(sn,gn);
    printf("\n-------------------------------\n");
}
