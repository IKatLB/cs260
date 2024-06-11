#include <iostream>

#include "test5.hpp"

int main(){

if(!TestSearch()){
    cout << "search error"<<endl;
}

else if(!TestAdd()){
    cout << "add error" << endl;
}

if(!TestRemove()){
    cout << "remove error" << endl;
}

else{
cout << "ran with no errors" << endl;
}
return 0;

}