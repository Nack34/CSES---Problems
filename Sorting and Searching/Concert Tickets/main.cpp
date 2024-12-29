#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, p, max_p;
   cin >> n >> x;
   
   multiset<long long> prices;
   while (cin >> p){
      prices.insert(p);
      if (cin.get(c) && c == '\n') break;
   }
   
   while (cin >> max_p){
      
      auto it = prices.upper_bound(max_p);

      if(it == prices.begin()) {
         cout << -1 << "\n";
      } else {
         it--;
         if(*it <= max_p) {
            cout << *it << "\n";
            prices.erase(it);
         } else {
            cout << -1 << "\n";
         }
      }
 
      if (cin.get(c) && c == '\n') break;
   }
 
   return 0;
}