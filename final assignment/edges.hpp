#ifndef edges_hpp
#define edges_hpp
#include "node.hpp"

struct edge{
int weight;
node* source;
node* end;

edge(){
    weight = 0;
    source = nullptr;
    end = nullptr;
}

edge(int w){
    weight = w;
    source = nullptr;
    end = nullptr;
}

edge(int w, node* s){
    weight = w;
    source = s;
    end = nullptr;
}

edge(int w, node* s, node* e){
    weight = w;
    source = s;
    end = e;
}
};


#endif