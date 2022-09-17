#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   long long n;
   cin >> n;
   for (long long i = 3; i <= n; ++i)
      for (long long j = i; j <= n; ++j)
      {
         double cp = sqrt(i * i + j * j);
         if (cp == (long long)cp) cout << i << ' ' << j << '\n';
      }
   return 0;
}
