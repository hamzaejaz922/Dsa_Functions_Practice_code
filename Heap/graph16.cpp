//#include "Graph16.h"
//
//Node* adj[20];
//
//bool visited[20];
//int parentArr[20];
//
//int cycleCount = 0;
//
//void initialize(int vertices)
//{
//    for(int i=0;i<vertices;i++)
//    {
//        adj[i] = NULL;
//        visited[i] = false;
//        parentArr[i] = -1;
//    }
//}
//
//void addEdge(int u,int v)
//{
//    Node* temp = new Node;
//
//    temp->vertex = v;
//    temp->next = adj[u];
//    adj[u] = temp;
//
//    temp = new Node;
//
//    temp->vertex = u;
//    temp->next = adj[v];
//    adj[v] = temp;
//}
//
//void printCycle(int start,int end)
//{
//    cout << "\nCycle " << cycleCount + 1 << " : ";
//
//    int curr = start;
//
//    cout << end << " ";
//
//    while(curr != end && curr != -1)
//    {
//        cout << curr << " ";
//        curr = parentArr[curr];
//    }
//
//    cout << end << endl;
//}
//
//void DFS(int vertex,int parent)
//{
//    visited[vertex] = true;
//
//    Node* temp = adj[vertex];
//
//    while(temp)
//    {
//        int neighbour = temp->vertex;
//
//        if(!visited[neighbour])
//        {
//            parentArr[neighbour] = vertex;
//
//            DFS(neighbour,vertex);
//        }
//        else if(neighbour != parent &&
//                cycleCount < 3)
//        {
//            printCycle(vertex,neighbour);
//
//            cycleCount++;
//        }
//
//        temp = temp->next;
//    }
//}
//
//void detectCycles(int vertices)
//{
//    for(int i=0;i<vertices;i++)
//    {
//        if(!visited[i])
//        {
//            DFS(i,-1);
//        }
//    }
//
//    if(cycleCount == 0)
//    {
//        cout << "\nNo Cycle Found";
//    }
//}






















#include "Graph16.h"

Vertex* graph = NULL;
int cycleCount = 0;

Vertex* findVertex(int v)
{
    Vertex* temp = graph;

    while(temp)
    {
        if(temp->data == v)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void initialize(int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        Vertex* temp = new Vertex;

        temp->data = i;
        temp->visited = false;
        temp->parent = -1;
        temp->adj = NULL;

        temp->next = graph;
        graph = temp;
    }
}

void addEdge(int u,int v)
{
    Vertex* U = findVertex(u);
    Vertex* V = findVertex(v);

    Edge* temp = new Edge;
    temp->vertex = v;
    temp->next = U->adj;
    U->adj = temp;

    temp = new Edge;
    temp->vertex = u;
    temp->next = V->adj;
    V->adj = temp;
}

void DFS(int v,int parent)
{
    Vertex* curr = findVertex(v);
    curr->visited = true;

    Edge* temp = curr->adj;

    while(temp)
    {
        Vertex* nbr = findVertex(temp->vertex);

        if(!nbr->visited)
        {
            nbr->parent = v;
            DFS(temp->vertex,v);
        }
        else if(temp->vertex != parent && cycleCount < 3)
        {
            cout << "\nCycle Found Between "
                 << v << " and "
                 << temp->vertex;

            cycleCount++;
        }

        temp = temp->next;
    }
}

void detectCycles()
{
    Vertex* temp = graph;

    while(temp)
    {
        if(!temp->visited)
            DFS(temp->data,-1);

        temp = temp->next;
    }

    if(cycleCount == 0)
        cout << "\nNo Cycle Found";
}