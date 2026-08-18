#include "graph.h"

int main()
{
    Vertex* start = NULL;

    int choice;

    while(true)
    {
        cout << "========== GRAPH MENU ==========\n";

        cout << "1. Insert Node\n";
        cout << "2. Insert Edge\n";
        cout << "3. Delete Node\n";
        cout << "4. Delete Edge\n";
        cout << "5. Display Graph\n";
        cout << "6. BFS\n";
        cout << "7. DFS\n";
        cout << "8. Connected Graph\n";
        cout << "9. Complete Graph\n";
        cout << "10. Dijkstra\n";
		cout << "11. Prim's MST\n";
		cout << "12. Kruskal MST\n";
		cout << "13. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            char val;

            cout << "Enter Node: ";
            cin >> val;

            insertNode(start, val);
        }

        else if(choice == 2)
        {
            char u, v;
            int w;

            cout << "Enter Source Node: ";
            cin >> u;

            cout << "Enter Destination Node: ";
            cin >> v;

            cout << "Enter Weight: ";
            cin >> w;

            insertEdge(start, u, v, w);
        }

        else if(choice == 3)
        {
            char val;

            cout << "Enter Node to Delete: ";
            cin >> val;

            deleteNode(start, val);
        }

        else if(choice == 4)
        {
            char u, v;

            cout << "Enter Source Node: ";
            cin >> u;

            cout << "Enter Destination Node: ";
            cin >> v;

            deleteEdge(start, u, v);
        }

        else if(choice == 5)
        {
            display(start);
        }

        else if(choice == 6)
        {
            char node;

            cout << "Enter Starting Node: ";
            cin >> node;

            BFS(start, node);
        }

        else if(choice == 7)
        {
            char node;

            cout << "Enter Starting Node: ";
            cin >> node;

            DFS(start, node);
        }

        else if(choice == 8)
        {
            connectedGraph(start);
        }

        else if(choice == 9)
        {
            completeGraph(start);
        }

        else if(choice == 10)
        {
            char s, d;

            cout << "Enter Source Node: ";
            cin >> s;

            cout << "Enter Destination Node: ";
            cin >> d;

            dijkstra(start, s, d);
        }
        
        else if(choice == 11)
		{
		    char source;
		
			cout << "Enter Starting Vertex: ";
			cin >> source;
			
			prim(start, source);
		
		}
		
		else if(choice == 12)
		{
    		kruskal(start);
		}
		
        else if(choice == 13)
        {
            break;
        }

        else
        {
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}