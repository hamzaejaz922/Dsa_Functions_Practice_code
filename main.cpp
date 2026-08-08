#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
    func f;
    int choice, data, pos;

    while(true)
    {
        cout<<"\n===== LINKED LIST MENU =====\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at Middle\n";
        cout<<"3. Insert at End\n";
        cout<<"4. Delete at Beginning\n";
        cout<<"5. Delete at Middle\n";
        cout<<"6. Delete at End\n";
        cout<<"7. Delete by Value\n";
        cout<<"8. Display\n";
        cout<<"9. Count\n";
        cout<<"10. Reverse\n";
        cout<<"11. Search\n";
        cout<<"12. Largest\n";
        cout<<"13. Smallest\n";
        cout<<"14. Average\n";
        cout<<"15. Even/Odd Count\n";
        cout<<"16. Occurrence\n";
        cout<<"17. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                f.add_at_beg(data);
                break;

            case 2:
                cout<<"Enter data: ";
                cin>>data;
                cout<<"Enter position: ";
                cin>>pos;
                f.add_at_middle(data,pos);
                break;

            case 3:
                cout<<"Enter data: ";
                cin>>data;
                f.add_at_end(data);
                break;

            case 4:
                f.delete_at_beg();
                break;

            case 5:
                cout<<"Enter position: ";
                cin>>pos;
                f.delete_at_middle(pos);
                break;

            case 6:
                f.delete_at_end();
                break;

            case 7:
                cout<<"Enter value to delete: ";
                cin>>data;
                f.delete_by_value(data);
                break;

            case 8:
                f.display();
                break;

            case 9:
                f.count();
                break;

            case 10:
                f.reverse();
                cout<<"List Reversed!\n";
                break;

            case 11:
                cout<<"Enter value to search: ";
                cin>>data;
                f.search(data);
                break;

            case 12:
                f.largest();
                break;

            case 13:
                f.smallest();
                break;

            case 14:
                f.average();
                break;

            case 15:
                f.even_odd_count();
                break;

            case 16:
                cout<<"Enter value: ";
                cin>>data;
                f.occurrence(data);
                break;

            case 17:
                cout<<"Exiting Program...\n";
                return 0;

            default:
                cout<<"Invalid Choice!\n";
        }
    }
}