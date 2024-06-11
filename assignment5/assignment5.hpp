
#include <iostream>
#include <cmath>


using std::cout;
using std::endl;
using std::floor;
/*

    Follow along with the in-class exercise on this, do your best to get it working, and turn in what you come up with here!

    Be sure to include at least one test for each function or piece of functionality that should verify that your code is working!  No slacking smile, you should start writing some tests before you write your implementations (just spend a few minutes thinking about the design and then write a few tests using natural language (English is preferred for me to be able to read it smile ))

    Create an array-based list or a linked-list (and a bonus for attempting both) that:

        automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words)

        efficiently searches for elements (likely binary search for the array list, but what about the linked-list?)

    Make a chart to compare the algorithmic complexity (use Big-O notation) of your insert, remove, and search algorithms you used for your structures

    Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).



*/


//node of linked list data structure, .next points to next node in list, by default is nullptr
struct node {

int value;
node *next;
node(){
    value = 0;
    next = nullptr;
}
};

//list struct contains lenth and tail pointer, by default is length = 0, and tail pointer is null pointer
struct list {

int length;
node *tail;

list(){
    length = 0;
    tail = nullptr;
}

//cycles through list position number of times and returns pointer to node found at position index
node *FindNode(int position){
node *N = this->tail;
if(N == nullptr or position > this->length){
return nullptr; //if the list is empty or if requested postion is not in list return nullptr
}

for(int NIndex = 1; NIndex != position; ++NIndex){

N = N->next;

}

return N;
}


void add(int pos, int val){

if(pos < 1 or pos > ((this->length)+1) ){
    return;
}

node* NewNode = new node;

NewNode->value = val;
NewNode ->next = nullptr;
node *oldnode = FindNode(pos);

if(this->tail == nullptr){
this->tail = NewNode;
++this->length;
return;
}

else if(oldnode == this->tail){
this->tail = NewNode;
NewNode->next = oldnode;
++this->length;
return;
}
else if(oldnode == nullptr){//pos must be at end of list +1
oldnode = this->FindNode(pos-1);
oldnode->next = NewNode;
++this->length;
return;
}
else{

NewNode -> next = oldnode->next;
oldnode-> next = NewNode;
++this->length;
return;
}
}

//returns postion of a given value, if value is not in list, returns position value should be at, if list is empty returns 1
int search(int val){
int head = this->length;
int tail = 1;
while(tail < head){
int CheckPos = floor(((head-tail)/2)+1); //float error could be rounding down too far

node *CheckNode = this->FindNode(CheckPos);

int CheckVal = CheckNode -> value;

if(val == CheckVal){
return CheckPos;
}
else if(val < CheckVal){
head = CheckVal-1;
}
else if(val > CheckVal){
tail = CheckVal+1;
}
else{
    return 0;
}
}
return tail;

}

void remove(int pos){
node *behind = this->FindNode(pos-1);
node *Node = this->FindNode(pos);
node *next = this->FindNode(pos+1);
if(Node==nullptr){
    return;
}    
if(behind == nullptr and next == nullptr){
this->tail = nullptr;
delete Node;
return;
}
else if(behind == nullptr){
this->tail = next;
delete Node;
return;
}
else if(next == nullptr){
behind->next = nullptr;
delete Node;    
return;
}

behind->next = next;
delete Node;
return;
}

//insert takes in a list and a value and inserts that value into its sorted position.
void insert(int val){
int pos = this->search(val);
this->add(pos,val);
return;

    
}



~list(){
node* kill = this->tail;
while(kill != nullptr){
node *next = kill->next;
delete kill;
kill = next;
}

}
};




