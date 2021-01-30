#include <iostream>
using std::cout;
using std::endl;


int main()
{
    int m=5, n=10;
    double x=5.3, y=10.6;
    cout << "inputs: " << m << ", " << n << endl;
    std::swap(m,n);
    cout << "outputs: " << m << ", " << n << endl;

    cout << "double inputs: " << x << ", " << y << endl;
    std::swap(x,y);
    cout << "double outputs: " << x << ", " << y << endl;
}
