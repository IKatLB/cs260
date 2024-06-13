#include "node.hpp"
#include "edges.hpp"
#include<iostream>
using std::cout, std::endl;
//include vector and using std::vector in node.hpp

//define helper functions outside which need to work on vectors in general

void node::MakeNeighborNodes(){
if(this->neighbors.size() == 0){
    return;
}
for(int i = 0; i != this->neighbors.size(); ++i){
if(this == this->neighbors[i]->source){
    this->NeighborNodes.push_back(this->neighbors[i]->end);
}
else if(this == this->neighbors[i]->end){
    this->NeighborNodes.push_back(this->neighbors[i]->source);
}

}//end for loop

}//end method
//n

//find node
int FindNode(vector<node*> vec, int NameToFind){ //returns -1 if name not in vector returs -2 if list is empty

int index = -1;
if(vec.size() == 0){
    index = -2;
    return index;
}

for(int i = 0; i != vec.size(); ++i){
node* n = vec[i];
if(n->name == NameToFind){
    index = i;
    return index;
} 

}
return index;
}
//n


int FindEdge(vector<edge*> vec, int Node1, int Node2){// returns -1 if not in vector
    int index = -1;
    for(int i = 0; i != vec.size(); ++i){
        if((vec[i]->source->name == Node1 or vec[i]->source->name == Node2) and (vec[i]->end->name == Node1 or vec[i]->end->name == Node2)){
            index = i;
            return index;
        }
    }
return index;
}
//n



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
if(index == -1){index = 0;}//return first input in the event everything is -1, would happen in dissconnected graph
return index;
}
//n



bool NoCycle(vector<edge*> vec, vector<node*> output, node*start, node* prev){
//populate output with starting node before calling function
//define new neighbor edge vector with edges in vec
vector<edge*> NewNeighbors;
for(int i = 0; i != start->neighbors.size(); ++i){
    edge* EdgeToAdd = start->neighbors[i];
    int found = FindEdge(vec,EdgeToAdd->source->name,EdgeToAdd->end->name);
    bool reverse = (EdgeToAdd->end == start or EdgeToAdd->source == start) and (EdgeToAdd->end == prev or EdgeToAdd->source == prev); 
    if(found == -1 or found == -2 or reverse){
        continue;
    }
    if(EdgeToAdd->source == start){
        //add edges other node to output
        //call this on that node
        int name = EdgeToAdd->end->name;
        int FoundNode = FindNode(output,name);
        if(FoundNode != -1 and FoundNode != -2){
            
            return false;
        }
        output.push_back(EdgeToAdd->end);
        
        if(!NoCycle(vec,output,EdgeToAdd->end,start)){
            
            return false;
        }
    }
    else{
        
        int name = EdgeToAdd->source->name;
        int FoundNode = FindNode(output,name);
        if(FoundNode != -1 and FoundNode != -2){
            
            return false;
            
        }
        output.push_back(EdgeToAdd->source);
        if(!NoCycle(vec,output,EdgeToAdd->source, start)){
            
            return false;
        }
    }


}


//if new neighbors is empty return
//else add new neighbor nodes to output and call Nodes hit on new neighbor nodes
return true;

}
//n*2^n recursion inside for loop


