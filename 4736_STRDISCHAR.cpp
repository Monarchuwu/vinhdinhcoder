// STRDISCHAR

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
   string s;
   cin >> s;
   vector <long long> a(256, 0);
   long long dem = 0;
   for (long i = 0; i < s.size(); ++i) ++a[s[i]];
   for (long i = 0; i < 256; ++i) if (a[i] > 0) ++dem;
   if (dem % 2 == 1) cout << "NONO";
   else cout << "GIRL";
   return 0;
}
    