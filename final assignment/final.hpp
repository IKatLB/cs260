#include "edges.hpp"
#include "node.hpp"
//include vector and using std::vector in node.hpp

//define helper functions outside which need to work on vectors in general

//find node
int FindNode(vector<node*> vec, int NameToFind){ //returns -1 if name not in vector

int index = -1;
if(vec.size() == 0){
    return index;
}

for(vector<node*>::iterator i = vec.begin(); i != vec.end(); ++i){
node* n = *i;
if(n->name == NameToFind){
    index = distance(vec.begin(), i);
    return index;
} 

}
return index;
}

//find smallest value
int SmallestValue(vector<int> input){

int index = -1;
int val = -1;

for(int i = 0; i < input.size(); ++i){ //should automatically exit for empty input
    if(input[i] != -1 and input[i] < val){
        val = input[i];
        index = i;
    }
    else if(input[i] != -1 and val == -1){ //need this since no valid value should be < -1 but we need to fill val
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
void AddNode(int name){
if(FindNode(this->nodes, name) != -1){return;} //node already exists

node *NewNode; 
NewNode->name = name;
this->nodes.push_back(NewNode);
}

//add edge
void AddEdge(int SourceName, int EndName, int weight){

int SourceIndex = FindNode(this->nodes,SourceName);
int EndIndex = FindNode(this->nodes,EndName);


//if node is not in graph add node. saves time when constructing tests
if(SourceIndex == -1){
    this->AddNode(SourceName);
    SourceIndex = FindNode(this->nodes,SourceName);
}
if(EndIndex == -1){
    this->AddNode(EndName);
    EndIndex = FindNode(this->nodes,EndName);
}


//need to account for edge already existing
for(int i = 0; i < this->edges.size(); ++i){
if((this->edges[i]->source->name == SourceName or this->edges[i]->source->name == EndName) and (this->edges[i]->end->name == SourceName or this->edges[i]->end->name == EndName)){
return;
}
}

edge* NewEdge;
NewEdge->weight = weight;
NewEdge->source = this->nodes[SourceIndex];
NewEdge->end = this->nodes[EndIndex];
this->nodes[SourceIndex]->neighbors.push_back(NewEdge);
this->nodes[EndIndex]->neighbors.push_back(NewEdge);
this->edges.push_back(NewEdge);

}


//shortest path

//minimum spanning tree

//graph destructor


};


