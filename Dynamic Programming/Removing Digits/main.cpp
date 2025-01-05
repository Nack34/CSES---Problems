#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, v;
   cin >> n;
   long long big_number=999999999;
   vector<long long> cants(n+1, big_number);

   cants[0]=0;
   for (long long i=1; i<n+1; ++i){
      for (auto c:to_string(i))
         cants[i]=min(cants[i],cants[i-(c - '0')]+1);
   }
   
   cout << cants[n];

   return 0;
}