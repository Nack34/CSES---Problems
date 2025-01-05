#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, m, v;
   cin >> n >> m;
   vector<long long> values(n,0);

   for (long long i=0; i<n; ++i){
      cin >> v;
      values[i]=v;
   }
   long long cants=1;
   for (long long i=1; i<n; ++i){
      if (values[i] != 0) continue;
      long long cant = 0;
      
      if (i-1 < 0 || i+1 > n) cant = 3;
      else {
         for (long long j=-1;j<2;++j){
            long long posible_value = values[i-1]+j;
            if (posible_value>m) continue;
            if (posible_value-values[i+1] > 1 || posible_value-values[i+1] < -1 ) continue;
            
            cant++;
         }
      }
      cout << cant << ' ';

      cants*=cant;
      cants = cants % 1000000007;
   }
   
   cout << cants;

   /*cout << "\n";
   for (int i=0; i<n+1; ++i){
      for (int j=0; j<x+1; ++j){
         cout << cants[i][j] << ' ';
         cout << " -----  ";
      }  
      cout << "\n";

   }*/

   return 0;
}