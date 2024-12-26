#include <bits/stdc++.h>

using namespace std;

int main() {
   char c;
   long long n, m, k, ab;
   cin >> n >> m >> k;
   
   vector<long long> desired_sizes;
   while (cin >> ab){
      desired_sizes.push_back(ab);
      if (cin.get(c) && c == '\n') break;

   }
   
   vector<long long> v;
   while (cin >> ab){
      v.push_back(ab);
      if (cin.get(c) && c == '\n') break;

   }
   sort(v.begin(),v.end());

   long long cant = 0;
   for (long long elem : desired_sizes){
      long long desired = elem;
      long long min = desired - k;
      long long max = desired + k;
         
      auto i = size_t(0);
      for (size_t b = v.size() / 2; b >= 1; b /= 2) {
         while (true){
            while (i + b < v.size() && v[i + b] !=-1 && v[i + b] < min) i += b;
            
            if (i < v.size() && v[i+1] < min && v[i + b] ==-1) i++;
            else break;
 
         }
      }
      if (i < v.size() && v[i] < min){
         i++;
      }
      if (i < v.size() && (v[i] >= min && v[i] <= max)) {
         cant++;
         v[i] = -1;
      }

   }

   cout << cant;

   return 0;
}