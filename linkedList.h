#include <iostream>
#include <algorithm>
#include <fstream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
const int RAND_ARRAY_SIZE = 49; //size for all arrays
int Josh[RAND_ARRAY_SIZE];//an array to store the duplicate numbers
int joshIndex = 0; //index for duplicate array
std::ofstream outfile ("LinkedListJW.txt");
//struct used for node of linked list
 struct Listnode {
       int value; //data part of node
       Listnode *next; //pointer to node
    }; 
Listnode* head; //later on put in header (all others so just main is here)


//finds the length of a Listnode linked list
int findLength(Listnode* head)
{
    int counter = 0;
    Listnode* current = head; 
    while (current != NULL){
        counter++;
        current = current->next;
    }
    return counter;
}

//generates a random list into array and prints it
void generateRandom(int randList[])
{
    srand(time(NULL));
    for(int r = 0; r < RAND_ARRAY_SIZE; r++)
    {
    randList[r]=std::rand()%100; // keep the random number less than 100
    printf("%d\t", randList[r]);
    outfile << randList[r] << "\t";
    }
}
//sorts Listnodes in a linked list
void sortByDescending(Listnode* curr, Listnode* prev)
{
    int temp;
    if (curr->value >= prev->value)
             {
            temp = curr->value;
            curr->value = prev->value;
            prev->value = temp;
          }
}

//adds node to the linked list, removes duplicates(by adding them to a seperate array) and sorts each node by descending order of its data.
void addNode(int num)
{
   // int temp; //variable to store a value temporarily for sorting
    Listnode* current;
    Listnode* previous;
    //allocate memory to the node
    current = new Listnode;
    //store the integer in myNode
    current->value = num;
    //set pointer part of node to null
    current->next = NULL;
    //we created a node and stored a value in it and pointer in it but it is not part of the linked list yet
    //if the list is empty- head is not pointing to any node
    if (!head) //list is empty or in other word head is pointing to NULL
    head = current;
         //to advance the point of the list (traverse the list)
    else {
        previous = head;
        while (previous->next) //while we are not at the end of the list
        {
            //sort the linked list by descending 
            sortByDescending(current, previous);
          //checking for duplicate, if not duplicate then add to linked list
            if (current->value != previous->value){
            previous = previous->next;
            }
          else 
          {//duplicate found, add it to the array of duplicates - tracking index to prevent printing empty indices later on
            Josh[joshIndex] = previous->value;
            joshIndex++;
          return;
          } //return is used to prevent adding of duplicate
        }
        //to add to the end of the list
        //need to link the node to the next 
         previous->next = current;
      }
}

//prints each node's value in the linked list
void displayTheLinkedList(Listnode* current)
{
    Listnode *nodePtr; //use a pointer to traverse the list
    current = head; //start at the start of the list: which is marked by the head variable
    while (current) //as long as nodePtr is not NULL or not reaching the end of the list
    {
        //print out the integer value that nodePtr is pointing to
        printf("%d\t", current->value);
        outfile << current->value << "\t";
        current = current->next;//advance the pointer to point to the next node
    }
    outfile << std::endl;
    std::cout << std::endl;
}

//function used to compare two integers and return comparison result (used in sort in the displayTheArray function)
int descend(int const &i, int const &j) {
    return i > j;
}

//sort & prints each element in a array, uses variable stop to prevent printing empty indices
void displayTheArray(int array[], int size, int stop)
{
    
    std::sort(array, array+joshIndex, descend);
    for (int i = 0; i < size;i++)
    {
        std::cout << array[i] << "\t";
        outfile << array[i] << "\t";
        if (i == stop - 1)
        { //do not print the empty contents of the array since the amount of duplicates is unknown
        std::cout << std::endl;
        outfile << std::endl;
        break;
        }
    }
}

//prints amount of duplicate repitions found in array, variable stop used to prevent printing additional indices 
void displayDuplicatesInArray(int array[], int stop){
    int counter;
    int temp;
//compares index i to index j, if match then increment count
    for (int i = 0; i < stop; i++)
    { //subtracting 1 due to array starting at index 0
        counter = 0;
        for (int j = 0; j < stop; j++)
    {
        //if the same number is next, do not print repititions again
        if (array[i] == array[i-1])
        i++;
        if (array[i] == array[j])
        {//if values match, repitition has been found
            counter++;
        }
     }
        outfile << array[i] << " was repeated " << counter << " number of time(s)\n";
        std::cout << array[i] << " was repeated " << counter << " number of time(s)\n";
    }
}
#endif