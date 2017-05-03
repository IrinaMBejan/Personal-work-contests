#include <cstdio>
#include <cmath>
int main()
{
    int cases=0;
    scanf("%d",&cases);
    int i;
    for(i=0;i<cases;i++){
        int x=0,y=0;
        scanf("%d %d",&x,&y);
        int sum=y-x;
        int lol=sqrt(sum),result=0;
        if(sum==0){
            result=0;
        }else if(lol*lol==sum){
            result=lol*2-1;
        }else if(lol*lol+lol<sum){
            result=lol*2+1;
        }else{
            result=lol*2;
        }
        printf("%d\n",result);
    }
    return 0;
}