struct graph{
vector<edge*> edges;
vector<node*> nodes;

//methods

//add node  n
void AddNode(int name){
int found = FindNode(this->nodes, name);
if(found != -1 and found != -2 ){return;} //node already exists

node *NewNode = new node; 
NewNode->name = name;
this->nodes.push_back(NewNode);

}

//add edge n
void AddEdge(int SourceName, int EndName, int weight){

int SourceIndex = FindNode(this->nodes,SourceName);
int EndIndex = FindNode(this->nodes,EndName);


//if node is not in graph add node. saves time when constructing tests
if(SourceIndex == -1 or SourceIndex == -2){
    this->AddNode(SourceName);
    SourceIndex = FindNode(this->nodes,SourceName);
}
if(EndIndex == -1 or EndIndex == -2){
    this->AddNode(EndName);
    EndIndex = FindNode(this->nodes,EndName);
}

node* source = this->nodes[SourceIndex];
node* end = this->nodes[EndIndex];

//need to account for edge already existing
for(int i = 0; i != this->edges.size(); ++i){
//if source = (source name or end name) and end = (source name or end name)
if((this->edges[i]->source->name == SourceName or this->edges[i]->source->name == EndName) and (this->edges[i]->end->name == SourceName or this->edges[i]->end->name == EndName)){
return;
}
}

edge *NewEdge = new edge; 
NewEdge->weight = weight;
NewEdge->source = source;
NewEdge->end = end;
this->edges.push_back(NewEdge);
source->neighbors.push_back(NewEdge);
end->neighbors.push_back(NewEdge);


}


//shortest path will use Dijkstra's algorithm  n^2
//disconected end node will result in nonsense output but will still output
vector<int> ShortestPath(int SourceName, int EndName){
int SourceIndex = FindNode(this->nodes,SourceName);
int EndIndex = FindNode(this->nodes, EndName);
node *source = this->nodes[SourceIndex];
vector<node*> unvisited = this->nodes;
//intialize sets
vector<int> distance(unvisited.size(),-1); //will track asociated node by index relation
distance[SourceIndex] = 0;
vector<int> UnvisitiedDistance(unvisited.size(),-1); //will track asociated node by index relation
UnvisitiedDistance[SourceIndex] = 0;
vector<node*> PrevNode(unvisited.size(), nullptr); //will track asociated node by index relation


while(!unvisited.empty()){

int CurrentNodeIndex = SmallestValue(UnvisitiedDistance);
node* CurrentNode = unvisited[CurrentNodeIndex];
CurrentNode->MakeNeighborNodes();

bool UnvisitedNeighbors = false;
//check for unvisited neighbors
for(int i = 0; i != CurrentNode->NeighborNodes.size(); ++i){ //n^2
    int NeighborName = CurrentNode->NeighborNodes[i]->name;
    int NeighborIndex = FindNode(unvisited,NeighborName);
    if(NeighborIndex != -1){UnvisitedNeighbors = true;}
}
if(!UnvisitedNeighbors){
    unvisited.erase(unvisited.begin()+CurrentNodeIndex);
    UnvisitiedDistance.erase(UnvisitiedDistance.begin()+CurrentNodeIndex);
    continue;
}

//iterate through neighbor nodes and update distances
//if distance is updated then make neighbors previous node = current node

for(int i = 0; i != CurrentNode->neighbors.size(); ++i){

int CurrentDistance = distance[CurrentNodeIndex]+CurrentNode->neighbors[i]->weight;

node* NeighborNode;
if(CurrentNode == CurrentNode->neighbors[i]->source){
NeighborNode = CurrentNode->neighbors[i]->end;
}
else{
NeighborNode = CurrentNode->neighbors[i]->source;
}

int NeighborName = NeighborNode->name;
int NeighborIndex = FindNode(this->nodes,NeighborName);

if(distance[NeighborIndex] > CurrentDistance or distance[NeighborIndex] == -1){
distance[NeighborIndex] = CurrentDistance;
PrevNode[NeighborIndex] = CurrentNode;
}

}//end main for loop



unvisited.erase(unvisited.begin()+CurrentNodeIndex);
UnvisitiedDistance.erase(UnvisitiedDistance.begin()+CurrentNodeIndex);



}//end main while loop




vector<int> output(1,EndName);

//we are gaurenteed to have path to end at this point unless graph is disconected
node* previous = PrevNode[EndIndex];

while(previous != nullptr){

output.push_back(previous->name);

int NextIndex = FindNode(this->nodes,previous->name);
previous = PrevNode[NextIndex];
}
return output;

}//end shortest path

//minimum spanning tree   (n^2)*2^n
vector<edge*> MinTree(){ //output will edge pointers that will be checked by find edge function
vector<edge*> TreeEdges;
vector<edge*> DummyEdges = this->edges;
vector<int> values; // values associated with edge index, need so we can call smallest value
for(int i = 0; i != this->edges.size(); ++i){ //n
values.push_back(this->edges[i]->weight);
}

//while loop to select current edge
//while loop to navigate tree until all edges have been touched or if we see the same node twice
while(!values.empty()){ //n^2*2^n

int CurrentEdgeIndex = SmallestValue(values);
edge* CurrentEdge = DummyEdges[CurrentEdgeIndex];
node* OriginalNode = CurrentEdge->source;
node* NewNode = CurrentEdge->end;

//push back current edge to output, navigate output tree
//if node is touched twice pop back output
TreeEdges.push_back(CurrentEdge);

vector<node*> hit{OriginalNode,NewNode};
bool c = NoCycle(TreeEdges,hit,NewNode, OriginalNode);
if(!c){
    TreeEdges.pop_back();
}


//delete index from values
values.erase(values.begin()+CurrentEdgeIndex);
DummyEdges.erase(DummyEdges.begin()+CurrentEdgeIndex);
}//end main while loop

//compile Tree edges to be vector of nodes that form tree.
return TreeEdges;
}//end min tree




//graph destructor
~graph(){
    for(int i = 0; i != this->nodes.size(); ++i){
        delete this->nodes[i];
    }
    for(int i = 0; i != this->edges.size(); ++i){
        delete this->edges[i];
    } 
}

};


