#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define max(a,b) (a>b?a:b)
const int MAXN=10005;
struct bigint
{
    string buf;
    bigint(string s="0") { buf=s; }
    void operator=(string s) { buf=s; }
    void operator=(bigint b) { buf=b.buf; }
    bigint operator+(bigint b)
    {
        int i, len = max(b.buf.length(), buf.length());
        int val, carry=0;
        string r;

        while((int)b.buf.length() < len) b.buf = "0" + b.buf;
        while((int)buf.length() < len) buf = "0" + buf;

        for(i=len-1; i>=0; i--) {
            val = (buf[i]-'0' + b.buf[i]-'0' + carry) % 10;
            carry = (buf[i]-'0' + b.buf[i]-'0' + carry) / 10;
            r = char(val+'0') + r;
        }
        if(carry > 0) r = char(carry+'0') + r;
        return r;
    }
} dif[MAXN], t[MAXN];

int main()
{
    int i=1, j, p=2, n;

    dif[0] = "1";
    while(i < MAXN) {
        j = 1;
        while(j++ <= p) {
            dif[i] = j==2 ? dif[i-1]+dif[i-1] : dif[i-1];
            if(++i >= MAXN) break;
        }
        p++;
    }

    t[1] = "1";
    for(i=2; i<MAXN; i++)
        t[i] = t[i-1]+dif[i-1];

    while(scanf("%d", &n) > 0)
        printf("%s\n", t[n].buf.c_str());

    return 0;
}
