#include<cstdio>
#include<cstring>

using namespace std;

int t, n, m, k, len, r, c;
char grid[100][100], word[100];

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool despite_case(char c, char d) {
    if(c == d) return true;
    if(c >= 'A' && c <= 'Z' && c == (d + 'A' - 'a'))
        return true;
    if(c >= 'a' && c <= 'z' && d == (c + 'A' - 'a'))
        return true;
    return false;
}

bool search(int r, int c) {
    for(int i = 0; i < 8; i++) {
        int rt = r, ct = c, k;
        for(k = 0; k < len; k++) {
            if(rt >= n || rt < 0 || ct >= m || ct < 0) break;
            if(!despite_case(grid[rt][ct], word[k])) break;
            rt += x[i], ct += y[i];
        }
        if(k == len) return true;
    }
    return false;
}

void init() {
    for(r = 0; r < n; r++)
        for(c = 0; c < m; c++) {
            if(search(r, c))
                return;
        }
}

int main() {
    scanf("%d", &t);
    for(int u = 0; u < t; u++) {
        if(u != 0) printf("\n");

        scanf("%d %d\n", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%s", grid[i]);
        scanf("%d\n", &k);
        for(int i = 0; i < k; i++) {
            scanf("%s", word);
            len = strlen(word);

            init();
            printf("%d %d\n", r + 1, c + 1);
        }
    }
}
