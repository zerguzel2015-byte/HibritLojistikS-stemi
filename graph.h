#ifndef GRAPH_H
#define GRAPH_H
#include "types.h"

void init_graph(GraphNode* graph);
void add_city(GraphNode* graph, int index, const char* name);
void add_edge(GraphNode* graph, int src, int dest);
void dfs(GraphNode* graph, int vertex);
void reset_visited(GraphNode* graph);

#endif
