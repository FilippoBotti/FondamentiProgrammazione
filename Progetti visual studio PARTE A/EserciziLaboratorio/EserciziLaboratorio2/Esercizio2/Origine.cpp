#include<iostream>
#include<cstdlib>
#define N 30
using namespace std;

int main(){
	int a[N];
	int b[N];
	int liberi[N];
	int i=0;
	int giorno_a=1;
	int giorno_b=1;

	for(i=0;i<N;i++){
		a[i]=0;
		b[i]=0;
	}

	while(giorno_a!=0){
		cout << "Inserisci il giorno impegnato di a " << endl;
		cin >> giorno_a;
		if(giorno_a!=0){
		a[giorno_a-1]=1;
		}
	}

	while(giorno_b!=0){
		cout << "Inserisci il giorno impegnato di b " << endl;
		cin >> giorno_b;
		if(giorno_b!=0){
		a[giorno_b-1]=1;
		}
	}

	for(i=0;i<N;i++){
		if((a[i]==0) && (a[i]==b[i])){
			liberi[i]=1;
		}
		else {
			liberi[i]=0;
		}

	}
	cout << "I giorni che entrambi hanno liberi sono " << endl;
	for(i=0;i<N;i++){
		cout << liberi[i] << endl;
	}




	cin >> giorno_a;
}


