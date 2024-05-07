#include <iostream>
#include "assignment5.hpp"
#include "test5.hpp"

int main(){

if(!TestSearch()){
    cout << "Find Node error"<<endl;
}

cout << "ran with no errors" << endl;
return 0;

}