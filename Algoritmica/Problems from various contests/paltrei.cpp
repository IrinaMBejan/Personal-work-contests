#include <fstream>

using namespace std;
ifstream fin("paltrei.in");
ofstream fout("paltrei.out");
int compar(int x[101],int y[101],int n);
int a[101],se[101];
int main()
{
    int k,i,r,s=0;
    fin>>k;
    for(i=1;i<=k;i++)
        fin>>a[i];
    int mid=k/2+k%2;
    for(i=1;i<=mid;i++)
    {
        se[k-i+1]=a[i];
        se[i]=a[i];
    }
    for(i=1;i<=k;i++)
        s+=se[i];
    r=s%3;
    while(compar(a,se,k)!=-1||r!=0)
    {
            se[mid]++;
            if(mid==k/2+k%2&&k%2==1) r+=1;
            else {r+=2; se[k-mid+1]++;}
            if(se[mid]==10)
            {
                i=mid-1;
                se[mid]=0;
                se[k-mid+1]=0;
                while(se[i]==9){ se[i]=0; se[k-i+1]=0; i--;}
                se[i]++;
                se[k-i+1]++;
                mid=k/2+k%2;
            }
            r%=3;
    }
    for(i=1;i<=k;i++)
        fout<<se[i];
    fout<<'\n';

    return 0;
}

int compar(int x[101],int y[101],int n)
{
    int i;
    for(i=1;i<=n;i++)
        if(x[i]>y[i])
                return 1;
        else if(x[i]<y[i])
                return -1;
    return 0;
}
