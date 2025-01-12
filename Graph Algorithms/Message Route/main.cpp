#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   int n, m, a, b;
   cin >> n >> m;

   queue<int> q;
   vector<bool> visited(n, false);
   vector<int> anterior(n, -1);

   vector<vector<int>> vecinos(n);
   for (int i=0; i<m; ++i){
      cin >> a >> b;
      vecinos[a-1].push_back(b-1);
      vecinos[b-1].push_back(a-1);
   }

   int i=n-1;
   visited[i] = true;
   q.push(i);
   while (!q.empty()) {
      i = q.front(); q.pop();
      if (i == 0) {
         break;
      }
      
      for (auto v:vecinos[i]) {
         if (visited[v]) continue;
         visited[v] = true;
         anterior[v] = i;
         q.push(v);
      }
      
   }

   if (i != 0) {
      cout << "IMPOSSIBLE";
      return 0;
   }

   string camino;
   int cant = 1;
   i=0;
   while (true){
      camino+= to_string(i+1) + ' ';
      if (i == n-1) break;
      ++cant;
      i = anterior[i];
   }
 
   cout << cant << "\n" << camino;
 
   return 0;
}