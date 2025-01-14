#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   //ifstream input("input.txt");  // Este archivo simula la entrada estándar (cin)
   //ofstream output("output.txt"); // Este archivo simula la salida estándar (cout)

   // Redirigir cin y cout a los archivos
   //cin.rdbuf(input.rdbuf());
   //cout.rdbuf(output.rdbuf());




   long long n, m, a, b, c;
   cin >> n >> m;

   vector<vector<tuple<long long, long long>>> adj(n);

   for (long long i=0; i<m; ++i){
      cin >> a >> b >> c;
      adj[a-1].push_back({b-1,c});
   }
   vector<bool> visited(n,false);
   vector<long long> distance(n, LLONG_MAX);
   
   priority_queue<tuple<long long,long long>> q;
   distance[0] = 0;
   q.push({0,0});
   while (!q.empty()) {
      auto [z, a] = q.top(); q.pop();
      if (visited[a]) continue;
      visited[a] = true;
      for (auto v : adj[a]) {
         auto [b,w] = v;
         if (distance[a]+w < distance[b]) {
            distance[b] = distance[a]+w;
            q.emplace(-distance[b],b);
         }
      }
   }


   for (long long i=0; i<n; i++){
      cout << distance[i] << ' ';
   }
   
   return 0;
}