#include <iostream>
//#include <stdio.h>
using namespace std;

int a[20],b[20];

void aranjamente(int k, int len, int max){
	if(k-1 == max){
		for(int i = 1; i <= max; i++)
			cout << a[i]<<" ";
		cout << '\n';
	}
	else{
		for(int  i = 1; i <= len; i++)
			if(!b[i]){
				a[k] = i;
				b[i] = 1;
				aranjamente(k+1, len, max);
				b[i] = 0;
			}
	}
}

int main(){
	int n,k;
	cin >> n;
	cin >> k;
	aranjamente(1, n, k);
	return 0;
}
