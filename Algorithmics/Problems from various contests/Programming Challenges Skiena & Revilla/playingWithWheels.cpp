#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int T, n, s, t, f[10000], F;
queue<int> q;
int dist[10000];

int read() {
    int res = 0, asdf;
    for (double i=3 ; i>=0 ; i--) {
        scanf("%d", &asdf);
        res += asdf*(int)pow(10.0, i);
    }
    return res;
}

int bfs() {
    memset(dist, -1, sizeof dist);
    q = queue<int>();
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int p = u;
        int v;
        for (int i=0 ; i<4 ; i++) {
            int d = (int)pow(10.0, (double)i);
            if (p % 10 == 0) v = u + (d*9);
            else v = u-d;
            if (!f[v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (v == t) return dist[v];
                q.push(v);
            }
            if (p % 10 == 9) v = u - (d*9);
            else v = u + d;
            if (!f[v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (v == t) return dist[v];
                q.push(v);
            }
            p /= 10;
        }
    }
    return -1;
}

int main() {
    scanf("%d\n", &T);
    while (T--) {
        memset(f, 0, sizeof f);
        s = read();
        t = read();
        scanf("%d", &n);
        while (n--) {
            F = read();
            f[F] = 1;
        }
        if (s == t) {
            printf("0\n");
            continue;
        }
        printf("%d\n", bfs());
    }
}
