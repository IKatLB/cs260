#ifndef node_hpp
#define node_hpp
#include "edges.hpp"
#include<vector>

using std::vector;

struct node{

int name;
vector<edge *> neighbors; //needs to be initialized outside of node decleration

node(){
    name = 0;
}

};


#endif