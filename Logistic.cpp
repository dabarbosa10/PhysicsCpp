#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main(){
	const double rmin=2.5;
	const double rmax=4.0;
	const double Ntrans=500;
	const double NSteps=100;
	const double Rsteps=2000;

	int i;
	double r,dr,x0,x1;
	//-------------------------
	dr=(rmax-rmin)/Rsteps;
	ofstream myfile("bif.dat");	
	myfile.precision(17);
	//------Calculate---------
	r=rmin;
	while(r<=rmax){
	x0=0.5;
	for(i=1;i<=Ntrans;i++){
		x1=r*x0*(1.0-x0);		
		x0=x1;
		}
	for(i=1; i<=NSteps;i++){
		x1=r*x0*(1.0-x0);
		myfile<<r << " " <<x1<<endl;
		x0=x1;
		}

	r+=dr;
	}

myfile.close();



}