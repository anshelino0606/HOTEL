//
// Created by Anhelina Modenko on 17.10.2023.
//

#ifndef ALGOTESTER_UNI_DOUBLELINKEDLIST_HPP
#define ALGOTESTER_UNI_DOUBLELINKEDLIST_HPP

#include <iostream>


template<class T>
class Node {
public:
    Node() : next(nullptr), prev(nullptr) {}

    Node(T data) :
        data(data), next(nullptr), prev(nullptr) {}

    Node* prev;

    T data;

    Node* next;
};

template<typename T>
class DoubleLinkedList {

public:

    // doubly linked list templated
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    // copy constructor
    DoubleLinkedList(const DoubleLinkedList& other) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            this->add(current->data);
            current = current->next;
        }
    }

    // move constructor
    DoubleLinkedList(DoubleLinkedList&& other) {
        this->head = other.head;
        this->tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }

    // push element to the end of the list
//    void push_back(T value) {
//        Node<T>* newNode = new Node<T>(value);
//        if (empty()) {
//            head = tail = newNode;
//        } else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//        size++;
//    }

    void pushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        if (tail != nullptr) {
            tail->next = newNode;
        }
        newNode->next = nullptr;
        newNode->prev = tail;
        tail = newNode;

        size++;
    }


    void popBack() {
        if (empty()) {
            return;
        }
        if (size == 1) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node<T>* temp = tail->prev;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("DoubleLinkedList::back: list is empty");
        }
        return tail->data;
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("DoubleLinkedList::back: list is empty");
        }
        return tail->data;
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    const T& getHead() const {
        return head->data;
    }

    T getTail() const {
        return tail->data;
    }

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }


    void popFront() {
        if (empty()) {
            return;
        }
        if (size == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
        }
        size--;
    }

    T findByKey(T key) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void sort() {
        Node<T>* current = head;
        Node<T>* index = nullptr;
        T temp;
        if (head == nullptr) {
            return;
        } else {
            while (current != nullptr) {
                index = current->next;
                while (index != nullptr) {
                    if (current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }


    Node<T>* head;
protected:
    size_t size;
    Node<T>* tail;

};



#endif //ALGOTESTER_UNI_DOUBLELINKEDLIST_HPP
