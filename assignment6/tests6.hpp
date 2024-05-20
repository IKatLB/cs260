#include "assignment6.hpp"


bool TestDecide(){
node root;
root.value = 2;
node left;
left.value = 1;
node right;
right.value = 3;
root.left = &left;
root.right = &right;
bool a; //root.decide larger case
a = false;
bool b; //root.decide smaller case
b = false;
bool c; // root.decide equal case
c = false; 
bool d; // root.left.decide empty children case
d = false;
if(root.decide(5) == root.right){
    a = true;
}
if(root.decide(1) == root.left){
    b = true;
}
if(root.decide(2) == root.left){
    c = true;
}
if(root.left->decide(5) == nullptr){
    d = true;
}
root.left = nullptr;
root.right = nullptr;
if(a and b and c and d){
    return true;
}
else{
    return false;
}


}
bool TestFindNode(){
    bool a = false; //not in tree case
    bool b = false; //root value
    bool c = false; //child value
    
    
    tree T;
    T.AddNode(2);
    T.AddNode(1);
    T.AddNode(3);
    node *check = T.FindNode(5);
    if(check == nullptr){
        a = true;
    }
    check = T.FindNode(2);
    if(T.root == check){
        b = true;
    }
    check = T.FindNode(3);
    if(T.root->right == check){
        c = true;
    }
    if(a and b and c){
        return true;
    }
    else{
        return false;
    }
}
bool TestAdd(){
    bool a = false; //empty root case
    bool b = false; //less than root case
    bool c = false; //greater than root case
    bool d = false; //non root case
    tree T;
    
    T.AddNode(2);
    if(T.root->value == 2){
        a = true;
    }
    
    T.AddNode(1);
    if(T.root->left->value == 1){
        b = true;
    }
    T.AddNode(3);
    
    if(T.root->right->value == 3){
        c = true;
    }
    T.AddNode(5);
    if(T.root->right->right->value == 5){
        d = true;
    }
    
    if(a and b and c and d){
        return true;
    }
    else{
        return false;
    }
}
bool Testr1(){
    bool a = false; //no children case
    bool b = false; //one child case
    //two child input test not necessary, will be tested with total remove function
    
    tree T;
    T.AddNode(2);
    T.AddNode(1);
    T.AddNode(3);
    T.r1(T.FindNode(3));
    if(T.root->right == nullptr){
        a = true;
    }
    T.r1(T.FindNode(2));
    if(T.root->value == 1){
        b = true;
    }
    if(a and b){
        return true;
    }
    else{
        return false;
    }

}
bool TestRemove(){
    bool a = true; // not in tree case, just included to keep track
    bool b = false; // one child case, does it call r1?
    bool c = false; // two children case.

    tree T;
    T.AddNode(2);
    T.AddNode(1);
    T.AddNode(3);
    T.remove(5); // passes for not crashing
    T.remove(2);
    if(T.root->value == 3){
        b = true;
    }
    T.remove(3);
    if(T.root->value == 1){
        c = true;
    }
    if(b and c){
        return true;
    }
    else{
        return false;
    }
}

