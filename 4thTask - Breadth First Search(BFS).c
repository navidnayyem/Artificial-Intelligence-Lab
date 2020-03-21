#include<stdio.h>
#include<stdlib.h>

//global variables
int Q[20]; // queue array of size 20
int head = 0; // initially the head of the queue is 0
int tail = 0; // initially the tail of the queue is 0
int color[10]; // color array of size 10
int Adj[10][10]; // max size 10 by 10 adjacency matrix
int dt[20]; //discovery time
int ft[20]; //finishing time
int N,E; // node and edge integer variable
int time = 1;
int parent[10];

void initGraph(){
    int i,j,s,d;
    printf("***Breadth First Search(BFS)***\n\n");
    printf("Enter the Number of Nodes: ");
    scanf("%d", &N); // input the total number of nodes
    printf("Enter the Number of Edges: ");
    scanf("%d", &E); // input the total number of edges

    for(i=0;i<=N;i++){
            for(j=0;j<=N;j++){
                    Adj[i][j] = 0; // assign all of the values of the matrix to 0
            }
            color[i] = 0; //initialize colour to 0
            parent[i] = -1; // node by itself
    }
    printf("\n");

    for(i=0;i<E;i++){
        printf("Enter Source: ");
        scanf("%d", &s); // input the source
        printf("Enter Destination: ");
        scanf("%d", &d); // input the destination
        Adj[s][d] = Adj[d][s] = 1; // assign the source and destination to 1 as it is adjacent
    }

    printf("\nAdjacency Matrix\n-----------------\n");
    for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                printf("%d ", Adj[i][j]); //print adjacency matrix
            }
            printf("\n");
    }
}

void enqueue(int item){
    Q[tail] = item; // item has been inserted in the tail of the queue
    tail++; // tail is incremented
    dt[item] = time++; //discovery time
}

int dequeue(){
    int item;
    item = Q[head]; // the value of head of the queue
    head++; // head is incremented
    ft[item] = time++; //finishing time
    return item;
}

void BFS(){
    int u,v;
    while (head != tail){
        u = Q[head];
        for(v=1;v<=N;v++){
            if(Adj[u][v] == 1){ // 1 means there are adjacent nodes
                if(color[v] == 0){ // O means white(untouched)
                    color[v] = 1;  // 1 means gray(discovered)
                    enqueue(v);
                    parent[v] = u;
                }
            }
        }
        color[u] = 2; // 2 means black(visited)
        dequeue();
    }
}

int main(){
    system("COLOR F0"); // terminal colour
    initGraph();
    int starting_node = 1;
    enqueue(starting_node);
    color[starting_node] = 1; // 1 means gray(discovered)
    BFS();
    int index = 1;
    printf("\n N | DT | FT | C | PN \n---|----|----|---|----\n");
    for(int i=1;i<=N;i++){
        printf(" %d | %d  | %d | %d  | %d\n",index++,dt[i],ft[i],color[i], parent[i]); //printing node index,discovery,finishing time,color array and parent node
    }
}
