#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, v;
   cin >> n >> x;

   set<long long> values;
   vector<long long> cants(x+1, 0);

   while (cin >> v){
      values.insert(v);
      if (cin.get(c) && c == '\n') break;
   }

   cants[0]=0;
   for (long long i=1; i<x+1; ++i){
      auto it = values.upper_bound(i);
      while(it != values.begin()) {
         it--;
         v = *it;
         if (i-v == 0){
            cants[i]++;
         } else if (i-v > 0 and cants[i-v]>0){
            cants[i]+=cants[i-v];
         }
         cants[i] = cants[i]% 1000000007;
      }
   }
   
   cout << cants[x];
   
   cout << "\n";
   for (long long i=0; i<x+1; ++i){
      cout << i << ": " << cants[i] << '\n';
   }

   return 0;
}