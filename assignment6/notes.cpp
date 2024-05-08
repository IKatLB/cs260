/*

Implement a binary search tree that includes:

    nodes to store values,

    an add function that adds a new value in the appropriate location based on our ordering rules,
    (I likely used less than or equal to going to the left and greater than values going to the right)

    a remove function that finds and removes a value and then picks an appropriate replacement node,
    (successor is a term often used for this)

    we have at least one tree traversal function (I recommend starting with an in-order traversal!)

    Bonus if you implement the three common traversals (pre-order, post-order, in-order)
    More Bonus if you also include a breadth-first traversal (sometimes called a level-order search)

*/
//would like to use arrays for tree typing

//foo(int &var){stuff} actually edit var object at its memory
 
//negative 1 is invalid input
struct tree{
int size;
int *body;
tree(){         //default constructor
    size = 0;
    int B[1] = {-1}; 
    body = B;
}

void AddElement(int val){


}

};