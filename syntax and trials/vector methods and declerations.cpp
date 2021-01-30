#include <iostream>
#include <vector>
using namespace std;

//Constructors
vector<T> v; //empty sequence
vector<T> v(n); //size n with default constructor T() called for each element
vector<T> v(n, value); //value is  of type T or convertible to T and is value of each element

v.size() //get current size
v.resize(int size) //resize the vector
