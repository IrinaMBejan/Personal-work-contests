#define TuTTy "Cosmin-Mihai Tutunaru"
#include <cstdio>
#define infile "superstring.in"
#define outfile "superstring.out"
#define ll long long

using namespace std;

ll k;
int ret;

void read() {
    scanf("%lld\n", &k);
}

int digits(ll x) {
    int cnt = 0;

    while(x) {
        x /= 10, ++cnt;
    }

    return cnt;
}

int getDigit(ll x, int d) {
    d = digits(x) - d;

    while(d) x /= 10, --d;
    return x%10;
}

ll cnt(ll x) {

    int d = digits(x);

    ll nine = 0, ten = 1;
    ll ret = 0,  prv = 0;

    for (int i = 0; i < d-1; ++i) {
        nine = nine * 10 + 9, ten = ten * 10;
        ret += (nine * ten / 2 - prv) * (i+1);
        prv = nine * ten / 2;
    }

    ret += (x*(x+1)/2 - prv) * d;

    return ret;
}

void solve() {
    ret = 0;

    ll le = 1;
    ll ri = 1<<29;

    while (le <= ri) {

        ll mi = (le+ri)>>1;

        if (cnt(mi) < k) {
            ret = mi;
            le = mi+1;
        } else {
            ri = mi-1;
        }
    }

    k -= cnt(ret);
    ret++;

    k %= digits(ret);
    if (k == 0) k = digits(ret);

    ret = getDigit(ret, k);

}

void write() {
    printf("%d\n", ret);
}

int main() {
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    int t;
    scanf("%d\n", &t);

    while(t--) {
        read();
        solve();
        write();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
