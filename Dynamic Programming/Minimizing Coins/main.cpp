#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, v;
   cin >> n >> x;

   long long big_number = 9999999;
   vector<long long> values;
   vector<long long> cants(x+1, big_number);

   values.push_back(0);
   while (cin >> v){
      values.push_back(v);
      if (cin.get(c) && c == '\n') break;
   }

   cants[0]=0;
   for (long long i=1; i<x+1; ++i){
      for (auto v:values){
         if (i-v >= 0){
            cants[i]=min(cants[i], cants[i-v]+1);
         }
      }
   }
   
   long long res = cants[x] < big_number ? cants[x] : -1;
   cout << res;
   cout << "\n";
 
   return 0;
}