#include <stdio.h>

void createGraph(int graph[][10],int vertices,int edges){
    for(int i=0; i<vertices;i++){
        for(int j=0;j<vertices;j++){
            graph[i][j]=0;
        }
    }
    int source,dest;
    for (int i=0 ; i<edges;i++){
        printf("Enter : source -> destination ");
        scanf("%d%d",&source,&dest);
        if((source>=0 && dest>=0 )&&(source<vertices && dest<vertices)){
            graph[source][dest]=1;
            graph[dest][source]=1;
        }else{
            printf("Invalid Vertices ");
            i--;
        }
    }
}

void printGraph(int graph[][10],int vertices){
    for (int i=0;i<vertices;i++){
        for (int j=0;j<vertices;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int vertices,edges;
    printf("Enter the no of vertices : ");
    scanf("%d",&vertices);
    int graph[vertices][10];
    printf("Enter the no of edges : ");
    scanf("%d",&edges);
    createGraph(graph,vertices,edges);
    printGraph(graph,vertices);
}

/*
Algorithm:

1. **Graph Creation Function (`createGraph`)**:
    - Accept the graph (as a 2D array), number of vertices (`vertices`), and number of edges (`edges`) as input.
    - Initialize the adjacency matrix (`graph`) by setting all elements to 0. This represents an empty graph with no edges between vertices.
    - For each edge (from 1 to `edges`):
        - Prompt the user to enter the source and destination vertices of the edge.
        - If both source and destination vertices are valid (i.e., they are within the range 0 to `vertices-1`):
            - Set `graph[source][dest]` and `graph[dest][source]` to 1, indicating an undirected edge between the two vertices.
        - If the input is invalid (source or destination is out of bounds), print an error message and prompt for the edge again.

2. **Graph Printing Function (`printGraph`)**:
    - Accept the graph (as a 2D array) and number of vertices (`vertices`) as input.
    - For each row (i.e., vertex) in the graph:
        - Print all the values in that row. These values represent the edges between the current vertex and other vertices.
    - A value of `1` in `graph[i][j]` indicates an edge from vertex `i` to vertex `j`, while a `0` indicates no edge.

3. **Main Function (`main`)**:
    - Accept the number of vertices (`vertices`) and the number of edges (`edges`) as input.
    - Declare a 2D array `graph[vertices][10]` to represent the graph's adjacency matrix (with a maximum of 10 vertices).
    - Call the `createGraph` function to create the graph based on the user input.
    - Call the `printGraph` function to display the adjacency matrix of the graph.

4. **Output**:
    - The program prints the adjacency matrix representing the graph. Each row corresponds to a vertex, and the entries indicate whether there is an edge between that vertex and other vertices.

*/
