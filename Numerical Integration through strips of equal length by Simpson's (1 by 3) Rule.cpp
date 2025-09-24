#include <iostream>
#include <cmath>
using namespace std;

double function(double x){
	// enter your respective function and return 
	// return pow( exp(1.0) , -(x*x));
	// return 1/pow(2.718, x*x);
	// return 1/(1 + pow(2.718, x));
	return 1/(1+(pow(2.718, (-1*x*x))));
}

int main(){
	double a, b; 
	cout<<"enter limits: ";
	cin>>a>>b;
	double n; 
	cout<<"enter no. of slits: ";
	cin>>n;
	double h = (b-a)/n;// ensure that values in expression are double orelse decimal value won't be printed
	cout<<"h: "<<h<<"\n";
	double value = 0.0;
	double total;
	double k;
	for (int i=1; i<n; i++){
		k =a+(i*h);
		if (i%2 == 0){ // 
			value += 2*function(k);
		} else {
			value += 4*function(k);
		}
		
	}
	value += (function(a) + function(b));
	total = (h/3)*(value);
	cout<<total<<"\n";
	return 0;
}
