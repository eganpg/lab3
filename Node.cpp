#include "Node.h"

Node::Node(const std::string& cat, const std::string& ln, Node* nxt)
    : category(cat), line(ln), next(nxt) {
}

Node::~Node() {
    // Normally you would handle dynamic memory here, but since `next` is handled by LinkedList, we don't delete here.
}

std::string Node::getCategory() const {
    return category;
}

void Node::setCategory(const std::string& cat) {
    category = cat;
}

std::string Node::getLine() const {
    return line;
}

void Node::setLine(const std::string& ln) {
    line = ln;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* nxt) {
    next = nxt;
}
