
//node of binary tree
struct node{

int value;
node *left;
node *right;
node *parent;

//constructors
node(){
value = 0;
left = nullptr;
right = nullptr;
parent = nullptr;
}
node(int val){
value = val;
left = nullptr;
right = nullptr;
parent = nullptr;
}



//methods
node *decide(int val){ //will return nullptr if left or right is nullptr
if(val > this->value){
   return this->right;
}
else{
return this->left;
}
}
~node(){ //recursively deletes children
    if(this->parent != nullptr){
        if(this->parent->left == this){
            this->parent->left = nullptr;
        }
        else{
            this->parent->right = nullptr;
        }
    }
    if(this->left != nullptr){
        delete this->left;
    }
    if(this->right != nullptr){
        delete this->right;
    }

    return;
}

};

//binary tree struct, holds root node
struct tree{
node* root;

//constructors
tree(){
root = nullptr;
}
tree(node* N){
root = N;
}

//methods
//r2, remove
node *FindNode(int val){ //returns nullptr if val is not in tree, possible nullptr dereferance errors, O(logn)
    node *n = this->root;
    node *out = nullptr;
    while(n != nullptr){
        if(n->value == val){
            out = n;
            n = nullptr;
        }
        else{
            n = n->decide(val);
        } 
    }
    return out;
}
void AddNode(int val){
    node *NodeToAdd = new node(val);
    if(this->root == nullptr){
        this->root = NodeToAdd;
        return;
    }
    else{ //root node is now not empty
        node *n = this->root; //iterable node
        while(n != nullptr){ 
            node *check = n->decide(val);
            if(check == nullptr){ //child spot is empty -> ready to add new node
                if(val > n->value){
                    n->right = NodeToAdd;
                    NodeToAdd->parent = n;
                    n = nullptr; //stop loop
                    return;
                }
                else{
                    n->left = NodeToAdd;
                    NodeToAdd->parent = n;
                    n = nullptr;
                    return;
                }
            
            }
            else{ //child spot is not empty so move to next node
                n = check;
            }

        }
    }
return;
    
    return;
}
void r1(node *NodeToDelete){ //will only be called if one or more children is nullptr
    
    if(NodeToDelete->left != nullptr){
        node *left = NodeToDelete->left; //node to deletes only child
        NodeToDelete -> value = left -> value; //swap values
        NodeToDelete->left = left->left; //swap children
        NodeToDelete->right = left->right;
        left->left = nullptr; //get rid of old childs children
        left->right = nullptr;
        delete left; //delete old child
    }
    else if(NodeToDelete->right != nullptr){
        node* right = NodeToDelete->right;
        NodeToDelete -> value = right -> value;
        NodeToDelete -> left = right -> left;
        NodeToDelete -> right = right -> right;
        right->right = nullptr;
        right->left = nullptr;
        delete right; 
    }
    else{
        delete NodeToDelete;
    }
return;
}
void r2(node* NodeToRemove){ //will only be called if node has two children
    tree subtree;
    subtree.root = NodeToRemove->right;
    node* CurrentNode = subtree.root;
    while(CurrentNode->left != nullptr){
        CurrentNode = CurrentNode->decide(CurrentNode->value);//find smallest value in subtree
    }
    NodeToRemove->value = CurrentNode->value; //binary tree succession
    subtree.r1(CurrentNode);
    subtree.root=nullptr; //dont want to delete subtree nodes since they exist in "this" tree 
}
void remove(int val){//global remove just calls r1 or r2 based on simple conditional
    node *NodeToDelete = this->FindNode(val);
    if(NodeToDelete == nullptr){
        return;
    }
    else if(NodeToDelete->left != nullptr and NodeToDelete->right != nullptr){
        this->r2(NodeToDelete);
    }
    else{
        this->r1(NodeToDelete);
    }
}
//destructor
~tree(){
    delete this->root;
}
};




