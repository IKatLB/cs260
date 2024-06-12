#ifndef node_hpp
#define node_hpp
#include<vector>


using std::vector;

struct edge;

struct node{

int name;
vector<edge *> neighbors; //needs to be initialized outside of node decleration
vector<node *> SourceNeighborNodes; //this is source of edge which connects to neighbor
vector<node *> EndNeighborNodes; //this is end of edge which connects to neighbor
vector<node *> NeighborNodes;
node(){
    name = 0;
}

void MakeNeighborNodes(){
if(this->neighbors.size() == 0){
    return;
}
for(int i = 0; i != this->neighbors.size(); ++i){
if(this == this->neighbors[i]->source){
    this->SourceNeighborNodes.push_back(this->neighbors[i]->end);
}
else if(this == this->neighbors[i]->end){
    this->EndNeighborNodes.push_back(this->neighbors[i]->source);
}

}//end for loop
this->NeighborNodes = this->SourceNeighborNodes;
this->NeighborNodes.insert(this->NeighborNodes.end(),this->EndNeighborNodes.begin(),this->EndNeighborNodes.begin());

}//end method

};


#endif