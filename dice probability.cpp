// The following programs computes
// the probability for dice possibilities
//

#include <iostream> //drops .h still available
#include <cstdlib>
#include <ctime>
using namespace std;
const int sides = 6; //replaces many sharp defines
inline int r_sides(){ return (rand() % sides + 1); }

int main(void)
{
    const int n_dice = 2;
    int d1, d2;
    srand(clock()); //initialize seed
    cout << "\nEnter number of trials: ";
    int trials;
    cin >> trials; //compare to scanf
    int* outcomes = new int[n_dice * sides + 1];
    for (int j=0; j<trials; ++j)
        outcomes[(d1 = r_sides()) + (d2 = r_sides())]++;
    cout << "probability\n";
    for (int j=2; j<n_dice*sides+1; ++j)
        cout << "j=" << j << " p= "
        << static_cast<double>(outcomes[j])/trials
        << endl;

}
