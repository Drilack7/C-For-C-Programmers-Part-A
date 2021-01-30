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
    for (auto it : data)
        sum += it; //note that it's not *it as before
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Average is = " << 1.0*sum/data.size() << std::endl;

}
