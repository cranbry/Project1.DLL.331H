#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template <typename T>

class DoublyLinkedList {
    private:
        struct Node{
            T info;
            Node* next;
            Node* prev;

            Node() : next(NULL), prev(NULL) {}
            Node (const T& item) : info(item), next(NULL), prev(NULL){}
        };
        Node* first;
        Node* last;
        int length;

    public:
        // Forward Iterator / traversing the list from first to last 
        class Iterator {
            private:
                Node* current; // pointer to current node
                
            public:
                // constructor
                Iterator(Node* node = NULL) : current(node) {}
                
                // dereferencing operator to get access to the value in the current node
                T& operator*() {
                    return current->info;
                }

                // move to next node and return updated iterator
                Iterator& operator++() {
                    if (current != NULL) {
                        current = current->next;
                    }
                    return *this;
                }

                // move to next node and return original position
                Iterator operator++(int) {
                    Iterator temp = *this; // saving original position
                    if (current != NULL) {
                        current = current->next;
                    }
                    return temp;
                }
                
                // check if two iterators point to same node (using it to test)
                bool operator==(const Iterator& other) const {
                    return current == other.current;
                }

                // check if two iterators point to different nodes (using it to test)
                bool operator!=(const Iterator& other) const {
                    return current != other.current;
                }
        };
        
        // Reverse Iterator / traversing the list from last to first
        class ReverseIterator {
            private:
                Node* current; // pointer to current node
                
            public:
                // constructor to initialize iterator
                ReverseIterator(Node* node = NULL) : current(node) {}
                
                // dereferencing operator to get access to the value in the current node
                T& operator*() {
                    return current->info;
                }
                
                // decrement operator moves backwards through the list
                ReverseIterator& operator++() {
                    if (current != NULL) {
                        current = current->prev;
                    }
                    return *this; // return reference to this iterator
                }
                
                // move backwards through the list but return orginal position
                ReverseIterator operator++(int) {
                    ReverseIterator temp = *this;
                    if (current != NULL) {
                        current = current->prev;
                    }
                    return temp;
                }

                // check if two iterators point to the same node (using it to test)
                bool operator==(const ReverseIterator& other) const {
                    return current == other.current;
                }

                // check if two iterators point to different nodes (using it to test)
                bool operator!=(const ReverseIterator& other) const {
                    return current != other.current;
                }
        };
        
        // Iterator methods

        // iterator pointing to the first node
        Iterator begin() {
            return Iterator(first);
        }
        
        // iterator pointing to after the last node
        Iterator end() {
            return Iterator(NULL);
        }
        
        // reverse iterator pointing to last node
        ReverseIterator rbegin() {
            return ReverseIterator(last);
        }
        
        // reverse iterator pointing to after the first node
        ReverseIterator rend() {
            return ReverseIterator(NULL);
        }

        // default constructor
        DoublyLinkedList() : first(NULL), last(NULL), length(0) {} // CLOSED default constructor 

        // destructor
        ~DoublyLinkedList() {

            Clear();

        } // CLOSED destructor 

        // copy constructor
        DoublyLinkedList(const DoublyLinkedList& other) : first(NULL), last(NULL), length(0) {
            // copying nodes from other list
            Node* current = other.first;
        
            // going thru and copying each node
            while (current != NULL) {
                insertBack(current->info);
                current = current->next;
            }
        } // CLOSED copy constructor

        // checking if list is empty
        bool isEmpty() const {

            return length == 0;
            
        } // CLOSED isEmpty()
        
        // returnoing length of the list
        int getLength() const {

            return length;

        } // CLOSED getLength()

        // overloading assignment operator
        DoublyLinkedList& operator=(const DoublyLinkedList& other) {

            if (this != &other) {
                // clearing the current list
                while (first != NULL) {
                    Node* p = first;
                    first = first->next;
                    delete p;
                }
                last = NULL;
                length = 0;
                
                // copy nodes from the other list
                if (other.first == NULL) {
                    first = NULL;
                    last = NULL;
                } else {
                    first = new Node;
                    first->info = other.first->info;
                    first->prev = NULL;
                    
                    Node* p = other.first->next;
                    Node* q = first;
                    
                    while (p != NULL) {
                        q->next = new Node;
                        q->next->info = p->info;
                        q->next->prev = q;
                        p = p->next;
                        q = q->next;
                    }
                    
                    q->next = NULL;
                    last = q;
                    length = other.length;
                }
            }
            return *this;
        } // CLOSED overloading operator=

        // deleting item
        bool deleteItem(const T& item) {

            // list is empty
            if (isEmpty()) {
                cout << "List is empty";
                return false;
            }

            // item is in first node
            if (first->info == item) {
                Node* p = first;

                // if we have only 1 node
                if (first == last) {
                    first = last = NULL;
                } 
                // more than one node
                else {
                    first = first->next;
                    first->prev = NULL;
                }

                delete p;
                length--;
                return true;
            }

            // item is in the last node.
            if (last->info == item) {
                Node* p = last;

                last = last->prev;
                last->next = NULL;

                delete p;
                length--;
                return true;
            }

            // item is in the middle
            Node* p = first->next;
            while (p != NULL && p->info != item) {
                p = p->next;
            }
            // checking if item is found
            if (p != NULL) {
                // skipping the node we want to delete
                p->prev->next = p->next;
                p->next->prev = p->prev;

                delete p;
                length--;
                return true;
            }

            return false; // item not found
        } // CLOSED deleteItem()

        // searching for a given item
        bool search(const T& item) const{
            Node* p = first;
            bool found = false;

            while (p != NULL) {
                if (p->info == item) {
                    found = true;
                    break; //very sexy
                }
                p = p->next;
            }

            return found;
        } // CLOSED search()

        void insertFront(const T& item) {
            Node* newNode = new Node(item);

            if (isEmpty()) {
                first = last = newNode;
            } else {

                newNode->next = first;
                first->prev = newNode;
                first = newNode;
                
            }
            length++;
        } // CLOSED insertFront()

        void insertBack(const T& item) {
            Node* newNode = new Node(item);

            if (isEmpty()) {
                first = last = newNode;
            } else {
                
                last->next = newNode;
                newNode->prev = last;
                last = newNode;
                
            }
            length++;
        }

        void Clear() {
            Node* p = first;
            Node* q;         // temp save address of next node

            while (p != NULL) {
                q = p->next;
                delete p;
                p = q;
            }

            first = last = NULL;
            length = 0;
        } // CLOSED Clear()

        void print() {
            Node* p =first;
            if (isEmpty()) {
                cout << "List is empty";
            } else {
                cout << "List contains: ";
                while (p != NULL) {
                    cout << p->info << " " << endl;

                    p = p->next;
                }
            }
        }
};



#endif