#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
using namespace std;

int main()
{
    int N,n;

    cin >> N;

    for (int i=0; i<N; i++)
    {
        deque<int> LeftSide, RightSide;

        cin >> n;
        int T;
        for (int i=0; i<n; i++)
            {
                cin >> T;
                LeftSide.push_back(T);
            }

        sort(LeftSide.begin(), LeftSide.end());
        int TotalTime = 0;
        stringstream fout;
        while(1)
        {

            int A = LeftSide[0];

            if (LeftSide.size() == 1) {fout << A; TotalTime += A; break;}

            int B = LeftSide[1];
            if (LeftSide.size() == 2)
            {
                fout << A << " " << B; TotalTime += B;break;
            }

            if (LeftSide.size() == 3)
            {
                fout << A << " " <<LeftSide[2] << endl << A << endl << A << " " <<  B ;
                TotalTime += B + A +  LeftSide[2];
                break;
            }
            int Y, Z;

            Z = LeftSide.back();
            LeftSide.pop_back();
            Y = LeftSide.back();
            LeftSide.pop_back();
            if (A + Y < 2*B)
            {
                fout << A << " " << Z << endl << A << endl << A << " " << Y << endl << A << endl;
                TotalTime += Z + 2*A + Y;
            }
            else
            {
                fout << A << " " << B << endl << A << endl << Y << " " << Z << endl << B << endl;
                TotalTime += 2*B + A + Z;
            }
        }

        cout<< TotalTime << endl << fout.str() << endl;

        if (i != N-1) cout << endl ;
    }
    return 0;
}
