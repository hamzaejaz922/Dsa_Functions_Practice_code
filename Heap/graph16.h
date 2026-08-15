//#ifndef GRAPH_H
//#define GRAPH_H
//
//#include <iostream>
//using namespace std;
//
//struct Node
//{
//    int vertex;
//    Node* next;
//};
//
//void initialize(int vertices);
//void addEdge(int u,int v);
//void detectCycles(int vertices);
//
//#endif

















#ifndef GRAPH16_H
#define GRAPH16_H

#include <iostream>
using namespace std;

struct Edge
{
    int vertex;
    Edge* next;
};

struct Vertex
{
    int data;
    bool visited;
    int parent;

    Edge* adj;
    Vertex* next;
};

void initialize(int vertices);
void addEdge(int u,int v);
void detectCycles();

#endif