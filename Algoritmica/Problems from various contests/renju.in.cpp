#include <fstream>
using namespace std;

ifstream fin ("renju.in");
ofstream fout ("renju.out");
int a[20][20];
int main ()
{
	int  i , j , ok, ic, jc, k, contor ;

	for(i=1;i<20;i++)
		for(j=1;j<20;j++)
			fin>>a[i][j];

	ok=0;
	for(i=1;i<20&&!ok;i++)
		for(j=1;j<20&&!ok;j++)
			{
				if(a[i][j]!=0)
				{
					if(a[i][j]!=a[i][j-1])
					{
						contor=1;
					for(k=j+1;k<20;k++)
						if(a[i][j]==a[i][k])
							contor++;
						else break;
					if(contor==5)
						{
							ic=i;
							jc=j;
							ok=a[i][j];

						}
	            }
				if(a[i][j]!=a[i-1][j])
				{
					contor=1;
					for(k=i+1;k<20;k++)
						if(a[k][j]==a[i][j])
							contor++;
						else break;
					if(contor==5)
					{
						ic=i;
						jc=j;
						ok=a[i][j];

					}
	            }
				if(a[i][j]!=a[i-1][j-1])
				{
					contor=1;
				for(k=1;k<20-i&&k<20-j;k++)
					if(a[i+k][j+k]==a[i][j])
						contor++;
					else break;

				if(contor==5)
				{
					ic=i;
					jc=j;
					ok=a[i][j];
				}
				}
				if(a[i][j]!=a[i+1][j-1])
				{
                contor=1;
				for(k=1;k<20-j&&i>k;k++)
					if(a[i-k][j+k]==a[i][j])
						contor++;
					else break;

				if(contor==5)
					{
					ic=i;
					jc=j;
					ok=a[i][j];
					}
					}
			    }
			}

	fout<<ok<<'\n';
	if(ok!=0)
		fout<<ic<<' '<<jc;

fout.close();
return 0;

}



/*#include <fstream>

using namespace std;
ifstream fin("renju.in");
ofstream fout("renju.out");

int a[22][22];
int lin[10]={0,-1,-1,0,1, 1, 1, 0,-1};
int col[10]={0, 0, 1,1,1, 0,-1,-1,-1};

int main()
{
    int i,j;
    for(i=1;i<=19;i++)
        for(j=1;j<=19;j++)
            fin>>a[i][j];
    int nr; int prod; int f;
    for(i=1;i<=19;i++)
        for(j=1;j<=19;j++)
            if(a[i][j]==1)
            {
                for(int k=1;k<=8;k++)
                   {
                       nr=1;
                       while(a[i+nr*lin[k]][j+nr*col[k]]==1)
                                    nr++;
                        if(nr==5)
                            {
                                fout<<"1"<<'\n';
                                if(k==1||k==6||k==7||k==8)
                                    fout<<i+nr*lin[k]<<" "<<j+nr*col[k]<<'\n';

                                else if(k==2||k==3||k==4||k==5)
                                    fout<<i<<" "<<j<<'\n';

                                return 0;
                            }
                   }
            }
            else if(a[i][j]==2)
            {
                for(int k=1;k<=8;k++)
                   {
                      nr=1;
                       while(a[i+nr*lin[k]][j+nr*col[k]]==2)
                                nr++;
                        if(nr==5)
                          {
                                fout<<"2"<<'\n';
                                return 0;
                          }
                   }
            }
    fout<<"0"<<'\n';
    return 0;
}
*/
