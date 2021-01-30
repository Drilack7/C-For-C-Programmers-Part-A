//Simple STL vector program
//"auto" replaces "vector<int>::iterator" because the compiler
//understands from "v.begin()" how to declare "p".
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>v(100); //allocate space

    for (int i=0; i<100; ++i) //C idiom
        v[i] = i; //index through like an array
    for (auto p = v.begin(); p != v.end(); ++p) //C++ idiom
        cout << *p << "\t";
    cout << endl;
}
