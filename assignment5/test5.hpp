
#include "assignment5.hpp"

//test function for add function, initialize list, adds normally to a list and checks to make sure value is expected. If I knew dual typed functions
//I could test for invalid cases
bool TestAdd(){

list L;

L.add(1,2);
node *n = L.FindNode(1);
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
L.add(1,2);
L.remove(1);
if(L.tail != nullptr or L.length != 0){
    return false;
}

return true;
}



//creates list with and checks if position got is expected for value in and not in list
bool TestSearch(){
list L;
L.length = 0;
L.tail = nullptr;
L.add(1,1);
L.add(2,2);
L.add(3,4);
int ExpectPos1 = L.search(1);
int ExpectPos2 = L.search(3);
if(ExpectPos1 == 1 and ExpectPos2 == 3){
    
    return true;
}

else{
    return false;
}

}


