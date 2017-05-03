#include <fstream>

using namespace std;
ifstream fin("cern.in");
ofstream fout("cern.out");
int main()
{
	char p;
	int s,c=1,pp=0;
	long long t;
	fin>>p;
	fin>>s>>t;

	switch (p)
	{
		case 'A':pp=0;c=1;break;
		case 'B':pp=60;c=1;break;
		case 'C':pp=120;c=2;break;
		case 'D':pp=180;c=2;break;
		case 'E':pp=240;c=3;break;
		case 'F':pp=300;c=3;break;
	}


	int i,pozitie=pp,sens=s,cerc=c;
	for(i=1;i<=t%(3*360);i++)
	{
		switch (pozitie)
		{
			case 180 : 	if(sens==1&&cerc==1)
									{
									pozitie=360;
									sens=-1;
									cerc=2;
									}
						if (sens==-1&&cerc==1)
									{
									pozitie=0;
									sens=1;
									cerc=2;
									}
						break;
			case 0	 : if (cerc==2)
									{
									pozitie=180;
									sens=sens*(-1);
									cerc=1;
									}
						if (cerc==1&&sens==-1) pozitie=360;
						if (cerc==3&&sens==-1) pozitie=360;
						break;
			case 300 : if (cerc==2)
									{
									pozitie=120;
									sens=sens*(-1);
									cerc=3;
									}
						break;
			case 120 : if (cerc==3)
									{
									pozitie=300;
									sens=sens*(-1);
									cerc=2;
									}
						break;
			case 60	 : if (cerc==3)
									{
									pozitie=240;
									sens=sens*(-1);
									cerc=1;
									}
						break;
			case 240 : if (cerc==1)
									{
									pozitie=60;
									sens=sens*(-1);
									cerc=3;
									}
						break;

			case 360 :	if (cerc==2&&sens==1)
									{
									pozitie=180;
									cerc=1;
									sens=sens*(-1);
									}
						if (cerc==1&&sens==1) pozitie=0;
						if (cerc==3&&sens==1) pozitie=0;
						break;
		}
		pozitie=pozitie+sens;

	}

	fout<<pozitie%360<<" "<<cerc<<'\n';
return 0;
}
