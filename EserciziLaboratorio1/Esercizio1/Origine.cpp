#include<iostream>
#include<cstdlib>
#define N 5

using namespace std;

int main(){
	int a[N] = {2,-5,6,3,1};
	int b[N] = {0,-3,6,-9,12};
	int c[N];
	int d[N];
	int b_rivolt[N];
	int i;
	cout << "Il vettore a risulta : " << endl;
	for(i=0;i<N;i++){
		cout << a[i] << endl;
	}

	cout << "Il vettore b risulta : " << endl;
	for(i=0;i<N;i++){
		cout << b[i] << endl;
	}


	cout << "Il vettore b rivoltato risulta : " << endl;
	for(i=0;i<N;i++){
		b_rivolt[(N-1)-i]= b[i];
	}

	for(i=0;i<N;i++){
		cout << b_rivolt[i] << endl;
	}
	cout << " " << endl;

	for(i=0;i<N;i++){
		c[i]= a[i]+b_rivolt[i];
	}

	cout << "Il vettore c risulta : " << endl;
	for(i=0;i<N;i++){
		cout << c[i] << endl;
	}
	cout << " " << endl;


	for(i=0;i<N;i++){
		if(a[i]>b[i]){
			d[i]=1;
		}
		 else if(a[i]==b[i]){
			 d[i]= 0;
		 }
		 else if (a[i]<b[i]){
			 d[i]=-1;
		 }
	}

	cout << "Il vettore d risulta : " << endl;
	for(i=0;i<N;i++){
		cout << d[i] << endl;
	}



	cin >> i;
}