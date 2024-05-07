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

int value = 0;
node *next = nullptr;
node *behind = nullptr;

};

//list struct contains lenth and tail pointer, by default is length = 0, and tail pointer is null pointer
struct list {

int length = 0;
node *tail = nullptr;
~list(){
    while(tail != nullptr){
        delete tail;
    }

}

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

//returns postion of a given value, if value is not in list, returns position value should be at, if list is empty returns 1
int search(list *L, int val){
    if(L->length == 0){
        return 1;
    }
int head = L->length;
int tail = 1;
while(tail <= head){
int check = floor((head-tail)/2);
int CheckVal = FindNode(L,check) -> value;
if(val > CheckVal){
tail = CheckVal+1;
}

else if(val < CheckVal){
head = CheckVal-1;
}
else{
    return check;
}
}

return tail;
}


//adds node in L at position pos of value val, will move other values to account for new node
void add(list *L, int pos, int val){

if(pos < 1 or pos > ((L->length)+1) ){
    return;
}

node *newnode;
newnode->value = val;

node *oldnode = FindNode(L, pos);
if(oldnode == nullptr){
    L->tail = newnode;
}
else{
newnode ->behind = oldnode->behind;
newnode ->next = oldnode;

//reassign old values
oldnode ->behind = newnode;
}

++L->length;
}


void remove(list *L, int pos){

node *kill = FindNode(L,pos);

kill->behind->next = kill->next;
kill->next->behind = kill->behind;
L->length -= 1;
return;
}

//insert takes in a list and a value and inserts that value into its sorted position.
void insert(list *L, int val){



    return;
}
