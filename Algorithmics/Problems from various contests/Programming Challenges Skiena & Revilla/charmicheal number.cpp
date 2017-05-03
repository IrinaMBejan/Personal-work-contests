#include<bitset>
#include<cstdio>
#include<vector>

using namespace std;

int n;
bitset<10000010> bs;
bool is_prime[65100], is_carmichael[65100];

void sieve(long long upper_bound) {
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= upper_bound + 1; i++) {
        if(bs[i]) {
            for(long long j = i * i; j <= upper_bound + 1; j += i)
                bs[j] = 0;
            is_prime[i] = true;
        }
    }
}

int mod_pow(long long base, int exp, int mod) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool carmichael(int n) {
    if(is_prime[n]) return false;
    for(int i = 2; i < n; i++) {
        if(mod_pow(i, n, n) != i) return false;
    }
    return true;
}

int main() {
    sieve(65000);
    for(int i = 2; i <= 65000; i++)
        is_carmichael[i] = carmichael(i);
    for(;;) {
        scanf("%d", &n);
        if(n == 0) break;

        printf(is_carmichael[n]? "The number %d is a Carmichael number.\n" : "%d is normal.\n", n);
    }
}
