#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   int n, m, a, b;
   cin >> n >> m;

   stack<tuple<int,int>> s;  // Usamos una pila en lugar de una cola para DFS
   vector<int> state(n,0);
   vector<int> anterior(n, -1);

   vector<vector<int>> vecinos(n);
   for (int i=0; i<m; ++i){
      cin >> a >> b;
      vecinos[a-1].push_back(b-1);
      //vecinos[b-1].push_back(a-1);
   }

   for (int i=0; i<n;++i){
      if (state[i]!=0) continue;
      
      s.push({i,-1});
      while (!s.empty()) {
         auto [j,w] = s.top(); s.pop();
         if (state[j]!=0) continue;

         //cout << "Nodo actual: " << j+1 << "\n";
         state[j]=1;
         anterior[j]=w;

         for (auto v:vecinos[j]) {
               //cout << "vecino " << v+1 <<" \n";
            if (state[v]==1) { 

                //cout << "aceptado " << v+1 <<" \n";
                anterior[v] = j;
                vector<int> camino;
                camino.push_back(v+1);

                int cant = 2;
                int actual = j;
                camino.push_back(actual+1);
                while (anterior[actual] != j){
                    actual = anterior[actual];
                    ++cant;
                    camino.push_back(actual+1);
                }

                cout << cant << "\n";
                for (int k = camino.size() - 1; k >= 0; --k) {
                        cout << camino[k] << ' ';
                }
               return 0;

            }
            s.push({v,j}); 
         }
      }
      for (int i=0; i<n;++i){
         if (state[i] == 1) state[i] = 2;
      }
   }
   
   /*for (int i=0; i<n;++i){
      cout << n_steps[i] << ' ';
   }
   cout << "\n";
   for (int i=0; i<n;++i){
      cout << anterior[i] << ' ';
   }
   cout << "\n";*/

   cout << "IMPOSSIBLE";
   return 0;
}