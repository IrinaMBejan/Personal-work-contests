#include <cstdio>
#include <cstring>

int N, t1, t2, t3, ans, a[1<<14], b[1<<14];
int S[1<<14];

int main()
{
	int i, j;
	int t;

	freopen("log.in", "r", stdin);
	freopen("log.out", "w", stdout);

	scanf("%d\n%d %d %d", &N, &t1, &t2, &t3);
	memset(S, 0x3f3f3f3f, sizeof(S));
	S[0] = N*t2-t1;
	for (i = 1; i <= N; ++i) {
		scanf("%d %d", a+i, b+i);
		for (j = i; j > 0; --j) {
			if (j < i && b[j] != a[j+1])
				break;
			if (S[i] > (t = S[j-1]+t3*(a[j]-b[i])*(a[j]-b[i])+t1-t2)) {
				S[i] = t;
			}
		}
	}
	printf("%d\n", S[N]);
	return 0;
}
