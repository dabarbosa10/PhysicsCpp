#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;
const double PI=3.14169265;

int main(){

double x0,y0,R,x,y,vx,vy,t,t0,tf,dt;
double o1,o2,T1,T2;
string buf;
//--------------------------------------------
cout<<"# Enter omega1 and omega2: "<<endl;
cin>>o1>>o2; getline(cin,buf);
cout<<"# Enter tf, df: "<<endl;
cin>>tf>>dt; getline(cin,buf);
cout<<"o1= "<<o1<<" o2= "<<o2<<endl; 
cout<<"to= "<< 0.0<<" tf= "<< tf <<"dt= "<<dt<<endl;
//............................................
if(o1<=0.0){cerr<<"Illegal value of o1"<<endl; exit(1);}
if(o2<=0.0){cerr<<"Illegal value of o2"<<endl; exit(1);}
//----------------------------------------------
T1=2.0*PI/o1;
T2=2.0*PI/o2;

cout<<"# T1= "<<T1<<" T2= "<<T2<<endl;
ofstream myfile("Lissajous.dat");
myfile.precision(17);

//-------------------------------------------- 

t=t0;
	while(t<=tf){
		x= cos(o1*t);
		y=sin(o2*t);
		vx=-o1*sin(o1*t);
		vy=o2*cos(02*t);	
		myfile<< t<< " " << x<< " "<<y<<" "<<vx<< " "<< vy<< " "<<endl;
		t=t+dt;
	}

}