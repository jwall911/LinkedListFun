#include <iostream>
#include <random> 
#include "linkedList.h"

/*Data Structures project#2 with linked lists - by Josh Wallace*/

int main(){
    int Wallace[RAND_ARRAY_SIZE]; //an array to store the randomly generated numbers
    std::cout << "\nWelcome to my linked list program Dr. Rad\n";
    outfile << "\nWelcome to my linked list program Dr. Rad\n";
    std::cout << "\nThe list of un-odered random generated numbers to be stored in the array are:\n";
    outfile << "\nThe list of un-odered random generated numbers to be stored in the array are:\n";
    generateRandom(Wallace);
    //build the linked list
    for (int i = 0; i < RAND_ARRAY_SIZE; i++)
    {
        addNode(Wallace[i]);
    }
    std::cout << "\n\nThe unique numbers put into a linked list in descending order:\n";
    outfile << "\n\nThe unique numbers put into a linked list in descending order:\n";
    displayTheLinkedList(head);
    std::cout << "\nThe list of duplicates that were not added to the linked list:\n";
    outfile << "\nThe list of duplicates that were not added to the linked list:\n";
    displayTheArray(Josh, RAND_ARRAY_SIZE, joshIndex);
    std::cout << "\nThe amount of repititions found in duplicates:\n";
    outfile << "\nThe amount of repititions found in duplicates:\n";
    displayDuplicatesInArray(Josh, joshIndex);
    std::cout << "\nThe length of the linked list is: " << findLength(head) << " nodes\n\n";
    outfile << "\nThe length of the linked list is: " << findLength(head) << " nodes\n\n";;
    std::cout << "\nContent has also been written to file LinkedListJW.txt\n";
    outfile << std::endl;
    outfile.close();
    return 0;
}