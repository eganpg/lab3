#include "Node.h"

// Constructor for Node class. Initializes a Node object with specified category, line, and next node pointer.
Node::Node(const std::string& cat, const std::string& ln, Node* nxt)
    : category(cat), line(ln), next(nxt) {
}

// Destructor for the Node class.
Node::~Node() {
    // Normally you would handle dynamic memory here, but since `next` is handled by LinkedList, we don't delete here.
}

// Accessor method for getting the category of the Node.
std::string Node::getCategory() const {
    return category;
}

// Mutator method for setting the category of the Node.
void Node::setCategory(const std::string& cat) {
    category = cat;
}

// Accessor method for getting the line of the Node.
std::string Node::getLine() const {
    return line;
}

// Mutator method for setting the line of the Node.
void Node::setLine(const std::string& ln) {
    line = ln;
}

// Accessor method for getting the next Node in the list.
Node* Node::getNext() const {
    return next;
}

// Mutator method for setting the next Node in the list.
void Node::setNext(Node* nxt) {
    next = nxt;
}
