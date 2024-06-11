#include "final.hpp"

bool test_FindNode(){
bool a = false; //case 1: empty input vector
bool b = false; //case 2: non empty input vector

vector<node*> test;
if(FindNode(test, 1) == -1){a = true;}
node TestNode;
TestNode.name = 1;
test.push_back(&TestNode);
if(FindNode(test, 1) == 0){b = true;}
if(a and b){return true;}
else{return false;}
}

bool test_SmallestValue(){
bool a = false; //case 1: empty input vector
bool b = false; //case 2: non empty input vector 

vector<int> nums;

if(SmallestValue(nums) == -1){a = true;}
nums = {3,2,1};
if(SmallestValue(nums) == 2){b = true;}

if(a and b){
    return true;
}
else{
    return false;
}

}

bool test_AddNode(){
bool a = false; //empty node list
bool b = false; //same value as other node
bool c = false; //non empty node list



}


    








