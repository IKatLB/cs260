#include <iostream>
#include "assignment_4.hpp"

int main(){

if(!TestFindNode()){
    cout << "Find Node error"<<endl;
}
if(!TestAdd){
    cout <<"Add error" <<endl;
}

if(!TestRemove){
    cout << "remove error" <<endl;
}

cout << "ran with no errors" << endl;
return 0;

}
