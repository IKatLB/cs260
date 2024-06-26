#include <iostream>
using std::cout;
using std::endl;




//node of linked list data structure, .next points to next node in list, by default is nullptr
struct node {

int value = 0;
node *next = nullptr;
node *behind = nullptr;

};

// queue struct to keep track of linked nodes
struct queue {

node *tail = nullptr;

};

//takes int and attaches it as a node to the tail of the queue,
void enqueue(queue *Q, node *NewTail){

NewTail->next = Q->tail;
if(Q->tail != nullptr){
Q->tail->behind = NewTail;
}
Q->tail = NewTail;

}

//enqueue test function check expected value of enqueue from local variable set up.
bool TestEnqueue(){

queue TestQueue; //initialize new queue 
node TestNode; //this will be what we try to get to from tail node
node tail; //tail to be enqueued to testqueue
TestNode.value = 1;
tail.value = 2;
TestQueue.tail = &TestNode; //assign initial tail to test queue
enqueue(&TestQueue, &tail); // enqueue tail to testqueue

//check if tail points to test node
if(tail.next == &TestNode and TestNode.behind == &tail){

    return true;

}
else{

    return false;
}
}

//cycles through queue and returns pointer to head node of queue
node *FindHead(queue *Q){
node *N = Q->tail;
if(N == nullptr){
return nullptr; //if the queue is empty head is nullptr
}
while(N->next != nullptr){

N = N->next;

}

return N;
}

//adds two nodes to queue and checks if head is expected memory value
bool TestFindHead(){
queue TestQueue;
node n1;
node n2;
enqueue(&TestQueue, &n1);
enqueue(&TestQueue, &n2);
node *head = FindHead(&TestQueue);
if(head == &n1){
    return true;
}
else{
    return false;
}

}
//calls find head and prints head value
void peek(queue *Q){

node *head = FindHead(Q);
cout << "queue head value = " << head ->value <<endl;

}

//removes head of queue and points new head to nullptr 
void dequeue(queue *Q){

if(Q->tail == nullptr){
return;

}

node *head = FindHead(Q);

if(head->behind == nullptr){
cout <<"head removed, value was: " << Q->tail->value << endl;
Q->tail = nullptr;
return;
}

else{
head->behind->next = nullptr;
cout <<"removed value: " << head->value << endl;

}
}

bool TestDequeue(){

queue TestQueue;
node TestNode;
TestNode.value = 1;
enqueue(&TestQueue, &TestNode); //assumes test enqueue was successful
cout << "following messages are part of test dequeue" << endl;
dequeue(&TestQueue);
cout << "end test messages" << endl;

if(TestQueue.tail == nullptr){

    return true;
}
else{

    return false;
}

}


int main() {


if(!TestEnqueue()){
cout << "Enqueue error" << endl;
}

else if(!TestFindHead()){
cout << "Find Head error" << endl;
}

else if(!TestDequeue()){
cout << "Dequeue error" << endl;
}
else{



}

return 0;

}

