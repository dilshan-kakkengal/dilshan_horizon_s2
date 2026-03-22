
#include<iostream>
#include<cmath>
using namespace std;
//function to calculate distance
float calcdistance(int x1,int y1,int x2,int y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
//function to calculate duration for the distance
float calctime(int a,int u,int vmax,float totaldis){
	float t1=(vmax-u)/a;//time to travel distance with vmax.
	float dis=u*t1+0.5*a*t1*t1;//distance traveled within the time t1
	if(dis>=totaldis){
//her distance i s greater or equal to the distance between two cordinates
//solving for t from the quadratic eqn 0.5at^2+ut-s=0
		float A=0.5*a;
		float B=u;
		float C=-totaldis;
		float t=(-B+sqrt(B*B-4*A*C))/(2*A);
		return t;
	}
	else{
//when rover didnt reach the next cordinate or it eneters to constatnt velocity
		float remdis=totaldis-dis;//remaining distance 
		float t2=remdis/vmax;//time for remaining distance
		return t1+t2;
	}
}
int main(){
	int p,q,r,s,u,a,vmax;
	float totaldis,time;
	cout<<"enter x1 and y1"<<endl;
	cin>>p>>q;
	cout<<"enter x2 and y2"<<endl;
	cin>>r>>s;
	totaldis=calcdistance(p,q,r,s);
	cout<<"enter the initial velocity"<<endl;
	cin>>u;
	cout<<"enter the acceleration"<<endl;
	cin>>a;
	cout<<"enter the maximum allowed top speed"<<endl;
	cin>>vmax;
	if(a<=0||vmax<=0){//error checking
		cout<<"invalid input! acceleration and maximum speed must be positive"<<endl;
		return 0;
	}
	else{
		time=calctime(a,u,vmax,totaldis);
		cout<<"distance to destination:"<<totaldis<<endl;
		cout<<"time required:"<<time<<"seconds"<<endl;
		return 0;
	}
}

