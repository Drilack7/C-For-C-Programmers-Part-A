#include <iostream>
using namespace std;

int main()
{
    int* i = new int(9); //i is a pointer to 9
    cout << *i << endl;
    delete i;

    int n=5;
    int* data = new int[n]; //data is a pointer to the first element (data[0]) and data[0] is the 1st element value, etc
    //fill the array with values
    for (int i=0; i<n; ++i)
        data[i] = i+1; //note that we use data[i]
    //print the array elements
    for (int i = 0; i < n; i++)
            cout << data[i] << " ";
    //print the address of the first element
    cout << endl << data << endl;
    delete []data;

    return 0;
}
