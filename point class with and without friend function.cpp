#include <iostream>
using namespace std;

class point
{
public:
    point(double x=0.0, double y=0.0):x(x),y(y){}
    double getx() {return x;}
    void setx(double v) {x = v;}
    point operator+ (point& p2)
{
    this->x = x;
    this->y = y;
    point sum = {x + p2.x, y + p2.y};
    return sum;
}
    friend ostream& operator<< (ostream& out, const point& p);
private:
    double x, y;

};



ostream& operator<< (ostream& out, const point& p)
{
    out << "(" << p.x << ", " << p.y << ")" ;
    return out;
}


int main()
{
    point a(2.0, 2.0);
    point b(2.0, 2.0);
    cout << "\n\na = " << a << ", b = " << b <<endl;
    cout << "sum = " << a + b << endl;
}
