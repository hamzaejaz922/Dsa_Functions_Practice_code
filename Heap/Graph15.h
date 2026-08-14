//#ifndef GRAPH_H
//#define GRAPH_H
//
//#include <iostream>
//using namespace std;
//
//struct Edge
//{
//    int dest;
//    int weight;
//    Edge* next;
//};
//
//struct Vertex
//{
//    int data;
//    Edge* adj;
//    Vertex* next;
//};
//
//struct Distance
//{
//    int vertex;
//    int dist;
//    bool visited;
//    Distance* next;
//};
//
//extern Vertex* graph;
//
//void addVertex(int v);
//void addEdge(int src,int dest,int weight);
//
//Distance* createDistanceList(int vertices,int source);
//Distance* findDistanceNode(Distance* head,int vertex);
//Distance* getMinNode(Distance* head);
//
//void dijkstra(int vertices,int source);
//
//#endif



#ifndef GRAPH15_H
#define GRAPH15_H

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 20;

extern int graph[MAX][MAX];

void initializeGraph(int vertices);
void addEdge(int src, int dest, int weight);
void dijkstra(int vertices, int source);

#endif