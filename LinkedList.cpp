#include "LinkedList.h"
#include <iostream>
#include <algorithm>

LinkedList::LinkedList() : headPtr(nullptr), numItems(0) {}

LinkedList::~LinkedList() {
    Node* current = headPtr;
    while (current) {
        Node* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}

LinkedList::LinkedList(const LinkedList& other) : headPtr(nullptr), numItems(0) {
    Node* cur = other.headPtr;
    while (cur) {
        add(cur->getCategory(), cur->getLine());
        cur = cur->getNext();
    }
}

void LinkedList::add(const std::string& category, const std::string& line) {
    Node* newNode = new Node(category, line, nullptr);  // Create new node
    if (headPtr == nullptr) {
        // First insertion when the list is empty
        headPtr = newNode;
    } else {
        Node* current = headPtr;
        Node* prev = nullptr;

        // Find the correct position for the new node
        while (current != nullptr && (current->getCategory() != category || (current->getCategory() == category && current->getLine() < line))) {
            prev = current;
            current = current->getNext();
        }

        // Insert the new node into the list
        newNode->setNext(current);
        if (prev == nullptr) {
            headPtr = newNode;
        } else {
            prev->setNext(newNode);
        }
    }

    ++numItems;
}

std::vector<std::string> LinkedList::toVector() const {
    std::vector<std::string> result;
    Node* current = headPtr;
    std::string lastCategory;
    while (current) {
        if (current->getCategory() != lastCategory) {
            result.push_back(current->getCategory());
            lastCategory = current->getCategory();
        }
        result.push_back("    " + current->getLine());
        current = current->getNext();
    }
    return result;
}

int LinkedList::getNumItems() const {
    return numItems;
}

