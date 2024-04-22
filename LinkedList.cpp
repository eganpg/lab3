#include "LinkedList.h"
#include <iostream>
#include <algorithm>

// Default constructor to initialize an empty linked list
LinkedList::LinkedList() : headPtr(nullptr), numItems(0) {}

// Destructor to clean up all dynamically allocated memory
LinkedList::~LinkedList() {
    Node* current = headPtr;
    // Traverse the linked list and delete each node
    while (current) {
        Node* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}

// Copy constructor to create a deep copy of another linked list
LinkedList::LinkedList(const LinkedList& other) : headPtr(nullptr), numItems(0) {
    Node* cur = other.headPtr;
    // Iterate over each node in the source list and add a copy to this list
    while (cur) {
        add(cur->getCategory(), cur->getLine());
        cur = cur->getNext();
    }
}

// Function to add a new node in the correct sorted position within the linked list
void LinkedList::add(const std::string& category, const std::string& line) {
    Node* newNode = new Node(category, line, nullptr);  // Create new node
    if (headPtr == nullptr) {
        // If the list is empty, insert the new node as the head
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
    // Increment the count of items in the list
    ++numItems;
}

// Convert the linked list to a vector of strings for easy display or processing
std::vector<std::string> LinkedList::toVector() const {
    std::vector<std::string> result;
    Node* current = headPtr;
    std::string lastCategory;
    // Traverse the list and add each node's data to the vector
    while (current) {
        if (current->getCategory() != lastCategory) {
            result.push_back(current->getCategory());
            lastCategory = current->getCategory();
        }
        // Add the line indented
        result.push_back("    " + current->getLine());
        current = current->getNext();
    }
    return result;
}

// Return the number of items/nodes in the linked list
int LinkedList::getNumItems() const {
    return numItems;
}

