//Simple STL vector program
#include <iostream>
#include <vector>

int main()
{
    std::vector<int>v(100); //allocate space

    for (int i=0; i<100; ++i) //C idiom
        v[i] = i; //index through like an array
    for (std::vector<int>::iterator p = v.begin(); p != v.end(); ++p) //C++ idiom
        std::cout << *p << "\t";
    std::cout << std::endl;
}
