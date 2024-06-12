#ifndef node_hpp
#define node_hpp
#include<vector>


using std::vector;

struct edge;

struct node{

int name;
vector<edge *> neighbors; //needs to be initialized outside of node decleration
vector<node *> NeighborNodes;
node(){
    name = 0;
}

void MakeNeighborNodes();

};


#endif