#include <iostream>

using namespace std;
ofstream fout("bla.out");
int a[100];
int cost[100][100];
int main()
{
    cin>>N;
    for(int i = 1; i<=N;i++)
        cin>>a[i];

    cout<<sol(1,N);
    return 0;
}

int sol(int i, int j)
{
    if(cost[i][j]) return;
    if(i>j) return;

    int minim = 99999;
    for(int k = i; k<=j;k++)
        if(c)
    cost[i][j] =
}
