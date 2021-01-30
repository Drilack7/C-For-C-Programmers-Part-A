#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    float number, answer;
    for (int i=0; i<20; ++i)
    {
        for (int j=0; j<10; ++j)
        {
            number =1.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/9.0)); //random float number from 0 to 10
            //answer = static_cast<float>(static_cast<int>(number * 10.0)) / 10.0; //round the number to 1 decimal place
            cout << number << "\t";
        }
        cout << endl;
    }
    cout << RAND_MAX;
}
