#include <iostream>
#include <fstream>
#include "LinkedList.h"

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file!\n";
        return 1;
    }

    LinkedList list;
    std::string category, line;
    while (getline(file, category) && getline(file, line)) {
        list.add(category, line);
    }

    file.close();

    std::vector<std::string> contents = list.toVector();
    for (const auto& str : contents) {
        std::cout << str << std::endl;
    }

    return 0;
}
