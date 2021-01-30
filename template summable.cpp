#include <iostream>
using namespace std;

template <class summable>
summable sum(const summable data[], int size, summable s=0)
{
    for(int i=0; i<size; ++i)
        s += data[i];
    return s;
}

int main()
{
    int pinakas[] = {1,2,3,4,5};
    int megethos=5, athroisma=0;
    cout << "Einai " << sum(pinakas, megethos, athroisma) << endl;
}
