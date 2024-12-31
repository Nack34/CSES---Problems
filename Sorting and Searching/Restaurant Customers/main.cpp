#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   long long n, a, b;
   cin >> n;
   
   map<long long, long long> time;
   while (cin >> a >> b){
      time[a]++;
      time[b+1]--;
   }

   long long prev = 0;
   long long max_time = 0;

   for (auto& elem : time) {
      prev += elem.second;  
      max_time = max(max_time, prev);
   }

   cout << max_time << "\n"; 
   return 0;
}