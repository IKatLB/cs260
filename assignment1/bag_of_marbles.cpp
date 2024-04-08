#include <iostream>

int main() {
    int bag_current;
    char cont;
    bool x;
    bag_current = 0;
    x = true;
    std::cout << "only input positive and negative numbers or bad things will happen" << std::endl << 
    "we will not be held responsible for making negative values mean something" << std::endl;

    while(x) 
    {
    std::cout << "you have " << bag_current << " marbles in your bag" << std::endl << "how many do you put in the bag, or how many fall out?" << std::endl;
    int input;
    std::cin >> input;

    bag_current += input;
    }
    return 0;
    
}