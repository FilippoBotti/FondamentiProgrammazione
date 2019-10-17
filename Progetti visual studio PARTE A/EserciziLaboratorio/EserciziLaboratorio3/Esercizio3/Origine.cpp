#include<iostream>
#include<cstdlib>
#include<cmath>
#define N 3
using namespace std;


float radice(float x){
	
	float a=1;
	xn_1 = ((a + (x)/a)*0.5);
	while(abs(sqrt(x) - a) >= 0.001){
			
			a = ((a + (x)/a)*0.5);
		}
	return a;
}


int main(){
	float a[N]= {26,47,99};
	int i;
	float rad;
	for(i=0;i<N;i++){
		rad= radice(a[i]);
		cout << rad << endl;

		
	}
	cin >> i;
}



























