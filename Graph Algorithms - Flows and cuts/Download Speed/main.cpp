#include <bits/stdc++.h>
 
using namespace std;

tuple<long long, deque<int>> min_augmentation_path(unordered_map<int, unordered_map<int, long long>>& adj, int s, int t, int n){  
   int a;
   long long cur_c_max;
   bool terminated = false;
   long long c_max;
   vector<bool> visited(n, false);
   vector<int> prev(n, -1);
   queue<tuple<int, long long>> q; // current node, cur_c_max (current capacidad max del camino)
   q.push({s, LONG_LONG_MAX});
   while (!q.empty()){
      tie(a, cur_c_max) = q.front(); q.pop();
      if (a == t) {
         c_max = cur_c_max;
         terminated = true;
         break;
      }
      //cout << "current a: "<< a+1 << ", cur_c_max: " << cur_c_max << "\n";

      for (const auto& [b, cr]:adj[a]){ // destino, capacidad restante
         //cout << "vecino: "<< b+1 << ", cr: " << cr << "\n";
         if (!visited[b] && cr>0){
            //cout << "anotando vecino "<< b+1 << "\n";
            visited[b]=true;
            prev[b]=a;
            q.push({b, min(cur_c_max, cr)});
         }
      }
   }

   deque<int> path;
   if (!terminated) return {-1, path};

   int b = t;
   int p = prev[b];
   path.push_front(b+1);
   while (b != s){
      adj[p][b]-=c_max;
      adj[b][p]+=c_max;
      b = p;
      p = prev[b];
      path.push_front(b+1);
   }
   //cout << "current max in function: " << c_max << "\n";

   return {c_max, path}; 
}
  
int main() {
   int n, m, a, b, c;
   cin >> n >> m ;
   int s = 0;
   int t = n-1;

   unordered_map<int, unordered_map<int, long long>> adj; // origen -> (destino -> capacidad restante)

   for (int _=0; _<m;++_){
      cin >> a >> b >> c;
      adj[a-1][b-1] += c;
      adj[b-1][a-1] += 0;
   }

   /*for (const auto& [a, inner]:adj){ // a = origen
      cout << "origen: "<< a+1 << "\n";
      for (const auto& [b, cr]:inner){ // b = destino, cr = capacidad restante
         cout << "destino: "<< b+1 << ", capacidad: " << cr <<" \n";
      }
   }*/

   long long flow = 0;
   long long c_max;
   deque<int> path;
   tie(c_max, path) = min_augmentation_path(adj, s, t, n);
   while (c_max!=-1 && path.size() != 0){
      /*cout << "path:  ";

      for (auto e:path){
         cout << e << ' ';
      }
      cout << "\n";*/
      flow += c_max;
      /*cout << "current max: " << c_max << ", current flow: " << flow;
      cout << "\n";
      cout << "\n";
      cout << "\n";
      string pausar;
      cin >> pausar;*/


      tie(c_max, path) = min_augmentation_path(adj, s, t, n);
   }
   cout << flow;
   
   return 0;
}