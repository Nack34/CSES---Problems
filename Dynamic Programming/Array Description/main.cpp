#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, m, v;
   cin >> n >> m;
   vector<long long> values;

   for (long long i=0; i<n; ++i){
      cin >> v;
      values.push_back(v); 
   }

   n = values.size();
   vector<vector<long long>> cants(n+1,vector<long long>(m+1, 0));

   for (long long i=1; i<m+1; ++i){
      cants[0][i]=1;
   }
   for (long long i=1; i<n+1; ++i){
      for (long long j=1; j<m+1; ++j){
         if (values[i-1] != 0 && abs(values[i-1]-j)<=1){
            //cout << "i: " << i << ", j: " << j << ", values[i-1]: " << values[i-1] << ", abs(values[i-1]-j): " << abs(values[i-1]-j) << "\n";
            cants[i][j]=cants[i-1][values[i-1]];
         } else if (values[i-1] == 0){
            cants[i][j]=cants[i-1][j-1]+cants[i-1][j];
            if (j+1 < m+1) {cants[i][j]+=cants[i-1][j+1];}
         }
         cants[i][j]= cants[i][j]%1000000007;
      }
   }
   long long res=0;
   if (values[n-1] == 0){
      for (long long i=0; i <cants[n-1].size(); ++i){
         res=(res+cants[n-1][i])%1000000007;
      }
   } else {
      res=*max_element(cants[n].begin(), cants[n].end());
   }

   cout << res;
   
   /*cout << "\n";
   cout << "LAST VALUE: " <<  values[n-1];
   cout << "\n";
   cout << n << " " << m;
   cout << "\n";
   for (int i=0; i<n+1; ++i){
      for (int j=0; j<m+1; ++j){
         cout << cants[i][j] << ' ';
         cout << " -----  ";
      }  
      cout << "\n";

   }*/

   return 0;
}