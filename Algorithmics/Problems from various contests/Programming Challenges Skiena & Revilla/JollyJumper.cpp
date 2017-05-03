#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cmath>
#include <map>
#include <queue>
using namespace std;


int main()
{

    int Left, Right;
    while(1)
    {
        int n;
        int Numbers[3000] = {0};
        char input;
        input = cin.get();
        if (input == '\n') break;
        if (cin.eof()) break;
        cin.putback(input);
        cin >> n;

        cin >> Right;

        for (int i=0; i<n-1; i++)
        {
            Left = Right;
            cin >> Right;
            int diff = abs(Right-Left);
            if (diff >= 1 && diff <= n-1) Numbers[diff] = 1;
        }

        bool Jolly = true;

        for (int i=1; i<n; i++) if (!Numbers[i]) Jolly = false;

        if (Jolly) cout << "Jolly";
        else cout << "Not jolly";

        cout << endl;
        cin.get();
    }
    return 0;
}
