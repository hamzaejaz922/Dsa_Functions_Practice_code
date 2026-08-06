#include <iostream>
#include "Link_List9.h"
using namespace std;

int main()
{
    int choice, val, level;
    func bst;
    func bst_rev;
    func bst_stu;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(30);

    while (true)
    {
        cout << "\n======= BINARY SEARCH TREE MENU =======\n";
        cout << " 1.  Insert value\n";
        cout << " 2.  Delete value\n";
        cout << " 3.  Non-Recursive Preorder Traversal\n";
        cout << " 4.  Non-Recursive Inorder Traversal\n";
        cout << " 5.  Non-Recursive Postorder Traversal\n";
        cout << " 6.  Insert into Reversed BST\n";
        cout << " 7.  Display Reversed BST\n";
        cout << " 8.  Insert Student Record\n";
        cout << " 9.  Search Student by Roll No\n";
        cout << "10.  Display Leaf Nodes\n";
        cout << "11.  Delete All Leaf Nodes\n";
        cout << "12.  Inorder Successor\n";
        cout << "13.  Inorder Predecessor\n";
        cout << "14.  Display Nodes at Given Level\n";
        cout << "15.  Display All Left Child Nodes\n";
        cout << "16.  Largest Value at Given Level\n";
        cout << "17.  Display All Right Child Nodes\n";
        cout << "18.  Display Full BST\n";
        cout << "19.  Exit\n";
        cout << "========================================\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insert(val);
                return_menu();
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                bst.deleteNode(val);
                return_menu();
                break;

            case 3:
                bst.preorder_NR();
                return_menu();
                break;

            case 4:
                bst.inorder_NR();
                return_menu();
                break;

            case 5:
                bst.postorder_NR();
                return_menu();
                break;

            case 6:
                cout << "Enter value to insert in Reversed BST: ";
                cin >> val;
                bst_rev.insert_reversed(val);
                return_menu();
                break;

            case 7:
                bst_rev.display_reversed();
                return_menu();
                break;

            case 8:
            {
                int roll;
                string name;
                float gpa;
                cout << "Enter Roll No : ";
                cin >> roll;
                cout << "Enter Name    : ";
                cin >> name;
                cout << "Enter GPA     : ";
                cin >> gpa;
                bst_stu.insert_student(roll, name, gpa);
                return_menu();
                break;
            }

            case 9:
                cout << "Enter Roll No to search: ";
                cin >> val;
                bst_stu.search_student(val);
                return_menu();
                break;

            case 10:
                bst.display_leaves();
                return_menu();
                break;

            case 11:
                bst.display_leaves();
                bst.delete_leaves();
                return_menu();
                break;

            case 12:
                cout << "Enter value: ";
                cin >> val;
                bst.inorder_successor(val);
                return_menu();
                break;

            case 13:
                cout << "Enter value: ";
                cin >> val;
                bst.inorder_predecessor(val);
                return_menu();
                break;

            case 14:
                cout << "Enter level (root = 1): ";
                cin >> level;
                bst.display_level(level);
                return_menu();
                break;

            case 15:
                bst.display_left_nodes();
                return_menu();
                break;

            case 16:
                cout << "Enter level (root = 1): ";
                cin >> level;
                bst.largest_at_level(level);
                return_menu();
                break;

            case 17:
                bst.display_right_nodes();
                return_menu();
                break;

            case 18:
                bst.display();
                return_menu();
                break;

            case 19:
                exit(0);

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
