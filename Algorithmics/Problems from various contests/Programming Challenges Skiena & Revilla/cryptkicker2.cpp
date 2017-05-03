#include<iostream>
#include<cstring>
#include<map>
#include<cctype>
using namespace std;

const int NMAX = 85;

map<char, int> values;
char model[NMAX] = "the quick brown fox jumps over the lazy dog";
int modLength;
int modSpaces[NMAX];
char s[105][NMAX];
int lg[105];
int lines;

void spaces(char sir[NMAX], int n, int sp[NMAX])
{
    int i, k = 0;
    for(i=0; i<n; i++)
        if( sir[i] == ' ') sp[++k] = i;
    sp[0] = k;
}

bool passText(int a[NMAX], int b[NMAX])
{
    if(a[0] != b[0]) return 0;
    int i;
    for(i = 1; i<=a[0]; i++)
        if(a[i]!=b[i]) return 0;
    return 1;
}

int main()
{
    int N;
    int spacez[NMAX];
    cin>>N;
    cin.get();
    cin.get();

    modLength = strlen(model);
    spaces(model, modLength,modSpaces);
    for(int i = 1; i<=N; i++)
    {
        int lines = 0;
        do
        {
            cin.getline(s[lines],NMAX);
            lg[lines] = strlen(s[lines]);
        }
        while(isalpha(s[lines++][0]));

        for(int j = 0; j <lines; j++)
        {
            spaces(s[j],lg[j], spacez);
            int ok = passText(spacez, modSpaces);
            if(ok)
            {
                for(int x = 'a'; x<='z'; x++)
                    values[(char)x] = -1;

                for(int q = 0; q<modLength; q++)
                    if(model[q] != ' ')
                    {
                        if(values[s[j][q]] == -1)
                        {
                            values[s[j][q]] = (int) model[q];
                        }
                        else
                        {
                            if(values[s[j][q]] == (int)model[q])
                                continue;
                            else
                            {
                                ok = 0;
                                break;
                            }
                        }
                    }
                if(ok)
                {
                    for(int p = 0; p <lines; p++)
                    {
                        for(int z = 0; z < lg[p]; z++)
                            if(s[p][z] == ' ') cout<<' ';
                            else cout<<(char)values[s[p][z]];
                        cout<<'\n';
                    }
                }
            }
            values.clear();

        }


    }
    return 0;
}
