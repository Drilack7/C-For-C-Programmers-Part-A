class point {
	private:
	double x,y;
	
	public:
	point(double u):x(u),y(0.0){}
}

int main() {
	point s;
	double d=3.5;
	
	//Convert double to point (both are equivalent):
	s = d; //implicit conversion
	s = static_cast<point>(d); //explicit conversion
	
	//In order to convert a point to double, we have to create an operator method:
	point::operator double()
	{ return sqrt(x*x + y*y);}
	
	d = s; //this would now work
	//But it's not always a good idea.
	
	return 0;
}

//also this turns off the ability for implicit conversion:
explicit point::point(double d) {  //or explicit point(double d) if we're inside the class
	//code 
}; 

