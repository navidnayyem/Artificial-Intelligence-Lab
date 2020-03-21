//Q. Please implement A* search for the following function.
//   f(x) = g(x) + h(x)*0.8
//   Input any graph along with the h(x) values and output the optimal path cost from a source node to a goal node.

#include<stdio.h>
#include<stdlib.h>

int V,E; // integer variable of vertices and nodes
int Adj[20][20]; // adjacency matrix of size 20 by 20(row and column)
int h[20]; // integer array of heuristic value of size 20

void input(){
    int i,j,source,destination,path_cost; //integer variable
    printf("---A* Search Algorithm---\n\n");

    //taking input of vertices and nodes
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges: ");
    scanf("%d", &E);
    printf("\n");

    //taking input of source,destination and path cost
    for(i=0;i<E;i++){
        printf("Enter Source: ");
        scanf("%d", &source);
        printf("Enter Destination: ");
        scanf("%d", &destination);
        printf("Enter Path Cost: ");
        scanf("%d", &path_cost);
        Adj[source][destination] = Adj[destination][source] = path_cost; // assign the value of path cost to the source and destination
        printf("\n");
    }

    for(i=1;i<=V;i++){
        printf("Enter Heuristic Value(h[%d]) of Node %d: ", i,i);
        scanf("%d", &h[i]); //taking input of heuristic value of each node
    }
    printf("\n");


}
void A_Star(int sn,int Gn){ // A_Star function with parameters
    int current_node = sn; // assign source node to the current node
    double optimal_path_cost = 0.0; //initialize optimal path cost to 0
    int index,i; //integer variable
    while(current_node != Gn){ // current node is not equal to goal node
        double min_cost = 1000.0; //large value
        for(i=1;i<=V;i++){
            if(Adj[current_node][i] != 0){ //adjacent
                    if(min_cost > Adj[current_node][i] + h[i] * 0.8){
                        min_cost = Adj[current_node][i] + (h[i] * 0.8) + optimal_path_cost;
                        index = i;
                    }
            }
        }
        optimal_path_cost = optimal_path_cost + Adj[current_node][index]; // calculate optimal path cost
        current_node = index;
    }
    printf("%0.2f\n", optimal_path_cost); //printing optimal path cost
}

int main(){
    system("COLOR F0"); //terminal color
    int source_node,goal_node; //integer variable
    input();
    //taking input of source and goal node
    printf("Enter the Source Node: ");
    scanf("%d", &source_node);
    printf("Enter the Goal Node: ");
    scanf("%d", &goal_node);

    printf("\nThe Optimal Path Cost from Source Node %d to Goal Node %d is: ", source_node,goal_node); //printing optimal path cost from source node to goal node
    A_Star(source_node,goal_node); //calling A_Star function with parameters
}
