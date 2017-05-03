#include <fstream>
using namespace std;
ifstream fin("romb1.in");
ofstream fout("romb1.out");

int T, k, i, pminim;
double qx, qy, cx, cy, c1x, c1y, c2x, c2y, c3x, c3y, c4x, c4y, dx, dy, d1, d2, d3, d4, minim;
long long sol, start;

double dist(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a = y2-y1;
	double b = x1-x2;
	double c = -x1*(y2-y1) + y1*(x2-x1);
	double aux = a*x3+b*y3+c;
	return aux*aux/(a*a + b*b);
}

int main()
{
	fin>>T;
	while (T)
    {
		fin>>dx>>dy>>k>>qx>>qy;
		start = 1LL << (2*(k-1));
		cx = 0;
		cy = 0;
		sol = 0;
		for (i=1;i<=k;i++)
		{
			dx/= 2;
            dy/= 2;
			c1x = cx; c1y = cy + dy;
			c2x = cx - dx; c2y = cy;
			c3x = cx; c3y = cy - dy;
			c4x = cx + dx; c4y = cy;

			d1 = dist(c1x, c1y, c2x, c2y, qx, qy);
			d2 = dist(c2x, c2y, c3x, c3y, qx, qy);
			d3 = dist(c3x, c3y, c4x, c4y, qx, qy);
			d4 = dist(c4x, c4y, c1x, c1y, qx, qy);
			minim = d1 + d4;
			pminim = 1;
			if (minim>d1 + d2) {
				minim = d1 + d2;
				pminim = 2;
			}
			if (minim > d2 + d3) {
				minim = d2 + d3;
				pminim = 3;
			}
			if (minim > d3 + d4) {
				minim = d3 + d4;
				pminim = 4;
			}
			if (pminim == 1) {
				cx = c1x;
				cy = c1y;
				sol += 0*start;
			}
			if (pminim == 2) {
				cx = c2x;
				cy = c2y;
				sol += 1*start;
			}
			if (pminim == 3) {
				cx = c3x;
				cy = c3y;
				sol += 2*start;
			}
			if (pminim == 4) {
				cx = c4x;
				cy = c4y;
				sol += 3*start;
			}
			start /= 4LL;
		}
		fout<<sol+1<<"\n";
		T--;
	}
	return 0;
}
