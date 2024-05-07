#include <iostream>
#include "assignment5.hpp"
#include "test5.hpp"

int main(){

if(!TestSearch()){
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