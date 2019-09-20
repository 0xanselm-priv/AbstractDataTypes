//
// Created by Robert on 17/09/2019.
//

#include <iostream>
#include <stdio.h>
#include <array>

using namespace std;

class LinkedList {
private:
    typedef struct Element {
        int data;
        Element *next;
    };
    Element *head, *current;

public:
    LinkedList() {
        head = new Element;
        current = head;
        head->data = 69;
        head->next = nullptr;
    }

    void insert(int n) {
        Element *temp = new Element;
        temp->data = n;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = current->next;
        }
    }

    void remove() {
        Element *temp;
        if (current->next->next != nullptr) {
            temp = current->next->next;
            current->next = temp;
        } else {
            current->next = nullptr;
        }
    }

    void movetofront() {
        current = head;
    }

    void movetoend() {
        while (!empty() && !end()) {
            current = current->next;
        }
    }

    void next() {
        if (hasNext()) {
            current = current->next;
        } else {
            cout << "End of Structure" << endl;
        }
    }

    bool hasNext() {
        return current->next != nullptr;
    }

    bool end() {
        return current->next == nullptr;
    }

    bool empty() {
        return head->next == nullptr;
    }

    int read() {
        if (hasNext()) {
            return current->next->data;
        } else {
            return -1;
        }
    }

    void write(int n) {
        if (!end()) {
            current->next->data = n;
        }
    }

    void search(int n) {
        while (!end()) {
            if (current->next->data == n) {
                cout << "Found n. Current " << current->data << endl;
                break;
            }
            current = current->next;
        }
    }

    void displayList() {
        Element *temp;
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        printf("\n");
    }

    void displayCurrent() {
        cout << current->data << endl;
    }

    void concatenateList(LinkedList b) {
        movetoend();
        b.movetofront();
        current->next = b.current->next;
    }

    void sortN2_b() {
        //Sorting with swapping of nodes
        current = head;
        while (current->next->next != nullptr) {
            if (current->next->data > current->next->next->data ) {
                Element *temp = current->next->next;
                current->next->next = current->next;
                current->next = temp;
                current = head;
            } else {
                current = current->next;
            }
        }
    }

    void sortN2_a() {
        //Sorting with swapping of data
        Element *i, *j;
        for (i = head->next; i != nullptr; i = i->next) {
            for (j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    int t = i->data;
                    i->data = j->data;
                    j->data = t;
                }
            }
        }
    }

    void reverse(){
        //Pointer init and setting current to head
        current = head;
        Element *prev = nullptr;
        Element *next = nullptr;
        while (current != nullptr) {
            //Store next
            next = current->next;
            //Reverse current pointer
            current->next = prev;
            //Move pointers one pos ahead
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList a;
    LinkedList b;
    b.insert(99);
    b.insert(98);
    b.insert(97);
    a.insert(50);
    a.insert(9);
    a.insert(7);
    a.insert(6);
    a.insert(8);
    a.displayList();
    a.reverse();
    a.displayList();
    return 0;
}