#include <iostream>
using namespace std;
int x[50],k,n,v[50],nr=0;
void init(int k){
	x[k]=0;
}
int succesor(int k){
	int as;
	if(x[k]<n){as=1;x[k]++;}
	else as=0;
	return as;
}
int valid(int k){
	int ev,i;
	ev=1;
	for(i=1;i<=k-1;i++)
		if(x[k]==x[i]) ev=0;
	return ev;
}
int solutie(int k){
	if(k==n) return 1;
	else return 0;
}
void tipar(){
	int i;
	for(i=1;i<=n;i++)
		cout<<v[x[i]]<<" ";
	cout<<endl;
	nr++;
}
void back(int k){
	k=1;
	init(k);
	while(k>0){
		int as=1;
		int ev=0;
		while(as==1&&ev==0){
			as=succesor(k);
			if(as) ev=valid(k);
		}
		if(as)
			if(solutie(k)) tipar();
		else {k++;init(k);}
		else k--;}
}
int main(){
	cout<<"n=";cin>>n;
	for(int i=1;i<=n;i++)
	cin>>v[i];
	back(n);
	cout<<nr<<" ";
	return 0;
}
