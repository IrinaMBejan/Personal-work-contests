
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool decode(int &pc, vector< int > &reg, vector< int > &ram)
{
	int inst = ram.at(pc);
	int c = inst / 100,
		a = (inst % 100) / 10,
		b = inst % 10;

	switch(c) {
	case 1:
		return false;
		break;
	case 2:
		reg.at(a) = b;

		pc++;
		break;
	case 3:
		reg.at(a) += b;
		reg.at(a) %= 1000;

		pc++;
		break;
	case 4:
		reg.at(a) *= b;
		reg.at(a) %= 1000;

		pc++;
		break;
	case 5:
		reg.at(a) = reg.at(b);

		pc++;
		break;
	case 6:
		reg.at(a) += reg.at(b);
		reg.at(a) %= 1000;

		pc++;
		break;
	case 7:
		reg.at(a) *= reg.at(b);
		reg.at(a) %= 1000;

		pc++;
		break;
	case 8:
		reg.at(a) = ram.at(reg.at(b));

		pc++;
		break;
	case 9:
		ram.at(reg.at(b)) = reg.at(a);

		pc++;
		break;
	case 0:
		if(reg.at(b) == 0) {
			pc++;
		} else {
			pc = reg.at(a);
		}

		break;
	}

	return true;
}

int main(int argc, char *argv[])
{
	string dummy;
	int ncases;

	cin>>ncases;

	// ignore two empty lines
	getline(cin, dummy);
	getline(cin, dummy);

	for(int n = 0; n < ncases; n++) {
		vector< int > reg(10), ram(1000);

		fill(reg.begin(), reg.end(), 0);
		fill(ram.begin(), ram.end(), 0);

		for(int i = 0; i < 1000; i++) {
			string str;

			getline(cin, str);
			if(str == "") {
				break;
			}

			istringstream iss(str);
			iss>>ram.at(i);
		}

		int executed = 1;
		int pc = 0;
		while(decode(pc, reg, ram)) {
			executed++;
		}

		if(n > 0) {
			cout<<endl;
		}
		cout<<executed<<endl;
	}

	return 0;
}
