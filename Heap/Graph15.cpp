//#include "Graph15.h"
//
//Vertex* graph = NULL;
//
//void addVertex(int v)
//{
//    Vertex* temp = new Vertex;
//
//    temp->data = v;
//    temp->adj = NULL;
//    temp->next = NULL;
//
//    if(graph == NULL)
//    {
//        graph = temp;
//        return;
//    }
//
//    Vertex* curr = graph;
//
//    while(curr->next)
//        curr = curr->next;
//
//    curr->next = temp;
//}
//
//Vertex* findVertex(int v)
//{
//    Vertex* curr = graph;
//
//    while(curr)
//    {
//        if(curr->data == v)
//            return curr;
//
//        curr = curr->next;
//    }
//
//    return NULL;
//}
//
//void addEdge(int src,int dest,int weight)
//{
//    Vertex* v = findVertex(src);
//
//    if(v == NULL)
//        return;
//
//    Edge* temp = new Edge;
//
//    temp->dest = dest;
//    temp->weight = weight;
//    temp->next = v->adj;
//
//    v->adj = temp;
//}
//
//Distance* createDistanceList(int vertices,int source)
//{
//    Distance* head = NULL;
//    Distance* last = NULL;
//
//    for(int i=0;i<vertices;i++)
//    {
//        Distance* temp = new Distance;
//
//        temp->vertex = i;
//        temp->dist = "no path";
//        temp->visited = false;
//        temp->next = NULL;
//
//        if(i == source)
//            temp->dist = 0;
//
//        if(head == NULL)
//        {
//            head = temp;
//            last = temp;
//        }
//        else
//        {
//            last->next = temp;
//            la\st = temp;
//        }
//    }
//
//    return head;
//}
//
//Distance* findDistanceNode(Distance* head,int vertex)
//{
//    while(head)
//    {
//        if(head->vertex == vertex)
//            return head;
//
//        head = head->next;
//    }
//
//    return NULL;
//}
//
//Distance* getMinNode(Distance* head)
//{
//    Distance* minNode = NULL;
//
//    while(head)
//    {
//        if(!head->visited)
//        {
//            if(minNode == NULL ||
//               head->dist < minNode->dist)
//            {
//                minNode = head;
//            }
//        }
//
//        head = head->next;
//    }
//
//    return minNode;
//}
//
//void dijkstra(int vertices,int source)
//{
//    Distance* distList =
//        createDistanceList(vertices,source);
//
//    for(int i=0;i<vertices;i++)
//    {
//        Distance* u = getMinNode(distList);
//
//        if(u == NULL)
//            break;
//
//        u->visited = true;
//
//        Vertex* currentVertex =
//            findVertex(u->vertex);
//
//        Edge* edge = currentVertex->adj;
//
//        while(edge)
//        {
//            Distance* v =
//                findDistanceNode(
//                    distList,
//                    edge->dest);
//
//            if(!v->visited &&
//               u->dist + edge->weight < v->dist)
//            {
//                v->dist =
//                    u->dist + edge->weight;
//            }
//
//            edge = edge->next;
//        }
//    }
//
//    cout << "\nShortest Paths\n";
//
//    Distance* temp = distList;
//
//    while(temp)
//    {
//        cout << source
//             << " -> "
//             << temp->vertex
//             << " = "
//             << temp->dist
//             << endl;
//
//        temp = temp->next;
//    }
//}
















#include "Graph15.h"

int graph[MAX][MAX];

void initializeGraph(int vertices)
{
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest, int weight)
{
    graph[src][dest] = weight;
    graph[dest][src] = weight;
}

void dijkstra(int vertices, int source)
{
    int dist[MAX];
    bool visited[MAX];

    for(int i=0; i<vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        if(visited[current])
            continue;

        visited[current] = true;

        for(int i=0; i<vertices; i++)
        {
            if(graph[current][i] != 0)
            {
                if(dist[current] + graph[current][i] < dist[i])
                {
                    dist[i] = dist[current] + graph[current][i];
                    q.push(i);
                }
            }
        }
    }

    cout << "\nShortest Distances From Source " << source << endl;

    for(int i=0; i<vertices; i++)
    {
        cout << "Vertex " << i
             << " -> Distance = "
             << dist[i] << endl;
    }
}