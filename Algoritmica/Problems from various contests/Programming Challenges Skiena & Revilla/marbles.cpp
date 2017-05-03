#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>

using namespace std;
long x, y; // result
long c1, n1, c2, n2, n; // input

void ex_gcd(long a, long b, long &d, long &x, long &y) {
 if (b == 0) {
 x = 1, y = 0, d = a;
 return;
 }
 long x1, y1;
 ex_gcd(b, a % b, d, x1, y1);
 x = y1;
 y = x1 - (a / b) * y1;
}

bool check() {
 long gcd, m1, m2;
 ex_gcd(n1, n2, gcd, m1, m2);
 if (n % gcd != 0)
 return false;
 m1 *= n / gcd, m2 *= n / gcd;
 n2 /= gcd, n1 /= gcd;
 long c = ceil(-(double) m1 / n2), f = floor((double) m2 / n1);
 if (c > f)
 return false;
 long cost = c1 * n2 - c2 * n1;
 if (cost * c < cost * f)
 x = m1 + n2 * c, y = m2 - n1 * c;
 else
 x = m1 + n2 * f, y = m2 - n1 * f;
 return true;
}

int main() {
 while (scanf("%ld", &n) != EOF && n != 0) {
 scanf("%ld%ld%ld%ld", &c1, &n1, &c2, &n2);
 if (check())
 printf("%ld %ld\n", x, y);
 else
 printf("failed\n");
 }
 return 0;
}
