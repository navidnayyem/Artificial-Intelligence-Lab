#include<stdio.h>

int color[10] = {0,0,0,0,0,0,0,0,0,0};
int time = 1;
int dt[10]; //discovery time
int ft[10]; //finishing time
int depth[10] = {0,0,0,0,0,0,0,0,0,0,0};
int N,E;
int Adj[10][10];

initGraph(){
    int i,j,s,d;
    printf("Enter the Number of Nodes: ");
    scanf("%d", &N);
    printf("Enter the Number of Edges: ");
    scanf("%d", &E);

    for(i=0;i<=N;i++){
            for(j=0;j<=N;j++){
                    Adj[i][j] = 0;
            }
    }

    printf("\n");
    for(i=0;i<E;i++){
        printf("Enter Source: ");
        scanf("%d", &s);
        printf("Enter Destination: ");
        scanf("%d", &d);
        Adj[s][d] = Adj[d][s] = 1;
    }
}

void DFS_visit(int s){
    int d;
    int depthlimit = 1;
    color[s] = 1; //discovered
    dt[s] = time++;

    for(d=1;d<=N;d++){
        if(Adj[s][d] == 1)
            if(color[d] == 0)
                DFS_visit(d);
    }
    color[s] = 2; // visited
    ft[s] = time++;
    if (depth < depthlimit){
        depth[d] = 1;
    } else {
        depth[d] = 0;
    }
}

int main(){
    initGraph();
    printf("\nN DT | FT\n");
    DFS_visit(1);
    int i,index=1;
    for(i=1;i<=N;i++){
        printf("%d %d  | %d\n",index++,dt[i],ft[i]); //printing node index,discovery and finishing time
    }
}
