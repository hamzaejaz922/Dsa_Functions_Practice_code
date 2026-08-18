#include "graph.h"

void insertNode(Vertex*& start, char val)
{
    Vertex* check = start;

    while(check != NULL)
    {
        if(check->data == val)
        {
            cout << "Node Already Exists\n";
            return;
        }

        check = check->next;
    }

    Vertex* temp = new Vertex;

    temp->data = val;
    temp->adj = NULL;

    temp->prev = NULL;
    temp->next = NULL;

    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        Vertex* ptr = start;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
        temp->prev = ptr;
    }

    cout << "Node Inserted\n";
}


void insertEdge(Vertex*& start, char u, char v, int w)
{
    Vertex* locU = NULL;
    Vertex* locV = NULL;

    Vertex* ptr = start;

    while(ptr != NULL)
    {
        if(ptr->data == u)
            locU = ptr;

        if(ptr->data == v)
            locV = ptr;

        ptr = ptr->next;
    }

    if(locU == NULL || locV == NULL)
    {
        cout << "Invalid Nodes\n";
        return;
    }

    Edge* temp = new Edge;

    temp->dest = v;
    temp->weight = w;
    temp->next = NULL;

    if(locU->adj == NULL)
    {
        locU->adj = temp;
    }
    else
    {
        Edge* q = locU->adj;

        while(q->next != NULL)
            q = q->next;

        q->next = temp;
    }

    cout << "Edge Inserted\n";
}


void deleteNode(Vertex*& start, char val)
{
    Vertex* ptr = start;

    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr == NULL)
    {
        cout << "Node Not Found\n";
        return;
    }

    Edge* e = ptr->adj;

    while(e != NULL)
    {
        Edge* temp = e;

        e = e->next;

        delete temp;
    }

    Vertex* p = start;

    while(p != NULL)
    {
        Edge* curr = p->adj;
        Edge* prev = NULL;

        while(curr != NULL)
        {
            if(curr->dest == val)
            {
                if(prev == NULL)
                    p->adj = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                break;
            }

            prev = curr;
            curr = curr->next;
        }

        p = p->next;
    }

    if(ptr == start)
    {
        start = ptr->next;

        if(start != NULL)
            start->prev = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;

        if(ptr->next != NULL)
            ptr->next->prev = ptr->prev;
    }

    delete ptr;

    cout << "Node Deleted\n";
}


