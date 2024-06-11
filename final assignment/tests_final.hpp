#include "final.hpp"
#include<iostream>


bool test_FindNode(){
bool a = false; //case 1: empty input vector
bool b = false; //case 2: non empty input vector

vector<node*> test;
if(FindNode(test, 1) == -1){a = true;}
node TestNode;
TestNode.name = 1;
test.push_back(&TestNode);
if(FindNode(test, 1) == 0){b = true;}
if(a and b){return true;}
else{return false;}
}

bool test_SmallestValue(){
bool a = false; //case 1: empty input vector
bool b = false; //case 2: non empty input vector 

vector<int> nums;

if(SmallestValue(nums) == -1){a = true;}
nums = {3,2,1};
if(SmallestValue(nums) == 2){b = true;}

if(a and b){
    return true;
}
else{
    return false;
}

}

bool test_AddNode(){
bool a = false; //empty node list
bool b = false; //non empty node list 
bool c = false; //same value as other node

graph G;
G.AddNode(1);
if(G.nodes[0]->name == 1){
    a = true;
}

G.AddNode(2);
int size = G.nodes.size();
if(G.nodes[1]->name == 2){
    b = true;
}

G.AddNode(1);
if(G.nodes.size() == size){ //size should be same as before
    c = true;
}

if(a and b and c){
    return true;
}
else{
    return false;
}

}

bool test_AddEdge(){
    bool a = false; //nodes dont exist and edge does not exist
    bool b = false; //edge already exists
    //case "a" also accounts for nodes already existing since that case would hit same code
    
    graph G;
    G.AddEdge(1,2,1);
    int size = G.edges.size();
    if(G.edges[0]->source == G.nodes[0] and G.edges[0]->end == G.nodes[1]){
        a = true;
    }
    G.AddEdge(1,2,1); //should do nothing if G.edges.size() is same then pass
    if(G.edges.size() == size){
        b = true;
    }
    if(a and b){
        return true;
    }
    else{
        return false;
    }
}

    








