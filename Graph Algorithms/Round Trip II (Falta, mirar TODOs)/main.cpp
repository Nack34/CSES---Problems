#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
   int n, m, a, b;
   cin >> n >> m;

   stack<tuple<int,int,int>> s;  // Usamos una pila en lugar de una cola para DFS
   vector<bool> visited(n, false);
   vector<int> visitados;
   vector<int> anterior(n, -1);
   vector<int> n_steps(n, -1);

   vector<vector<int>> vecinos(n);
   for (int i=0; i<m; ++i){
      cin >> a >> b;
      vecinos[a-1].push_back(b-1);
      //vecinos[b-1].push_back(a-1);
   }

   for (int i=0; i<n;++i){
      if (visited[i]) continue;
      
      s.push({i,-1, 0});
      while (!s.empty()) {
         auto [j,w,n_step] = s.top(); s.pop();
         if (visited[j]) continue;

         //cout << "Nodo actual: " << j+1 << "\n";
         visited[j] = true;
         visitados.push_back(j);
         n_steps[j] = n_step+1;
         anterior[j]=w;

         for (auto v:vecinos[j]) {
                //cout << "vecino " << v+1 <<" \n";
            if (visited[v] && n_steps[j]-n_steps[v]>=1/*2*/) { 
               //TODO: Fix Test 17: el problema es que el grafo es dirigido, entonces marco 1 como visitado y le pongo el n_step, y despues cuando llego a 3, me fijo "el vecino 1 esta visitado y tiene un nstep con diferencia? -> SI" y ahi esta el error
               //TODO: Fix Test 15: seguramente es lo mismo que el test 17 

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
            s.push({v,j,n_steps[j]}); 
         }
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