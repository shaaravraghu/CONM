#include <iostream>
#include <cmath>
using namespace std;

double first_derivative(double x, double y){
	double l, m, n;
	l =  pow(2.718, (-1*y));
	m = sin (x*x);
	n = y*y +y;
	return l*m + n; // enter required expression
}

double second_derivative(double x, double y, double y1){
	double l, m, n, p;
	l =  pow(2.718, (-1*y));
	m = sin(x*x);
	n = cos(x*x);
	p = y1;
	return (l*n*2*x) + (m*l*(-1)*p) + (2*y*p) + p; // enter required expression
}

int main(){
	double n;
	cout<<"enter number of intervals";
	cin>>n;
	double a, b; double y_i; double y1, y2;
	cout<<"enter range";
	cin>>a>>b;
	double h = (b-a)/n;
	double sum = 0.0;
	cout<<"enter value of 'y' at "<<a;
	cin>>y_i;
	double k=a;
	
	for (int i=0; i<n; i=i+1){
		
		k=a+(i*h);
		sum+=y_i;
		y1 = first_derivative(k, y_i);
		sum += h*y1;
		y2 = second_derivative(k, y_i, y1);
		sum += h*h*(0.5)*y2;
		cout<<k<<"\t"<<sum<<"\n";
		y_i = sum;
		sum = 0.0;
		
	}
	
}
