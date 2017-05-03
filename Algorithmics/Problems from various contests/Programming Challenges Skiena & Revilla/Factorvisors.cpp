#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>


using std::vector;
using std::queue;


vector<int> primes;

struct factor {
    int prime, count;
};


/* Returns true if n is prime. */
static bool isPrime (int n);

/* Tests if n!|m is true. */
static bool divides_factorial (const int n, const int m);

/* Prepares table of primes. */
static void prime_sieve (int max_n);

/* Returns power of factor in n!. */
static int get_powers (const unsigned long int n, const int p);


int main (void) {
    int n, m;
    prime_sieve(50000);
    while (scanf("%d %d", &n, &m) == 2) {
        if (divides_factorial(n, m)) {
            printf("%d divides %d!\n", m, n);
        } else {
            printf("%d does not divide %d!\n", m, n);
        }
    }
    return EXIT_SUCCESS;
}

static bool divides_factorial (const int n, const int m) {
    if (m == 0) {
        return false;

    } else if (n >= m) {
        return true;

    } else {
        int k = m;
        vector<factor> factors;
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > k) {
                break;

            } else {
                factor f = {primes[i], 0};
                while (k % primes[i] == 0) {
                    f.count += 1;
                    k = k / primes[i];
                }

                if (f.count) {
                    factors.push_back(f);
                }
            }
        }

        if (k > 1) { // k is a prime
            if (n < k) {
                return false;
            } else {
                factors.push_back((factor) {k, 1});
            }
        }

        for (int i = 0; i < factors.size(); i++) {
            if (factors[i].count - get_powers(n, factors[i].prime) > 0) {
                return false;
            }
        }
        return true;
    }
}

static bool isPrime (int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

static void prime_sieve (int max_n) {
    for (int i = 2; i < max_n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
}

static int get_powers (const unsigned long int n, const int p) {
    int res = 0;
    for (unsigned long int power = p; power <= n; power *= p) {
        res += n / power;
    }
    return res;
}
