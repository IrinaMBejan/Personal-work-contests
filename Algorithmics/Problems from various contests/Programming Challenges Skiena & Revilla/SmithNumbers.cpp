#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using std::vector;


/* Prepared prime numbers. */
static vector<int> primes;


/* Smallest smith number larger than n. */
static unsigned long int smith (const int n);

/* Finds primes < max_p. */
static void prime_sieve(const int max_p);

/* Returns true if n is prime. */
static bool isPrime (const unsigned long int n);

/* Returns sum of the digits. */
static int digits (const unsigned long int n);


int main (void) {
    int count, n;
    if (scanf("%d", &count) != 1) {
        return EXIT_SUCCESS;
    }

    prime_sieve(10000);
    while (count-- > 0) {
        if (scanf("%d", &n) != 1) {
            return EXIT_SUCCESS;
        }

        printf("%lu\n", smith(n));
    }
}


static unsigned long int smith (const int n) {
    unsigned long int smith = n + 1;
    for (;;) {
        if (!isPrime(smith)) { /* Primes are excluded. */
            unsigned long int sum_factors = 0, k = smith;
            for (int i = 0; i < primes.size(); i++) {
                if (primes[i] > sqrt(k) + 1) {
                    break;

                } else {
                    while (k % primes[i] == 0) {
                        sum_factors += digits(primes[i]);
                        k = k / primes[i];
                    }
                }
            }

            if (k > 1) { /* K is prime. */
                sum_factors += digits(k);
            }

            if (digits(smith) == sum_factors) {
                return smith;
            }
        }

        smith += 1;
    }
}

static int digits (const unsigned long int n) {
    int sum = 0;
    for (unsigned int k = n; k > 0; k /= 10) {
        sum += k % 10;
    }
    return sum;
}

static bool isPrime (const unsigned long int n) {
    if (n == 1u) {
        return false;
    }

    for (int i = 0; i < primes.size() && primes[i] < n; i++) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

static void prime_sieve (const int max_p) {
    for (int i = 2; i <= max_p; i++) {
        int root = int(sqrt(i)) + 1;
        bool found = false;
        for (vector<int>::const_iterator it = primes.begin(); it != primes.end() && *it < root; it++) {
            if (i % *it == 0 ) {
                found = true;
                break;
            }
        }

        if (!found) {
            primes.push_back(i);
        }
    }
}
