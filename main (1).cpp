#include "heap1.h"

int main()
{
    int choice, item, level;

    while (1)
    {
        cout << "\n===== HEAP MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Find Max\n";
        cout << "6. Find Min\n";
        cout << "7. Display Level\n";
        cout << "8. Display Leaf Nodes\n";
        cout << "9. Successor / Predecessor\n";
        cout << "10. Reverse Insert (Min Heap)\n";
        cout << "11. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter item: ";
                cin >> item;
                insert(item);
                break;

            case 2:
                cout << "Enter item to delete: ";
                cin >> item;
                del(item);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Enter item to search: ";
                cin >> item;
                search(item);
                break;

            case 5:
                find_max();
                break;

            case 6:
                find_min();
                break;

            case 7:
                cout << "Enter level: ";
                cin >> level;
                display_level(level);
                break;

            case 8:
                display_leaf_nodes();
                break;

            case 9:
                cout << "Enter item: ";
                cin >> item;
                inorder_succ_pred(item);
                break;

            case 10:
                cout << "Enter item: ";
                cin >> item;
                insert_reverse(item);
                break;

            case 11:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}