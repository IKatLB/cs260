#include <iostream>
using std::cout;
using std::endl;


/*
    Create a linked-list that allows:

        an add function that takes a value and inserts it into a given position into the list
        (example: myList.add(someValue, somePosition) )

        a remove function that takes a position and removes the value stored at that position of the list and returns it
        (example: myList.remove(somePosition) )

        a get function that takes a position and returns that value without removing it
        (example: myList.get(somePosition) )

    Be sure to include at least one test function for each piece of functionality that should verify that your code is working!  This should be at least one test per behavior, likely more. 
    You can make these tests in a source file with a main where your tests are either directly in the main or inside their own standalone functions (please do not neglect the importance of testing!)

    Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements
    (or better, include a small screen snip of where it meets the requirement!).

    (Note: we will cover the analysis of some of this in class next week, then we will have you analyze the next ones!)
    Attempt to analyze the complexity of your implementation with line-by-line analysis,



*/

//node of linked list data structure, .next points to next node in list, by default is nullptr
struct node {

int value = 0;
node *next = nullptr;
node *behind = nullptr;

};

//list struct contains lenth and tail pointer, by default is length = 0, and tail pointer is null pointer
struct list {

int length = 0;
node *tail = nullptr;

};

//cycles through list position number of times and returns pointer to node found at position index
node *FindNode(list *L, int position){
node *N = L->tail;
if(N == nullptr or position > L->length){
return nullptr; //if the list is empty or if requested postion is not in list return nullptr
}

for(int NIndex = 1; NIndex < position; ++NIndex){

N = N->next;

}

return N;
}

//adds two nodes to queue and checks if head is expected memory value
bool TestFindNode(){
list TestQueue;
node n1;
node *TestNull = FindNode(&TestQueue,0);
if(TestNull != nullptr){
    return false;


}
TestQueue.length = 1;
TestQueue.tail = &n1;
node *TestNode = FindNode(&TestQueue, 1);

if(TestNode != &n1){
return false;
}

else{

    return true;
}
}


