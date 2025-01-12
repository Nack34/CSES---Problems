#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   char c;
   int n, m;
   int iA, jA;
   int iB, jB;
   cin >> n >> m;

   queue<tuple<int,int>> q;
   vector<vector<bool>> visited(n, vector<bool>(m, false));
   vector<vector<string>> direction(n, vector<string>(m, "#"));

   vector<vector<bool>> map(n, vector<bool>(m, false));
   for (int i=0; i<n; ++i){
      for (int j=0; j<m; ++j){
         cin >> c;
         if (c != '#') map[i][j]=true;
         if (c == 'A') {iA = i; jA=j;}
         if (c == 'B') {iB = i; jB=j;}
      }
   }

   int i=iB;
   int j=jB;

   visited[i][j] = true;
   q.push({i, j});
   while (!q.empty()) {
      tie(i,j) = q.front(); q.pop();
      //cout << "Current i: " << i << ", Current j: " << ' ' << j << "\n";

      
      if (iA == i && jA == j) {
         cout << "YES" << "\n";
         //cout << iA << ' ' << i << " - " << jA << ' ' << j << "\n";
         break;
      }

      for (int k=-1; k<2; k+=2) {
         if (i+k >= n || i+k<0) continue;
         if (visited[i+k][j] || !map[i+k][j]) continue;
         visited[i+k][j] = true;
         direction[i+k][j] = k==-1 ? "D" : "U";
         q.push({i+k, j});
      }
      
      for (int w=-1; w<2; w+=2) {
         if (j+w >= m || j+w<0) continue;
         if (visited[i][j+w] || !map[i][j+w]) continue;
         visited[i][j+w] = true;
         direction[i][j+w] = w==-1 ? "R" : "L";
         q.push({i, j+w});
      }
      
   }

   if (iA != i || jA != j) {
      cout << "NO" << "\n";
      //cout << iA << ' ' << i << " - " << jA << ' ' << j << "\n";
      return 0;
   }

   
   
   /*cout << "\n";
   for (int q=0; q<n; ++q){
      for (int e=0; e<m; ++e){
         cout << direction[q][e] << ' ';
      }
      cout << "\n";
   }*/





   string camino;
   int cant = 0;
   i=iA;
   j=jA;
   while (true){
      if (i == iB && j == jB) break;
      
      ++cant;
      camino+=direction[i][j];
      if (direction[i][j] == "L") --j;
      else if (direction[i][j] == "R") ++j;
      else if (direction[i][j] == "D") ++i;
      else if (direction[i][j] == "U") --i;
   }
 
   cout << cant << "\n" << camino;
   
   return 0;
}