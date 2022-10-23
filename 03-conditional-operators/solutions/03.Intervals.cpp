#include <iostream>

int main(){
    int a, b, c, d, e; 
    std::cin >> a, b, c, d, e;
    bool isInA = (e >= a) && (e <= b);
    bool isInB = (e >= c) && (e <= d); 
    
    bool isInUnion = isInA || isInB; 
    bool isInIntersect = isInA && isInB; 
    bool isInDiff = isInA && !isInB; 
    bool onlyInOne = isInUnion && !isInIntersect; 

    std::cout << std::boolalpha << isInUnion << " " << isInIntersect  << " "<< isInDiff  << " "<< onlyInOne; 
}