#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   int n, x, v;
   cin >> n >> x;
   vector<vector<int>> values(n,vector<int>(2,0));
   vector<vector<int>> cants(n+1,vector<int>(x+1,0));

   for (int i=0; i<n; ++i){
      cin >> v;
      values[i][0]=v;
   }
   for (int i=0; i<n; ++i){
      cin >> v;
      values[i][1]=v;
   }
   sort(values.begin(), values.end());
   
   /*for (int i=0; i<n; ++i){
      cout << values[i][0] << ": " << values[i][1] << " \n";
   }*/

   for (int i=1; i<n+1; ++i){
      for (int j=1; j<x+1; ++j){
         if (j-values[i-1][0] >= 0){
            cants[i][j]=max(cants[i-1][j], cants[i-1][j-values[i-1][0]]+values[i-1][1]);
         } else {
            cants[i][j]=cants[i-1][j];
         }
      }  
   }
   
   cout << cants[n][x];

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