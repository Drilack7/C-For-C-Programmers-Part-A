#include <iostream>
using namespace std;

class point
{
public:
    point(double x=0.0, double y=0.0):x(x),y(y){}
    double getx() {return x;}
    void setx(double v) {x = v;}
    double x, y;

};

point operator+ (point& p1, point& p2)
{
    point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
}

ostream& operator<< (ostream& out, const point& p)
{
    out << "(" << p.x << ", " << p.y << ")" ;
    return out;
}


int main()
{
    point a, b, c;
    cout << "Please input initial points:" << endl;
    cout << "a = ";
    cin >> a.x >> a.y;
    cout << "\nb = ";
    cin >> b.x >> b.y;
    cout << "\n\na = " << a << ", b = " << b <<endl;
    cout << "sum = " << a + b << endl;
}
