#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

int main(void)
{
    std::ifstream data_file("elephant_seal_data.txt");
    std::istream_iterator<int> start(data_file), end;
    std::vector<int> data(start, end);

    //so far, connected a variable to a file for input
    //pointed at the start of the file
    //vector constructor reads from the start to the end
    //initializing the vector<int> data

    int sum = 0;
    for (auto it = data.begin(); it != data.end(); ++it)
        sum += *it;
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Average is = " << 1.0*sum/data.size() << std::endl;

    //idiom for iterating over container
    //data.size() is, the number of actual objects held in data
    //but not necessarily its capacity
}
