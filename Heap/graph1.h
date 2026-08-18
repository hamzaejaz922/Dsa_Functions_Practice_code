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

struct KEdge
{
    char src;
    char dest;
    int weight;
    KEdge* next;
};

struct SetNode
{
    char vertex;
    char parent;
    SetNode* next;
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
void dijkstra(Vertex* start,char source,char destination);
void prim(Vertex* start,char source);
void kruskal(Vertex* start);

#endif