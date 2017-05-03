#include<cstdio>
using namespace std;
int transform(char* s);
int main()
{
   char* q="186692";
   printf("%d",transform(q));

   return 0;
}

int transform(char* sir)
{
    int nr=0,semn=1;
    if(*sir=='+'||*sir=='-')
        semn = (*(sir++)== '+') ? 1 : -1;
    while((*sir >= '0') && (*sir <= '9'))
    {
        nr = nr*10+(*sir-'0');
        sir++;
    }
    return (semn*nr);
}
