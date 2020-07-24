#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

const double PI=3.14159265;

int main(){

//variables:

double x0,y0,R,x,y,vx,vy,t,t0,tf,dt;
double theta, omega;
string buf;

//initalization
cout<<"# Enter omega:"<<endl;
cin>>omega;
cout<<"#Enter the center of the circle (x0,y0) and the radius R:"<<endl;
cin>>x0>>y0>>R; getline(cin,buf);
cout<<"# Enter t0,tf,dt:"<<endl;
cin>>t0>>tf>>dt; getline(cin,buf);
cout<<"# Omega= "<<omega<<endl;
cout<<"# x0=" <<x0<<" y0="<<y0<<" R="<<R<<endl;
cout<<"# t0="<<t0<<" tf="<<tf<<" dt="<<dt<<endl;  

//------------------------

if(R<=0.0){cerr<<"Illegal value of R"<<endl;exit(1);}
if(omega<=0.0){cerr<<"Illegal value of omega"<<endl;exit(1);}
cout<<"#T= "<<2.0*PI/omega<<endl;

ofstream myfile("circle.txt");
myfile.precision(17);

//.....................
//Computation.....
t=t0;
	while(t<=tf){
	theta=omega*(t-t0);
	x=x0+R*cos(theta);
	y=y0+R*sin(theta);
	vx=-omega*R*sin(theta);
	vy=omega*R*cos(theta);
	myfile<< t <<" "<< x <<" "<<y<< " "<< vx<< " " <<vy<< " "<< endl;
	t=t+dt;


	}



}