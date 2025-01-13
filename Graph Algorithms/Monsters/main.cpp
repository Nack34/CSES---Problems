#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   char c;
   int n, m;
   int big_number = INT_MAX;
   cin >> n >> m;
   
   tuple<int,int> hero;
   vector<tuple<int,int>> monsters;
   vector<tuple<int,int>> exits;

   vector<vector<bool>> map(n, vector<bool>(m, false));
   vector<vector<int>> min_monster_distance(n, vector<int>(m, big_number));
   for (int i=0; i<n; ++i){
      for (int j=0; j<m; ++j){
         cin >> c;
         if (c != '#') map[i][j]=true;
         if (c != '#' && (i==0 || i==n-1 || j==0 || j==m-1)) exits.push_back({i,j});
         if (c == 'A') hero = {i,j};
         if (c == 'M') monsters.push_back({i,j});
      }
   }
   auto [iA,jA] = hero;
   
   queue<tuple<int, int, int>> q;
   vector<vector<bool>> visited;
   visited = vector<vector<bool>>(n, vector<bool>(m, false));

   for (auto mon:monsters){
      auto [i,j] = mon;
      q.push({i, j, 0});
      visited[i][j] = true;
   }

   while (!q.empty()) {
      auto[i,j,current_distance] = q.front(); q.pop();
      min_monster_distance[i][j] = min(current_distance,min_monster_distance[i][j]);
      ++current_distance;

      for (int k=-1; k<2; k+=2) {
         if (i+k >= n || i+k<0) continue;
         if (visited[i+k][j] || !map[i+k][j] || current_distance>=min_monster_distance[i+k][j] || (i==iA && j==jA)) continue;
         visited[i+k][j] = true;
         q.push({i+k, j, current_distance});
      }
      
      for (int w=-1; w<2; w+=2) {
         if (j+w >= m || j+w<0) continue;
         if (visited[i][j+w] || !map[i][j+w] || current_distance>=min_monster_distance[i][j+w] || (i==iA && j==jA)) continue;
         visited[i][j+w] = true;
         q.push({i, j+w, current_distance});
      }
      
   }
      
   /*cout << "\n";
   for (int i=0; i<n; ++i){
      for (int j=0; j<m; ++j){
         if (min_monster_distance[i][j]!=big_number)
            cout << min_monster_distance[i][j] << ' '; 
         else{
            cout << "#" << ' '; 
         }
      }
      cout << "\n";
   } */

   // TODO: Recorrer desde el hero hasta algun exit, si llego entonces imprimo el camimo
   // si me quedo sin elementos en la cola, entonces es imposible
   // solo agrego elementos a la cola si no son # y si la distancia mia es menor que la de la minima distancia del minotauro


   visited = vector<vector<bool>>(n, vector<bool>(m, false));
   vector<vector<string>> direction(n, vector<string>(m, "#"));
   visited[iA][jA] = true;
   q.push({iA, jA, 0});
   while (!q.empty()) {
      auto[i, j, distance] = q.front(); q.pop();
      
      for (auto e:exits){
         auto [iE,jE] = e;
         if (i != iE || j != jE) continue;

         // SE LOGRO LLEGAR!!
         cout << "YES" << "\n";
         cout << distance << "\n";
         string camino = "";
         while (true){
            if (i == iA && j == jA) break;
            camino= direction[i][j]+camino;
            
            if (direction[i][j] == "R") --j;
            else if (direction[i][j] == "L") ++j;
            else if (direction[i][j] == "U") ++i;
            else if (direction[i][j] == "D") --i;
         }
         cout<<camino;
         return 0;

      }

      ++distance;
      for (int k=-1; k<2; k+=2) {
         if (i+k >= n || i+k<0) continue;
         if (visited[i+k][j] || !map[i+k][j] || distance>=min_monster_distance[i+k][j]) continue;
         visited[i+k][j] = true;
         direction[i+k][j] = k==-1 ? "U" : "D";
         q.push({i+k, j, distance});
      }
      
      for (int w=-1; w<2; w+=2) {
         if (j+w >= m || j+w<0) continue;
         if (visited[i][j+w] || !map[i][j+w] || distance>=min_monster_distance[i][j+w]) continue;
         visited[i][j+w] = true;
         direction[i][j+w] = w==-1 ? "L" : "R";
         q.push({i, j+w, distance});
      }
      
   }

   cout << "NO" << "\n";
   
   return 0;
}