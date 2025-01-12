#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;

    stack<tuple<int, int>> s;  // Usamos una pila en lugar de una cola para DFS
    vector<bool> visited(n, false);
    vector<int> padre(n, -1);  // Para rastrear el padre de cada nodo
    vector<int> n_steps(n, -1);

    vector<vector<int>> vecinos(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        vecinos[a - 1].push_back(b - 1);
        vecinos[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        s.push({i, 0});
        while (!s.empty()) {
            auto [j, n_step] = s.top();
            s.pop();
            if (visited[j]) continue;

            visited[j] = true;
            n_steps[j] = n_step;

            for (auto v : vecinos[j]) {
                if (!visited[v]) {
                    padre[v] = j;
                    s.push({v, n_step + 1});
                } else if (padre[j] != v && n_steps[j] - n_steps[v] >= 2) {
                    // Encontramos un ciclo de longitud al menos 3

                    // Reconstruir el camino desde j hasta v
                    vector<int> ciclo;
                    int current = j;
                    while (current != v) {
                        ciclo.push_back(current + 1);
                        current = padre[current];
                    }
                    ciclo.push_back(v + 1);

                    // Imprimir el ciclo
                    cout << ciclo.size()+1 << "\n";
                    for (int k = ciclo.size() - 1; k >= 0; --k) {
                        cout << ciclo[k] << ' ';
                    }
                    cout << v+1 << ' ';
                    cout << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}