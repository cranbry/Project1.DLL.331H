#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    int input,value;

    DoublyLinkedList<int> DLL;
    DoublyLinkedList<int> copyDLL(DLL);
    DoublyLinkedList<int> newDLL;

    do {
        cout << "Doubly Linked List Menu:" << endl;
        cout << "1. Insert Front" << endl;
        cout << "2. Insert Back" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Clear List" << endl;
        cout << "5. Search Item" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "7. Get Length" << endl;
        cout << "8. Copy Constructor Test" << endl;
        cout << "9. Assignment Operator Test" << endl;
        cout << "10. Test Forward Iterator" << endl;
        cout << "11. Test Backward Iterator" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your input: " << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Enter value of the item to be inserted at Front:" << endl;
            cin >> value;
            DLL.insertFront(value);
            cout << value << " Has been inserted form front" << endl;
            break;
        case 2:
            cout << "Enter value of the item to be inserted at Back:" << endl;
            cin >> value;
            DLL.insertBack(value);
            cout << value << " Has been inserted from back" << endl;
            break;
        case 3:
            cout << "Enter value of the item to be deleted:" << endl;
            cin >> value;
            DLL.deleteItem(value);
            cout << value << " Has been deleted from list." << endl;
            break;
        case 4:
            DLL.Clear();
            cout << "List has been cleared." << endl;
        case 5:
            cout << "Enter value of the item to search for:" << endl;
            cin >> value;
            if (DLL.search(value)) {
                cout << value << " is found in the list." << endl;
            } else {
                cout << value << " is not in the list." << endl;
            }
            break;
        case 6:
            if (DLL.isEmpty()) {
                cout << "List is empty" << endl;
            } else {
                cout << "List is not empty." << endl;
            }
            break;
        case 7:
            cout << "The length of the list is: " << DLL.getLength() << endl;
            break;
        case 8:
            copyDLL = DLL;
            cout << "Original list is: " << endl;
            DLL.print();
            cout << "The copied list is: " << endl;
            copyDLL.print();
            break;
        case 9: 
            newDLL = DLL;
            cout << "Assigned list:" << endl;
            newDLL.print();
            break;
        case 10:
            cout << "List contents using forward iterator: ";
            for (DoublyLinkedList<int>::Iterator iterator = DLL.begin(); iterator != DLL.end(); ++iterator) {
                cout << *iterator << " ";
            }
            cout << endl;
            break;
        case 11:
            cout << "List contents using reverse iterator: ";
            for (DoublyLinkedList<int>::ReverseIterator iterator = DLL.rbegin(); iterator != DLL.rend(); ++iterator) {
                cout << *iterator << " ";
            }
            cout << endl;
            break;
        case 12:
            cout << "Exited Program" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (input != 12);
}