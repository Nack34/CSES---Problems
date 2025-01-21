#include <bits/stdc++.h>
 
using namespace std;

tuple<long long, deque<int>> dfs_augmentation_path(unordered_map<int, unordered_map<int, long long>>& adj, int s, int t, int n){  
   int a, p;
   bool terminated = false;
   long long c_max = 1;
   vector<bool> visited(n, false);
   vector<int> prev(n, -1);
   stack<tuple<int, int>> stk; // current node, previo
   stk.push({s, s});
   while (!stk.empty()){
      tie(a, p) = stk.top(); stk.pop();
      if (visited[a]) continue;
      visited[a]=true;
      prev[a]=p;

      if (a == t) {
         terminated = true;
         break;
      }
      //cout << "current a: "<< a+1 << ", cur_c_max: " << cur_c_max << "\n";

      for (const auto& [b, cr]:adj[a]){ // destino, capacidad restante
         //cout << "vecino: "<< b+1 << ", cr: " << cr << "\n";
         if (!visited[b] && cr>0){
            //cout << "anotando vecino "<< b+1 << "\n";
            stk.push({b, a});
         }
      }
   }

   deque<int> path;
   if (!terminated) return {-1, path};

   int b = t;
   p = prev[b];
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


vector<tuple<int,int>> dfs_min_cut(unordered_map<int, unordered_map<int, long long>>& adj, int s, int t, int n){  
   int a;
   bool terminated = false;
   vector<bool> visited(n, false);
   stack<int> stk; // current node
   stk.push(s);
   while (!stk.empty()){
      a = stk.top(); stk.pop();
      if (visited[a]) continue;
      visited[a]=true;

      /*if (a == t) { // es imposible que esto pase ya que significa que todavia hay un augmentation_path
         return 
      }*/
      //cout << "current a: "<< a+1 << ", cur_c_max: " << cur_c_max << "\n";

      for (const auto& [b, cr]:adj[a]){ // destino, capacidad restante
         //cout << "vecino: "<< b+1 << ", cr: " << cr << "\n";
         if (!visited[b] && cr>0){
            //cout << "anotando vecino "<< b+1 << "\n";
            stk.push(b);
         }
      }
   }

   vector<tuple<int,int>> min_cut;

   for (const auto& [a, inner]:adj){
      for (const auto& [b, cr]:inner){ // destino, capacidad restante
         //cout << "vecino: "<< b+1 << ", cr: " << cr << "\n";
         if (visited[a] && !visited[b] && cr==0){
            //cout << "anotando vecino "<< b+1 << "\n";
            min_cut.push_back({a+1,b+1});
         }
      }
   }

   return min_cut;

}
  
int main() {
   int n, m, a, b;
   cin >> n >> m ;
   int s = 0;
   int t = n-1;

   unordered_map<int, unordered_map<int, long long>> adj; // origen -> (destino -> capacidad restante)

   for (int _=0; _<m;++_){
      cin >> a >> b;
      adj[a-1][b-1] = 1;
      adj[b-1][a-1] = 1;
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
   tie(c_max, path) = dfs_augmentation_path(adj, s, t, n);
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
      cout << "\n";*/
      //string pausar;
      //cin >> pausar;


      tie(c_max, path) = dfs_augmentation_path(adj, s, t, n);
   }
   cout << flow;

   vector<tuple<int,int>> min_cut = dfs_min_cut(adj, s, t, n);

   cout << "\n";
   for (auto [a,b]:min_cut){
      cout << a << ' ' << b << "\n";
   }
   
   return 0;
}