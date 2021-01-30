// This programs showcases operators "++"
// and "<<" overloading

#include <iostream>

typedef enum days{MON, TUE, WED, THU, FRI, SAT, SUN} days;

inline days operator++ (days d)
{
    return static_cast<days>((static_cast<int>(d)+1)%7);
}

std::ostream& operator<< (std::ostream& out, const days& d)
{
    switch(d)
    {
        case MON: out << "MON"; break;
        case TUE: out << "TUE"; break;
        case WED: out << "WED"; break;
        case THU: out << "THU"; break;
        case FRI: out << "FRI"; break;
        case SAT: out << "SAT"; break;
        case SUN: out << "SUN"; break;
    }
    return out;
}

int main()
{
    days d = MON, e;
    e = ++d;
    std::cout << d << "\t" << e << std::endl;
}
