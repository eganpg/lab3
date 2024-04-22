#ifndef NODE_H
#define NODE_H

#include <string>

// Definition of the Node class
class Node {
private:
    // Private string to store the category of the node.
    std::string category;
    // Private string to store the line associated with this node.
    std::string line;
     // Pointer to the next Node object in the linked list.
    Node* next;

public:
    // Constructor with default values, allowing for creation of a node with specified or default values.
    Node(const std::string& cat = "", const std::string& ln = "", Node* nxt = nullptr);
    // Destructor, responsible for cleaning up resources if needed.
    ~Node();

    // Accessor method to get the category of the node.
    std::string getCategory() const;
    // Mutator method to set the category of the node.
    void setCategory(const std::string& cat);

    // Accessor method to get the line stored in the node.
    std::string getLine() const;
    // Mutator method to set the line stored in the node.
    void setLine(const std::string& ln);

    // Accessor method to get the pointer to the next node in the list.
    Node* getNext() const;
    // Mutator method to set the pointer to the next node in the list.
    void setNext(Node* nxt);
};

#include "Node.cpp"

#endif // NODE_H
