#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

struct Visit
{
    char data;
    Visit* next;
};

struct Edge
{
    char dest;
    int weight;
    Edge* next;
};

struct Vertex
{
    char data;

    Vertex* prev;
    Vertex* next;

    Edge* adj;
};

void insertNode(Vertex*& start, char val);
void insertEdge(Vertex*& start, char u, char v, int w);
void deleteNode(Vertex*& start, char val);
void deleteEdge(Vertex*& start, char u, char v);
void display(Vertex* start);
void BFS(Vertex* start, char startNode);
void DFS(Vertex* start, char startNode);
void connectedGraph(Vertex* start);
void completeGraph(Vertex* start);
void dijkstra(Vertex* start, char source, char destination);

#endif