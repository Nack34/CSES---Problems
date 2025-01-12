#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   int n, m, a, b;
   cin >> n >> m;

   queue<int> q;
   vector<bool> visited(n, false);
   vector<int> teams(n);

   vector<vector<int>> vecinos(n);
   for (int i=0; i<m; ++i){
      cin >> a >> b;
      vecinos[a-1].push_back(b-1);
      vecinos[b-1].push_back(a-1);
   }

   int i;
   for (i=0; i<n;++i){
      if (visited[i]) continue;
      
      int team = 1;
      visited[i] = true;
      teams[i] = team;
      q.push(i);
      while (!q.empty()) {
         int j = q.front(); q.pop();
         team = teams[j] == 1 ? 2 : 1;
         
         for (auto v:vecinos[j]) {
            if (visited[v] && teams[v]!=team) {
               cout << "IMPOSSIBLE";
                  
               return 0;
            }
            if (visited[v]) continue;
            visited[v] = true;
            teams[v]=team;
            q.push(v);
         }
      }
   }
   

   for (auto t:teams){
      cout << t << ' ';
   }

   return 0;
}