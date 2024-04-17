#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
private:
    std::string category;
    std::string line;
    Node* next;

public:
    Node(const std::string& cat = "", const std::string& ln = "", Node* nxt = nullptr);
    ~Node();

    std::string getCategory() const;
    void setCategory(const std::string& cat);

    std::string getLine() const;
    void setLine(const std::string& ln);

    Node* getNext() const;
    void setNext(Node* nxt);
};

#include "Node.cpp"

#endif // NODE_H
