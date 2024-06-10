#include "edges.hpp"
#include "node.hpp"
//include vector and using std::vector in node.hpp

//define helper functions outside which need to work on vectors in general

//find node
int FindNode(vector<node> vec, int NameToFind){ //returns -1 if name not in vector

int index = -1;
if(vec.size() == 0){
    return index;
}

for(int i = 0; i < vec.size(); ++i){
if(vec[i].name == NameToFind){
    index = i;
    return index;
} 

}
return index;
}

//find smallest value
int SmallestValue(vector<int> input){

int index = 0;
int val = input[0];

for(int i = 1; i < input.size(); ++i){ //should automatically exit for empty input
    if(input[i] != -1 && input[i] < val){
        val = input[i];
        index = i;
    }
    else if(input[i] != -1 && val == -1){ //need this since no valid value should be < -1 but we need to fill val
        val = input[i];
        index = i;
    }
    
}

return index;
}


struct graph{
vector<edge*> edges;
vector<node*> nodes;

//methods

//add node

//add edge

//shortest path

//minimum spanning tree



};


