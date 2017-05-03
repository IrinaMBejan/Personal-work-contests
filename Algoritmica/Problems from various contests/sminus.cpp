#include <fstream>

using namespace std;
ifstream fin("sminus.in");
ofstream fout("sminus.out");
int s[100001], n;
int main()
{
    int i;
    fin >> n;
    for(i=1; i<=n; i++)
        fin >> s[i];
    int bestSum = -100000000, min = 0, pozmin=0, st, fi;
    for(i=1; i<=n; i++)
    {
        s[i] += s[i - 1];
        if (bestSum < s[i] - min)
        {
            bestSum = s[i] - min;
            st=pozmin + 1;
            fi=i;
        }
        if (min > s[i])
        {
            min = s[i];
            pozmin= i;
        }
    }
    fout<<st<<" "<<fi<<'\n'<<s[n]-2*bestSum<<'\n';
    return 0;
}
