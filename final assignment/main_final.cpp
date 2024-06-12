#include "tests_final.hpp"
#include<iostream>

using std::cout;
using std::endl;
int main(){

if(!test_FindNode()){
cout << "FindNode error" << endl;
}
else if(!test_SmallestValue()){
    cout << "SmallestValue error" << endl;
}
else if(!test_AddNode()){
    cout << "AddNode error" << endl;
}
else if(!test_AddEdge()){
    cout << "AddEdge error" << endl;
}

else if(!test_ShortestPath()){
    cout << "shortestpath error" << endl;
}
else{cout << "no errors" << endl;}
return EXIT_SUCCESS;
}
