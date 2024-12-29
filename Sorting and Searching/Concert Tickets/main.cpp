#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, p, max_p, price_to_pay;
   cin >> n >> x;
   
   vector<long long> prices;
   while (cin >> p){
      prices.push_back(p);
      if (cin.get(c) && c == '\n') break;
   }
   sort(prices.begin(),prices.end());
   
   while (cin >> max_p){
      price_to_pay = -1;
 
      long long pos_act = 0;
      for (long long i=prices.size()/2; i >=1; i/=2){
         while (pos_act + i < prices.size() && prices[pos_act + i] <= max_p) pos_act += i;
      }
      if (pos_act < prices.size() && prices[pos_act] <= max_p){
         price_to_pay = prices[pos_act];
         prices.erase(prices.begin() + pos_act);
      }
 
      cout << price_to_pay << "\n";
      if (cin.get(c) && c == '\n') break;
   }
 
   return 0;
}