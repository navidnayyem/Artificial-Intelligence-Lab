#include<stdio.h>
#include<stdlib.h>

//global variables
int Adj[10][10]; // max size 10 by 10 adjacency matrix
int N,E; // node and edge integer variable
int SLD[20];

void input_and_Graph(){
    int i,j,s,d,pc;
    printf("***Informed Search(Greedy Best First Search)***\n\n");
    printf("Enter the Number of Nodes: ");
    scanf("%d", &N); // input the total number of nodes
    printf("Enter the Number of Edges: ");
    scanf("%d", &E); // input the total number of edges

    for(i=0;i<=N;i++){
            for(j=0;j<=N;j++){
                    Adj[i][j] = 0; // assign all of the values of the matrix to 0
            }
    }

    printf("\n");
    for(i=0;i<E;i++){
        printf("Enter Source, Destination and Path Cost: ");
        scanf("%d %d %d", &s, &d, &pc); // input the source, destination and path cost(use space between input)
        Adj[s][d] = Adj[d][s] = pc; // assign the value of path cost to the source and destination
    }

    printf("\n");
    for(i=1;i<=N;i++){
        printf("Enter Straight Line Distance of Node %d: ",i);
        scanf("%d", &SLD[i]); // input the sld of each node
    }

    printf("\nAdjacency Matrix\n-----------------\n");
    for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                printf("%d ", Adj[i][j]); //print adjacency matrix
            }
            printf("\n");
    }
}

void GBFS(int sn,int Gn){
    int current_node = sn;
    int i,min_sld,temp_state,total_cost = 0;

    while(current_node != Gn){ // current node is not equal to the goal node
        for(i=1;i<=N;i++){
            min_sld = 1000000;
            if(Adj[current_node][i] != 0){
                if(SLD[i] < min_sld){
                    min_sld = SLD[i];
                    temp_state = i;
                }
            }
        }
        total_cost = total_cost + Adj[current_node][temp_state]; //total path cost
        current_node = temp_state; //current node
        printf(" %d",current_node); //printing current node
    }
        printf("\nTotal Path Cost: %d",total_cost); //printing total path cost
}

int main(){
    system("COLOR E0"); // terminal colour
    input_and_Graph();
    int starting_node,Goal_node;
    printf("\nEnter Starting Node: ");
    scanf("%d", &starting_node); // input the starting node
    printf("Enter Goal Node: ");
    scanf("%d", &Goal_node); // input the goal node
    printf("\n-------------------------------\n");
    printf("Nodes: ");
    printf("%d",starting_node);
    GBFS(starting_node,Goal_node);
    printf("\n-------------------------------\n");
}
