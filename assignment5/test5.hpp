#include <iostream>
#include "assignment5.hpp"

using std::cout;
using std::endl;


//test function for add function, initialize list, adds normally to a list and checks to make sure value is expected. If I knew dual typed functions
//I could test for invalid cases
bool TestAdd(){

list L;

add(&L,1,2);
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
add(&L,1,2);
remove(&L,1);
if(L.tail != nullptr or L.length != 0){
    return false;
}

return true;
}



//creates list with and checks if position got is expected for value in and not in list
bool TestSearch(){
list L;
add(&L,1,1);
add(&L,2,2);
add(&L,3,3);
add(&L,4,5); //L should now be 1->2->3->5
int ExpectPos1 = search(&L,2); //expect 2
int ExpectPos2 = search(&L,4); //expect 4
L.~list();
if(ExpectPos1 != 2 or ExpectPos2 != 4){
    return false;
}

else{
    return false;
}

}