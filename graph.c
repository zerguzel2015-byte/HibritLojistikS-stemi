#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void init_graph(GraphNode* graph) {
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        graph[i].head = NULL;
        graph[i].visited = 0;
    }
}

void add_city(GraphNode* graph, int index, const char* name) {
    strcpy(graph[index].city_name, name);
}

void add_edge(GraphNode* graph, int src, int dest) {
    EdgeNode* new_edge;
    new_edge = (EdgeNode*)malloc(sizeof(EdgeNode));
    new_edge->target_vertex = dest;
    new_edge->next = graph[src].head;
    graph[src].head = new_edge;
}

void reset_visited(GraphNode* graph) {
    int i;
    for(i = 0; i < MAX_CITIES; i++) {
        graph[i].visited = 0;
    }
}

/* DFS (Depth-First Search) Gezinme Algoritması */
void dfs(GraphNode* graph, int vertex) {
    EdgeNode* temp;
    graph[vertex].visited = 1;
    printf("%s -> ", graph[vertex].city_name);

    temp = graph[vertex].head;
    while (temp != NULL) {
        if (graph[temp->target_vertex].visited == 0) {
            dfs(graph, temp->target_vertex);
        }
        temp = temp->next;
    }
}
