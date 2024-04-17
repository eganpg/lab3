#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <vector>

class LinkedList {
private:
    Node* headPtr;
    int numItems;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other);

    void add(const std::string& category, const std::string& line);
    std::vector<std::string> toVector() const;
    int getNumItems() const;
};

#include "LinkedList.cpp"

#endif // LINKEDLIST_H
