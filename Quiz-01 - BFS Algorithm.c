//Q. Implement the BFS algorithm to find the goal node given in the following graph. You have to print the discovery time of all of the nodes.

#include<stdio.h>
#include<stdlib.h>

int Q[20]; // queue array of size 20
int head = 0; // initially the head of the queue is 0
int tail = 0; // initially the tail of the queue is 0
int color[10]; // color array of size 10
int Adj[10][10]; // max size 10 by 10 adjacency matrix
int dt[20]; //discovery time
int N,E; // node and edge integer variable
int time = 1;

void initGraph(){
    int i,j,s,d;
    printf("|Breadth First Search(BFS)|\n\n");
    printf("Enter the Number of Nodes: ");
    scanf("%d", &N); // input the total number of nodes
    printf("Enter the Number of Edges: ");
    scanf("%d", &E); // input the total number of edges

    for(i=0;i<E;i++){
        printf("Enter Source: ");
        scanf("%d", &s); // input the source
        printf("Enter Destination: ");
        scanf("%d", &d); // input the destination
        Adj[s][d] = Adj[d][s] = 1; // assign the source and destination to 1 as it is adjacent
    }
}

void enqueue(int item){
    Q[tail] = item;
    tail++;
    dt[item] = time++; //discovery time
}

int dequeue(){
    int item;
    item = Q[head]; // the value of head of the queue
    head++; // head is incremented
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
                }
            }
        }
        color[u] = 2; // 2 means black(visited)
        dequeue();
    }
}

int main(){
    initGraph();
    int starting_node = 1;
    enqueue(starting_node);
    color[starting_node] = 1; // 1 means gray(discovered)
    BFS();
    int index = 1;
    printf("\n N | DT\n");
    for(int i=1;i<=N;i++){
        printf(" %d | %d\n",index++,dt[i]);
    }
}
