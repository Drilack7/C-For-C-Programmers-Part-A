// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function

// Include preprocessing files
#include <iostream>
#include <vector>
using namespace std;
const int N=40; //declare constant variable

inline void sum(int& p, int n, vector<int> vec) //declare sum function
{
    p = 0;
    for(int i = 0; i < n; ++i)
        p += vec[i];
}

int main()
{
    int accum = 0; //Declerations
    vector<int> data(N);
    for(int i = 0; i < N; ++i) //Fill the vector with values
        data[i] = i;
    sum(accum, N, data); //Function call
    cout << "sum is " << accum << endl;
    return 0;
}
