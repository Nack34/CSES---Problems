#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, p, max_p;
   cin >> n >> x;
   
   vector<long long> prices;
   while (cin >> p){
      prices.push_back(p);
      if (cin.get(c) && c == '\n') break;
   }
   sort(prices.begin(),prices.end());
   
   while (cin >> max_p){
      
      auto it = upper_bound(prices.begin(), prices.end(), max_p);

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