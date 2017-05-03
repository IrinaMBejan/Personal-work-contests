#include <iostream>
#include <complex>
#include <cmath>
#define Nmax 1005
using namespace std;

unsigned int bitReverse(unsigned int x, int log2n)
{
    int n = 0;
    for (int i=0; i < log2n; i++)
    {
        n = n<<1;
        n = n| (x & 1);
        x >>= 1;
    }
    return n;
}

const double PI = 3.1415926536;

void fft(complex<double> a[Nmax], complex<double> b[Nmax], int log2n)
{
    const complex<double> J(0, 1);
    int n = 1 << log2n;
    for (unsigned int i=0; i < n; ++i)
    {
        b[bitReverse(i, log2n)] = a[i];
    }

    for (int s = 1; s <= log2n; ++s)

    {
        int m = 1 << s;
        int m2 = m >> 1;
        complex<double> w(1, 0);
        complex<double> wm = exp(-J * (PI / m2));
        for (int j=0; j < m2; ++j)

        {
            for (int k=j; k < n; k += m)

            {
                complex<double> t = w * b[k + m2];
                complex<double> u = b[k];
                b[k] = u + t;
                b[k + m2] = u - t;
            }
            w *= wm;
        }
    }
}
int main( )
{
    complex<double>  a[8], b[8];
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        complex<double> c(x, y);
        a[i] = c;
    }

    fft(a, b, 3);
    for (int i=0; i<8; ++i)
        cout << b[i] << "\n";

}
