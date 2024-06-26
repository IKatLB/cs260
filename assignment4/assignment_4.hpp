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

//checks empty list for nullpointer adds two nodes to list and then checks if find node returns expected values for either
//need two nodes since one is tail and the other is pointed at by a node, accounts for all possible positions of found node
bool TestFindNode(){
list TestQueue;
node n1;
node n2;
node *TestNull = FindNode(&TestQueue,0);
if(TestNull != nullptr){ //checks expected result for empty list
    return false;
}

TestQueue.length = 1;
TestQueue.tail = &n1;
node *TestNode = FindNode(&TestQueue, 1);

if(TestNode != &n1){
return false;
}
TestQueue.length = 2;
TestQueue.tail = &n2;
n2.next = &n1;

TestNode = FindNode(&TestQueue, 2);
if(TestNode != &n1){
return false;

}
else {

    return true;
}



}

//returns value of node at selected position, simply refers to value at node found using find node function, refer to TestFindNode for test function
int get(list *L, int pos){

node *FoundNode = FindNode(L, pos);
int value = FoundNode -> value;
return value;
}


//adds node in L at position pos of value val, will move other values to account for new node
void add(list *L, int pos, int val){

if(pos < 1 or pos > ((L->length)+1) ){

    cout << "invalid postion" << endl;
    return;
}
node *newnode;
node *oldnode = FindNode(L, pos);

//new values
newnode ->behind = oldnode->behind;
newnode ->next = oldnode;

//reassign old values
oldnode ->behind = newnode;

++L->length;

}

//test function for add function, initialize list, adds normally to a list and checks to make sure value is expected. If I knew dual typed functions
//I could test for invalid cases
bool TestAdd(){

list L;

add(&L,1,2);
int output = get(&L,1);
if(output != 2 or L.length != 1){

    return false;
}
else{
    return true;
}
}


void remove(list *L, int pos){

node *kill = FindNode(L,pos);

kill->behind->next = kill->next;
kill->next->behind = kill->behind;
L->length -= 1;

}

//assumes add works correctly, add item and remove it, make sure list is empty
bool TestRemove(){

list L;
add(&L,1,2);
remove(&L,1);
if(L.tail != nullptr or L.length != 0){
    return false;
}

return true;



}



