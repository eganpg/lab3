// Program Description:
// This program processes text records
// The program reads from a file entered by the user
// The records are stored in a linked list where each node is a single record
// The nodes are stored in alphabetic order, the categories are maintained in their order in the file
// Usage:
// The program is designed to be used with the provided files. If the user enters a file not included it will not work
// If the user would like to add additional files they may; however, they must be stored at the root level


#include <iostream>
#include <fstream>
#include "LinkedList.h"

int main() {
    std::string filename;
    // Prompt user to enter the filename
    std::cout << "Enter filename: ";
    // Read the filename input from the user
    std::getline(std::cin, filename);
    // Open the file with the given filename
    std::ifstream file(filename);
    // Check if the file was successfully opened
    if (!file.is_open()) {
        // If file cannot be opened present error
        std::cerr << "Could not open file!\n";
        // Exit program with error code 1 indicating failure
        return 1;
    }

    // Create an instance of LinkedList to store the data from the file
    LinkedList list;

    std::string category, line;
    // Read the file two lines at a time, assuming each pair of lines represents a category and a line
    while (getline(file, category) && getline(file, line)) {
        // Add each category and line pair to the linked list
        list.add(category, line);
    }

    // Close the file once all data has been read
    file.close();

    // Convert the linked list data into a vector of strings
    std::vector<std::string> contents = list.toVector();
    // Iterate through each string in the vector
    for (const auto& str : contents) {
        // Print each string, which includes categories and their associated lines
        std::cout << str << std::endl;
    }

    return 0;
}
