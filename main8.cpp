#include <iostream>
#include "Link_List8.h"
using namespace std;

int main() {
    func f;
    node* dq = NULL;
    node* queues[3] = {NULL, NULL, NULL};
    int choice, data;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Reverse Queue\n";
        cout << "2. Sort Dequeue Desc\n";
        cout << "3. Insert Front to Dequeue\n";
        cout << "4. Insert Rear to Dequeue\n";
        cout << "5. Delete Front from Dequeue\n";
        cout << "6. Delete Rear from Dequeue\n";
        cout << "7. Check Identical Queues\n";
        cout << "8. Palindrome using Dequeue\n";
        cout << "9. Call Center Simulation\n";
        cout << "10. Display Dequeue\n";
        cout << "11. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1:
                f.reverse_queue(dq);
                break;
            case 2:
                f.sort_dequeue_desc(dq);
                break;
            case 3:
                cout << "Enter value: "; cin >> data;
                f.insert_front(dq, data);
                break;
            case 4:
                cout << "Enter value: "; cin >> data;
                f.insert_rear(dq, data);
                break;
            case 5:
                f.delete_front(dq);
                break;
            case 6:
                f.delete_rear(dq);
                break;
            case 7:
                if (f.identical_queues(queues[0], queues[1]))
                    cout << "Queues are identical.\n";
                else
                    cout << "Queues are NOT identical.\n";
                break;
            case 8:
                if (f.is_palindrome_deque(dq)) cout << "Palindrome\n";
                else cout << "Not Palindrome\n";
                break;
            case 9:
                // Sample call center simulation
                f.insert_rear(queues[0], 101);
                f.insert_rear(queues[1], 201);
                f.insert_rear(queues[2], 301);
                f.call_center_simulation(queues, 3);
                break;
            case 10:
                cout << "Deque elements: ";
                f.display_queue(dq);
                break;
            case 11:
                return 0;
        }
    }
}