#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, v;
   cin >> n >> x;

   vector<long long> values;
   vector<long long> cants(x+1, 0);

   while (cin >> v){
      values.push_back(v);
      if (cin.get(c) && c == '\n') break;
   }

   cants[0]=0;
   for (long long i=1; i<x+1; ++i){
      for (auto v:values){
         if (i-v == 0){
            cants[i]++;
         } else if (i-v > 0 and cants[i-v]>0){
            cants[i]+=cants[i-v];
         }
         cants[i] = cants[i]% 1000000007;
      }
   }
   
   cout << cants[x];

   return 0;
}