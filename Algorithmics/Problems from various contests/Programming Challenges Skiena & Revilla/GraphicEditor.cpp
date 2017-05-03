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
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int m, n;
char a [250 + 5] [250 + 5];
char preColor;

void reset ()
{
    for ( int i = 0; i < 250 + 5; i++ )
        memset (a [i], 'O', sizeof (a [i]));
}

void funcI ()
{
    scanf ("%d %d", &m, &n);
    reset ();
}

void funcL ()
{
    int x, y;
    char c [5];

    scanf ("%d %d %s", &x, &y, c);
    a [y] [x] = c [0];
}

void funcV ()
{
    int x, y1, y2;
    char c [5];

    scanf ("%d %d %d %s", &x, &y1, &y2, c);

    if ( y1 > y2 ) swap (y1, y2);

    for ( int i = y1; i <= y2; i++ )
        a [i] [x] = c [0];
}

void funcH ()
{
    int x1, x2, y;
    char c [5];

    scanf ("%d %d %d %s", &x1, &x2, &y, c);

    if ( x1 > x2 ) swap (x1, x2);

    for ( int i = x1; i <= x2; i++ )
        a [y] [i] = c [0];
}

void funcK ()
{
    int x1, x2, y1, y2;
    char c [5];

    scanf ("%d %d %d %d %s", &x1, &y1, &x2, &y2, c);

    for ( int i = y1; i <= y2; i++ ) {
        for ( int j = x1; j <= x2; j++ )
            a [i] [j] = c [0];
    }
}

void funcS ()
{
    char name [1000];
    scanf ("%s", name);
    printf ("%s\n", name);

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ )
            printf ("%c", a [i] [j]);
        printf ("\n");
    }
}

void funcF (int x, int y, char c)
{
    if ( x < 1 || x > m || y < 1 || y > n || a [y] [x] != preColor || c == preColor ) return;

    a [y] [x] = c;

    funcF (x, y - 1, c); // up
    funcF (x + 1, y, c); // right
    funcF (x, y + 1, c); // down
    funcF (x - 1, y, c); // left
}

int main ()
{
    char input [5];

    while ( scanf ("%s", input) ) {
        switch (input [0]) {
            case 'I' :
                funcI (); break;
            case 'C' :
                reset (); break;
            case 'L' :
                funcL (); break;
            case 'V' :
                funcV (); break;
            case 'H' :
                funcH (); break;
            case 'K' :
                funcK (); break;
            case 'F' :
                int x, y;
                char c [5];

                scanf ("%d %d %s", &x, &y, c);
                preColor = a [y] [x];

                funcF (x, y, c [0]); break;
            case 'S' :
                funcS (); break;
            case 'X' : exit (0);
            default :
                char garbage [1000];
                gets (garbage);
        }
    }

    return 0;
}
