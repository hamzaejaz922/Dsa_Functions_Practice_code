//#include "Graph16.h"
//
//int main()
//{
//    int vertices;
//
//    cout << "Enter Number of Vertices: ";
//    cin >> vertices;
//
//    initialize(vertices);
//
//    int choice;
//
//    do
//    {
//        int u,v;
//
//        cout << "\nEnter First Vertex : ";
//        cin >> u;
//
//        cout << "Enter Second Vertex : ";
//        cin >> v;
//
//        addEdge(u,v);
//
//        cout << "\n1. Add More Edge";
//        cout << "\n0. Detect Cycles";
//        cout << "\nEnter Choice : ";
//        cin >> choice;
//
//    }while(choice == 1);
//
//    cout << "\nSearching Cycles...\n";
//
//    detectCycles(vertices);
//
//    return 0;
//}
















#include "Graph16.h"

int main()
{
    int vertices;

    cout << "Enter Number of Vertices: ";
    cin >> vertices;

    initialize(vertices);

    int choice;

    do
    {
        int u,v;

        cout << "\nEnter First Vertex : ";
        cin >> u;

        cout << "Enter Second Vertex : ";
        cin >> v;

        addEdge(u,v);

        cout << "\n1. Add More Edge";
        cout << "\n0. Detect Cycles";
        cout << "\nEnter Choice : ";
        cin >> choice;

    }while(choice == 1);

    cout << "\nSearching Cycles...\n";

    detectCycles();

    return 0;
}