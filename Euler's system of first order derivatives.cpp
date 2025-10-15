#include <iostream>
#include <cmath>
using namespace std;

double dy_dx(double x, double y, double z){
	double l, m, n;
	l =  x*x;
	m =  sin(y);
	n = cos(z);
	return l + m + n;// enter required expression
}

double dz_dx(double x, double y, double z){
	double l, m, n, p;
	l =  pow(2.718, (-1*x*x));
	m =  sin(y*y);
	n =  pow(2.718, (-1*z*z));
	return l + m + n; // enter required expression
}

int main(){
	
	double n;
	cout<<"enter number of intervals";
	cin>>n;
	double x0, xn;
	cout<<"enter range";
	cin>>x0>>xn;
	double alpha, beta; 
	cout<<"enter 'y' and 'z' values at "<<x0;
	cin>>alpha>>beta;
	double h = (xn - x0)/n;
	double xi = x0, yi = alpha, zi = beta;
	double xik, yik, zik;
	
	
	for (int i=0; i<n; i=i+1){
		
		yik = yi + h*dy_dx(xi, yi, zi);
		cout<<yik<<"\t";
		zik = zi + h*dz_dx(xi, yi, zi);
		cout<<zik<<"\n";
		xik = xi +h;
		xi = xik;
		yi = yik;
		zi = zik;
		
	}
	
}
