#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, v;
   cin >> n;
   vector<vector<long long>> values(n,vector<long long>(n,0));
   vector<vector<long long>> cants(n,vector<long long>(n,0));
 
   for (long long i=0; i<n; ++i){
      for (long long j=0; j<n; ++j){
         cin >> c;
         if (c == '.') v = 1;
         else v = -1;
         values[i][j] = v;
      }  
   }
 
   if (values[0][0] == -1){
      cout << 0;
      return 0;
   }
 
   cants[0][0]=1;
   for (long long i=1; i<n; ++i){
      cants[i][0]= values[i][0]!=-1 ? cants[i-1][0] : 0;
   }
   for (long long i=1; i<n; ++i){
      cants[0][i]= values[0][i]!=-1 ? cants[0][i-1]  : 0;
   }
 
   for (long long i=1; i<n; ++i){
      for (long long j=1; j<n; ++j){
         if (values[i][j]!=-1) {
            cants[i][j]+=cants[i-1][j];
            cants[i][j]+=cants[i][j-1];
         } else { 
            cants[i][j]=0;
          }
         cants[i][j] = cants[i][j]% 1000000007;
      }  
   }
   
   cout << cants[n-1][n-1];
 
   /*cout << "\n";
   for (long long i=0; i<n; ++i){
      for (long long j=0; j<n; ++j){
         cout << cants[i][j] << ' ';
         cout << " -----  ";
      }  
      cout << "\n";
 
   }*/
 
   return 0;
}