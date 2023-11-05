
#ifndef SINGLE_LINKED_LIST_HPP
#define SINGLE_LINKED_LIST_HPP

#include <iostream>
#include <fstream>
#include <string>


template<typename T>
class SingleLinkedList {
public:

    template<class M>
    class Node {
    private:
        Node() : next(nullptr) {}

        Node(M data) :
                data(data), next(nullptr) {}

        M data;

        Node* next;

    };

    SingleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Constructor that reads data from a text file and populates the list.
    SingleLinkedList(const std::string& filename) : head(nullptr), tail(nullptr) {
        std::ifstream file(filename);
        if (file.is_open()) {
            double value;
            while (file >> value) {
                pushBack(value);
            }
            file.close();
        }
    }

    ~SingleLinkedList() {
        clear();
    }

    void pushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront() {
        if (!empty()) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void popBack() {
        if (!empty()) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node<T>* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
        }
    }

    void clear() {
        while (!empty()) {
            popFront();
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void sortAsc() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* min = current;
            Node<T>* temp = current->next;
            while (temp != nullptr) {
                if (temp->data < min->data) {
                    min = temp;
                }
                temp = temp->next;
            }
            T tempData = current->data;
            current->data = min->data;
            min->data = tempData;
            current = current->next;
        }
    }

    int countOccurrence(T value) {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    SingleLinkedList mergeAscend(SingleLinkedList& other) {
        SingleLinkedList<T> result;
        Node<T>* current1 = head;
        Node<T>* current2 = other.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data < current2->data) {
                result.pushBack(current1->data);
                current1 = current1->next;
            } else {
                result.pushBack(current2->data);
                current2 = current2->next;
            }
        }

        while (current1 != nullptr) {
            result.pushBack(current1->data);
            current1 = current1->next;
        }

        while (current2 != nullptr) {
            result.pushBack(current2->data);
            current2 = current2->next;
        }

        return result;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};






#endif