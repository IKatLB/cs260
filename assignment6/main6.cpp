#include "tests6.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    
    if(!TestDecide()){
        cout<< "Decide method error" << endl;
    }
    else if(!TestAdd()){
        cout<< "Add method error" << endl;
    }
    else if(!TestFindNode()){
        cout<< "FindNode error" <<endl;
    }
    else if(!Testr1()){
        cout<<"r1 error" << endl;
    }
    else if(!TestRemove()){
        cout<<"remove error" << endl;
    }
    else{
        cout << "no errors" <<endl;
    }
    return 0;
}