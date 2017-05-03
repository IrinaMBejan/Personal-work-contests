#include <stdio.h>
#include <algorithm>

using namespace std;

long long A,B,X,Y,D,temp,Ans,minK,maxK,T;
int N;

inline long long euclid(long long A,long long B,long long &X,long long &Y )
{
    if (B == 0)
    {
        X = 1;
        Y = 0;
        return A;
    }

    long long X0, Y0, D;
    D = euclid( B, A % B, X0, Y0 );
   
    X = Y0;
    Y = X0 - (A / B) * Y0;
    return D;
}

int main()
{
    freopen("oak.in","r",stdin);
    freopen("oak.out","w",stdout);
   
    for (scanf("%d\n",&N); N; --N){
        scanf("%lld %lld %lld",&A,&B,&T);
        if (A>B) swap(A,B);
       
        long long D = euclid(A,B,X,Y);
       
        if (T%D){
            printf("-1\n");
            continue;
        }
        else {
            X*=T/D;
            Y*=T/D;
        }
        A/=D; B/=D;
       
        temp = -X;
        if (temp%B == 0) minK = temp/B;
        else
            if (temp<0) minK = temp/B;
            else minK = temp/B + 1;
       
        temp = Y;
        if (temp%A == 0) maxK = temp/A;
        else
            if (temp<0) maxK = temp/A-1;
            else maxK = temp/A;
       
        Ans = X+Y + minK * (B-A);
        if (minK <= maxK){
            if (Ans < 0) printf("Nu e bine\n");
            else
                printf("%lld\n",Ans);
        }
        else
            printf("-1\n");
    }
   
    return 0;
}