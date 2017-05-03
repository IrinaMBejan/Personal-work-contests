#include<iostream>
#include<cmath>
using namespace std;

int isPrime(int x) {
    int s = sqrt(x);
    for (int i = 2; i <= s; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
void Num(int x, int & a, int & b) {
    for (int i = 2; i <= x / 2; i++) {
        if (isPrime(i) && isPrime(x - i)) {
            a = i;
            b = x - i;
            return;
        }
    }
}
int main() {
    int n;
    while (cin >> n) {
        if (n <= 7) {
            cout << "Impossible." << endl;
            continue;
        }
        if (n % 2 !=0) {
            int a, b;
            Num(n -5, a, b);
            cout << "2 3 " << a << " " << b << endl;
        }
        else {
            int a, b;
            Num(n -4, a, b);
            cout << "2 2 " << a << " " << b << endl;
        }
    }
    return 0;
}
