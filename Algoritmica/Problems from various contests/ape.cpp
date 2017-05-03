#include <fstream>

using namespace std;
ifstream fin("ape.in");
ofstream fout("ape.out");

char S[10002];

int main()
{
    int n,i;
    fin>>n;
    fin>>S;
    int x=0,y=0,xm=100000, ym=100000, xM=-100000, yM=-100000;
    for(i=0; i<n; i++)
    {
        if(S[i]=='N') y++;
        else if(S[i]=='S') y--;
        else if(S[i]=='E') x++;
        else x--;

        if(x>xM) xM=x;
        if(x<xm) xm=x;
        if(y>yM) yM=y;
        if(y<ym) ym=y;
    }
    int l,L,A,P=0;
    l=xM-1-xm;
    L=yM-ym-1;
    fout<<l<<" "<<L<<" ";

    A=l*L;
    x=0;
    y=0;
    int s=0;
    for (i=0; i<n-1; i++)
    {
        if (S[i]=='N')
            switch (S[i+1])
            {
            case 'N' :
            {
                s=s-x-1;
                y++;
                break;
            }
            case 'E' :
            {
                x++;
                break;
            }
            case 'V' :
            {
                s=s-x-1;
                x--;
                break;
            }
            }
        else if (S[i]=='V')
            switch (S[i+1])
            {
            case 'N' :
            {
                y++;
                break;
            }
            case 'V' :
            {
                x--;
                break;
            }
            case 'S' :
            {
                s=s+x;
                y--;
                break;
            }
            }
        else if (S[i]=='S')
            switch (S[i+1])
            {
            case 'S' :
            {
                s=s+x;
                y--;
                break;
            }
            case 'V' :
            {
                x--;
                break;
            }
            case 'E' :
            {
                s=s+x;
                x++;
                break;
            }
            }
        else
            switch (S[i+1])
            {
            case 'S' :
            {
                y--;
                break;
            }
            case 'E' :
            {
                x++;
                break;
            }
            case 'N' :
            {
                s=s-x-1;
                y++;
                break;
            }
            }
    }
    if (S[n-1]=='N')
        switch (S[1])
        {
        case 'N' :
        {
            s=s-x-1;
            y++;
            break;
        }
        case 'E' :
        {
            x++;
            break;
        }
        case 'V' :
        {
            s=s-x-1;
            x--;
            break;
        }
        }
    else if (S[n-1]=='V')
        switch (S[1])
        {
        case 'N' :
        {
            y++;
            break;
        }
        case 'V' :
        {
            x--;
            break;
        }
        case 'S' :
        {
            s=s+x;
            y--;
            break;
        }
        }
    else if (S[n-1]=='S')
        switch (S[1])
        {
        case 'S' :
        {
            s=s+x;
            y--;
            break;
        }
        case 'V' :
        {
            x--;
            break;
        }
        case 'E' :
        {
            s=s+x;
            x++;
            break;
        }
        }
    else
        switch (S[1])
        {
        case 'S' :
        {
            y--;
            break;
        }
        case 'E' :
        {
            x++;
            break;
        }
        case 'N' :
        {
            s=s-x-1;
            y++;
            break;
        }
        }

    if (s<0)
    {
        P=1;
        s=-s;
        s=s-n;
    }
    else P=0;
    fout<<P<<" "<<s<<'\n';

    return 0;
}