void deleteEdge(Vertex*& start, char u, char v)
{
    Vertex* ptr = start;

    while(ptr != NULL && ptr->data != u)
        ptr = ptr->next;

    if(ptr == NULL)
    {
        cout << "Source Node Not Found\n";
        return;
    }

    Edge* curr = ptr->adj;
    Edge* prev = NULL;

    while(curr != NULL)
    {
        if(curr->dest == v)
        {
            if(prev == NULL)
                ptr->adj = curr->next;
            else
                prev->next = curr->next;

            delete curr;

            cout << "Edge Deleted\n";
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Edge Not Found\n";
}


void display(Vertex* start)
{
    Vertex* ptr = start;

    cout << "\nGRAPH ADJACENCY LIST\n";

    while(ptr != NULL)
    {
        cout << ptr->data << " -> ";

        Edge* q = ptr->adj;

        while(q != NULL)
        {
            cout << q->dest<< "(" << q->weight << ")";

            if(q->next != NULL)
                cout << " -> ";

            q = q->next;
        }

        cout << endl;

        ptr = ptr->next;
    }
}


void BFS(Vertex* start, char startNode)
{
    queue<char> q;

    Visit* visited = NULL;

    q.push(startNode);

    Visit* vtemp = new Visit;

    vtemp->data = startNode;
    vtemp->next = visited;

    visited = vtemp;

    cout << "BFS Traversal: ";

    while(!q.empty())
    {
        char current = q.front();
        q.pop();

        cout << current << " ";

        Vertex* ptr = start;

        while(ptr != NULL && ptr->data != current)
        {
            ptr = ptr->next;
        }

        if(ptr != NULL)
        {
            Edge* e = ptr->adj;

            while(e != NULL)
            {
                bool found = false;

                Visit* t = visited;

                while(t != NULL)
                {
                    if(t->data == e->dest)
                    {
                        found = true;
                        break;
                    }

                    t = t->next;
                }

                if(!found)
                {
                    q.push(e->dest);

                    Visit* newVisit = new Visit;

                    newVisit->data = e->dest;
                    newVisit->next = visited;

                    visited = newVisit;
                }

                e = e->next;
            }
        }
    }

    cout << endl;
}

void DFS(Vertex* start, char startNode)
{
    stack<char> st;

    Visit* visited = NULL;

    st.push(startNode);

    cout << "DFS Traversal: ";

    while(!st.empty())
    {
        char current = st.top();
        st.pop();

        bool found = false;

        Visit* t = visited;

        while(t != NULL)
        {
            if(t->data == current)
            {
                found = true;
                break;
             }

            t = t->next;
        }

        if(!found)
        {
            cout << current << " ";

            Visit* newVisit = new Visit;

            newVisit->data = current;
            newVisit->next = visited;

            visited = newVisit;

            Vertex* ptr = start;

            while(ptr != NULL && ptr->data != current)
               { ptr = ptr->next;}

            if(ptr != NULL)
            {
                Edge* e = ptr->adj;

                while(e != NULL)
                {
                    bool already = false;

                    Visit* x = visited;

                    while(x != NULL)
                    {
                        if(x->data == e->dest)
                        {
                            already = true;
                            break;
                        }

                        x = x->next;
                    }

                    if(!already)
                        st.push(e->dest);

                    e = e->next;
                }
            }
        }
    }

    cout << endl;
}


void connectedGraph(Vertex* start)
{
    if(start == NULL)
    {
        cout << "Graph Empty\n";
        return;
    }

    queue<char> q;

    Visit* visited = NULL;

    q.push(start->data);

    Visit* temp = new Visit;

    temp->data = start->data;
    temp->next = NULL;

    visited = temp;

    while(!q.empty())
    {
        char current = q.front();
        q.pop();

        Vertex* ptr = start;

        while(ptr != NULL && ptr->data != current)
            ptr = ptr->next;

        if(ptr != NULL)
        {
            Edge* e = ptr->adj;

            while(e != NULL)
            {
                bool found = false;

                Visit* t = visited;

                while(t != NULL)
                {
                    if(t->data == e->dest)
                    {
                        found = true;
                        break;
                    }

                    t = t->next;
                }

                if(!found)
                {
                    q.push(e->dest);

                    Visit* nv = new Visit;

                    nv->data = e->dest;
                    nv->next = visited;

                    visited = nv;
                }

                e = e->next;
            }
        }
    }

    bool connected = true;

    Vertex* check = start;

    while(check != NULL)
    {
        bool found = false;

        Visit* t = visited;

        while(t != NULL)
        {
            if(t->data == check->data)
            {
                found = true;
                break;
            }

            t = t->next;
        }

        if(!found)
        {
            connected = false;
            break;
        }

        check = check->next;
    }

    if(connected)
        cout << "Graph is Connected\n";
    else
        cout << "Graph is NOT Connected\n";
}


void completeGraph(Vertex* start)
{
    int totalNodes = 0;

    Vertex* ptr = start;

    while(ptr != NULL)
    {
        totalNodes++;
        ptr = ptr->next;
    }

    bool complete = true;

    ptr = start;

    while(ptr != NULL)
    { 
        int edgeCount = 0;

        Edge* e = ptr->adj;

        while(e != NULL)
        {
            edgeCount++;
            e = e->next;
        }

        if(edgeCount != totalNodes - 1)
        {
            complete = false;
            break;
        }

        ptr = ptr->next;
    }

    if(complete)
        cout << "Graph is Complete\n";
    else
        cout << "Graph is NOT Complete\n";
}


void dijkstra(Vertex* start, char source, char destination)
{
    struct DNode
    {
        char vertex;
        int dist;
        char parent;
        bool permanent;
        DNode* next;
    };

    DNode* head = NULL;

    Vertex* ptr = start;

    while(ptr != NULL)
    {
        DNode* temp = new DNode;

        temp->vertex = ptr->data;
        temp->dist = INT_MAX;
        temp->parent = '\0';
        temp->permanent = false;

        temp->next = head;

        head = temp;

        ptr = ptr->next;
    }

    DNode* s = head;

    while(s != NULL)
    {
        if(s->vertex == source)
        {
            s->dist = 0;
            break;
        }

        s = s->next;
    }

    while(true)
    {
        DNode* minNode = NULL;

        DNode* t = head;

        while(t != NULL)
        {
            if(!t->permanent && t->dist != INT_MAX)
            {
                if(minNode == NULL ||
                   t->dist < minNode->dist)
                {
                    minNode = t;
                }
            }

            t = t->next;
        }

        if(minNode == NULL)
            break;

        minNode->permanent = true;

        Vertex* current = start;

        while(current != NULL &&
              current->data != minNode->vertex)
        {
            current = current->next;
        }

        if(current != NULL)
        {
            Edge* e = current->adj;

            while(e != NULL)
            {
                DNode* dn = head;

                while(dn != NULL)
                {
                    if(dn->vertex == e->dest &&
                       !dn->permanent)
                    {
                        if(minNode->dist + e->weight
                           < dn->dist)
                        {
                            dn->dist =
                            minNode->dist + e->weight;

                            dn->parent =
                            minNode->vertex;
                        }
                    }

                    dn = dn->next;
                }

                e = e->next;
            }
        }
    }

    DNode* dest = head;

    while(dest != NULL &&
          dest->vertex != destination)
    {
        dest = dest->next;
    }

    if(dest == NULL || dest->dist == INT_MAX)
    {
        cout << "No Path Exists\n";
        return;
    }

    cout << "Shortest Distance = "
         << dest->dist << endl;

    cout << "Path: ";

    stack<char> path;

    char current = destination;

    while(current != '\0')
    {
        path.push(current);

        DNode* p = head;

        while(p != NULL)
        {
            if(p->vertex == current)
            {
                current = p->parent;
                break;
            }

            p = p->next;
        }
    }

    while(!path.empty())
    {
        cout << path.top();

        path.pop();

        if(!path.empty())
            cout << " -> ";
    }

    cout << endl;
}


void prim(Vertex* start, char source)
{
    struct PNode
    {
        char vertex;
        int key;
        char parent;
        bool permanent;
        PNode* next;
    };

    PNode* head = NULL;

    Vertex* ptr = start;

    while(ptr != NULL)
    {
        PNode* temp = new PNode;

        temp->vertex = ptr->data;
        temp->key = INT_MAX;
        temp->parent = '\0';
        temp->permanent = false;

        temp->next = head;
        head = temp;

        ptr = ptr->next;
    }

    // Source vertex key = 0
    PNode* s = head;

    while(s != NULL)
    {
        if(s->vertex == source)
        {
            s->key = 0;
            break;
        }

        s = s->next;
    }

    while(true)
    {
        PNode* minNode = NULL;

        PNode* t = head;

        while(t != NULL)
        {
            if(!t->permanent)
            {
                if(minNode == NULL ||
                   t->key < minNode->key)
                {
                    minNode = t;
                }
            }

            t = t->next;
        }

        if(minNode == NULL)
            break;

        minNode->permanent = true;

        Vertex* current = start;

        while(current != NULL &&
              current->data != minNode->vertex)
        {
            current = current->next;
        }

        if(current != NULL)
        {
            Edge* e = current->adj;

            while(e != NULL)
            {
                PNode* pn = head;

                while(pn != NULL)
                {
                    if(pn->vertex == e->dest &&
                       !pn->permanent)
                    {
                        if(e->weight < pn->key)
                        {
                            pn->key = e->weight;
                            pn->parent = minNode->vertex;
                        }
                    }

                    pn = pn->next;
                }

                e = e->next;
            }
        }
    }

    cout << "Minimum Spanning Tree:\n";

    int totalCost = 0;

    PNode* p = head;

    while(p != NULL)
    {
        if(p->parent != '\0')
        {
            cout << p->parent
                 << " - "
                 << p->vertex
                 << " ("
                 << p->key
                 << ")\n";

            totalCost += p->key;
        }

        p = p->next;
    }

    cout << "Total Cost = "
         << totalCost << endl;
}


void kruskal(Vertex* start)
{
    KEdge* edgeList = NULL;

    Vertex* v = start;

    // Create edge list
    while(v != NULL)
    {
        Edge* e = v->adj;

        while(e != NULL)
        {
            if(v->data < e->dest) // avoid duplicate edges
            {
                KEdge* temp = new KEdge;

                temp->src = v->data;
                temp->dest = e->dest;
                temp->weight = e->weight;

                temp->next = edgeList;
                edgeList = temp;
            }

            e = e->next;
        }

        v = v->next;
    }

    // Sort edge list (Bubble Sort)
    KEdge* p;
    KEdge* q;

    for(p = edgeList; p != NULL; p = p->next)
    {
        for(q = p->next; q != NULL; q = q->next)
        {
            if(p->weight > q->weight)
            {
                swap(p->src,q->src);
                swap(p->dest,q->dest);
                swap(p->weight,q->weight);
            }
        }
    }

    // Create disjoint sets
    SetNode* sets = NULL;

    v = start;

    while(v != NULL)
    {
        SetNode* temp = new SetNode;

        temp->vertex = v->data;
        temp->parent = v->data;

        temp->next = sets;
        sets = temp;

        v = v->next;
    }

    int totalCost = 0;

    cout << "MST Edges:\n";

    KEdge* edge = edgeList;

    while(edge != NULL)
    {
        char root1 = edge->src;

        while(true)
        {
            SetNode* s = sets;

            while(s != NULL && s->vertex != root1)
                s = s->next;

            if(s->parent == root1)
                break;

            root1 = s->parent;
        }

        char root2 = edge->dest;

        while(true)
        {
            SetNode* s = sets;

            while(s != NULL && s->vertex != root2)
                s = s->next;

            if(s->parent == root2)
                break;

            root2 = s->parent;
        }

        if(root1 != root2)
        {
            cout << edge->src
                 << " - "
                 << edge->dest
                 << " ("
                 << edge->weight
                 << ")\n";

            totalCost += edge->weight;

            SetNode* s = sets;

            while(s != NULL)
            {
                if(s->vertex == root1)
                {
                    s->parent = root2;
                    break;
                }

                s = s->next;
            }
        }

        edge = edge->next;
    }

    cout << "Total Cost = "
         << totalCost << endl;
}