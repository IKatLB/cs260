#include <iostream>
#include "assignment5.hpp"

using std::cout;
using std::endl;


//test function for add function, initialize list, adds normally to a list and checks to make sure value is expected. If I knew dual typed functions
//I could test for invalid cases
bool TestAdd(){

list L;
node n1;
add(&L,1,2,&n1);
node *n = FindNode(&L,1);
int output = n -> value;
if(output != 2 or L.length != 1){

    return false;
}
else{
    return true;
}
}



//assumes add works correctly, add item and remove it, make sure list is empty
bool TestRemove(){

list L;
node n1;
add(&L,1,2,&n1);
remove(&L,1);
if(L.tail != nullptr or L.length != 0){
    return false;
}

return true;
}



//creates list with and checks if position got is expected for value in and not in list
bool TestSearch(){
list L;
node n1;
L.length = 0;
L.tail = nullptr;
add(&L,1,1,&n1);
add(&L,2,2,&n1);
add(&L,3,4,&n1);
int ExpectPos1 = search(&L,1);
int ExpectPos2 = search(&L,3);
if(ExpectPos1 == 1 or ExpectPos2 == 3){
    return true;
}

else{
    return false;
}

}