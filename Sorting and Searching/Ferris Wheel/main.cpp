#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, p, max_p, min_p;
   cin >> n >> x;
   long long res = 0;
   
   vector<long long> pesos;
   while (cin >> p){
      pesos.push_back(p);
      if (cin.get(c) && c == '\n') break;
   }
   sort(pesos.begin(),pesos.end());

   max_p=pesos.size()-1;
   min_p=0;
   while (true){
      if (max_p == min_p){
         res++;
         break;
      }
      else if (max_p < min_p) break;

      if (pesos[max_p] + pesos[min_p] <= x){
         min_p++;
      }
      max_p--;
      res++;
   }
 
   cout << res;
 
   return 0;
}