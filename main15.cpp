//#include "Graph15.h"
//
//int main()
//{
//    int vertices;
//
//    cout<<"Enter Number of Vertices: ";
//    cin>>vertices;
//
//    for(int i=0;i<vertices;i++)
//    {
//        addVertex(i);
//    }
//
//    int choice;
//
//    do
//    {
//        int src,dest,weight;
//
//        cout<<"\nEnter Source Vertex: ";
//        cin>>src;
//
//        cout<<"Enter Destination Vertex: ";
//        cin>>dest;
//
//        cout<<"Enter Weight: ";
//        cin>>weight;
//
//        addEdge(src,dest,weight);
//
//        cout<<"\n1. Add More Edge";
//        cout<<"\n0. Run Dijkstra";
//        cout<<"\nChoice: ";
//        cin>>choice;
//
//    }while(choice==1);
//
//    int source;
//
//    cout<<"\nEnter Source Node: ";
//    cin>>source;
//
//    dijkstra(vertices,source);
//
//    return 0;
//}



#include "Graph15.h"

int main()
{
    int vertices;

    cout << "Enter Number of Vertices: ";
    cin >> vertices;

    initializeGraph(vertices);

    int choice;

    do
    {
        int src, dest, weight;

        cout << "\nEnter Source Vertex: ";
        cin >> src;

        cout << "Enter Destination Vertex: ";
        cin >> dest;

        cout << "Enter Weight: ";
        cin >> weight;

        addEdge(src, dest, weight);

        cout << "\n1. Add More Edge";
        cout << "\n0. Run Dijkstra";
        cout << "\nChoice: ";
        cin >> choice;

    }while(choice == 1);

    int source;

    cout << "\nEnter Source Node: ";
    cin >> source;

    dijkstra(vertices, source);

    return 0;
}



