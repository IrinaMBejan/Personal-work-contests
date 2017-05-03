#include <iostream>
#include <set>
using namespace std;

struct nr
{
    bool operator() (const int&a, const int&b) const{return a>b;};
};
int main ()
{
   set<int, nr> myset;
   set<int, nr>::iterator itlow,itup;

  for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

  /*itlow=myset.lower_bound (31);                //       ^
  itup=myset.upper_bound (59);                 //                   ^

  myset.erase(itlow,itup);                     // 10 20 70 80 90
*/
   cout << "myset contains:";
  for ( set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
     cout << ' ' << *it;
   cout << '\n';

  return 0;
}
