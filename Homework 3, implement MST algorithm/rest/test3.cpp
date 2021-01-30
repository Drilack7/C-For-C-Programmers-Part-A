#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int size, **arr;

    ifstream infile;
    infile.open("Sample Test Data.txt");

    if (infile.good())
    {
        infile >> size;

        arr = new int*[size];
        for (int g = 0; g < size; ++g)
        {
            arr[g] = new int[size];
            for (int f = 0; f < size; ++f)
            {
                infile >> arr[g][f];
                cout << arr[g][f] << " ";
            }
            cout << endl;
        }
        delete [] arr;
    }
	return 0;
}
