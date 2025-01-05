#include <bits/stdc++.h>
 
using namespace std;
 

int main() {
   char c;
   long long n, x, v;
   cin >> n >> x;

   vector<int> values;
   vector<vector<int>> cants(n + 1, vector<int>(x + 1, 0));
   
   while (cin >> v){
      values.push_back(v);
      if (cin.get(c) && c == '\n') break;
   }
   sort(values.begin(),values.end());

   for (long long i = 0; i < n+1; ++i) {
        cants[i][0] = 1; 
    }

    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= x; ++j) {
            if (j - values[i - 1] >= 0) {   
               cants[i][j] = cants[i][j - values[i - 1]];
               cants[i][j] = cants[i][j]% 1000000007;

            }
            cants[i][j] += cants[i - 1][j];  
            cants[i][j] = cants[i][j]% 1000000007;
        }
    }

   cout << cants[n][x];

   return 0;
}