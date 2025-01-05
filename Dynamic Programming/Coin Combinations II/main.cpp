#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, v, cant;
   cin >> n >> x;

   set<long long> values;
   vector<map<long long,long long>> cants(x+1);

   while (cin >> v){
      values.insert(v);
      if (cin.get(c) && c == '\n') break;
   }

   for (long long i=1; i<x+1; ++i){
      auto it = values.upper_bound(i);
      while(it != values.begin()) {
         it--;
         v = *it;
         if (i-v == 0){
            cants[i][v]=1;
         } else if (i-v > 0){
            auto siguiente = cants[i-v].upper_bound(v);

            long long suma = accumulate(cants[i-v].begin(), siguiente, 0,[](long long acc, const pair<long long,long long>& p) {
                                                      return (acc + p.second)% 1000000007;
                                                   });
            if (suma>0){
               cants[i][v]=suma;
            }
         }
      }
   }
   
   long long res = accumulate(cants[x].begin(), cants[x].end(), 0,[](int acc, const pair<int,int>& p) {
                                             return acc + p.second;
                                          });
   cout << res;

   return 0;
}