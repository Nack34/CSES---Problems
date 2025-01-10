#include <bits/stdc++.h>
 
using namespace std;
 
 
vector<int> pre;
vector<int> len;
 
int find(int x) { // find representative
   int buscado = x;
   while (x != pre[x]) x = pre[x];
   pre[buscado]=x;
   return x;
}
 
bool same(int a, int b) { // checks whether elements a and b belong to the same set
   return find(a) == find(b);
}
 
void unite(int a, int b) { // joins the sets that contain elements a and b
   a = find(a);
   b = find(b);
   if (a == b) return;
   if (len[a] < len[b]) swap(a,b);
   len[a] += len[b];
   pre[b] = a;
}
 
int main() {
   char c;
   int n, m;
   cin >> n >> m;
   pre.resize(n * m, 0);
   len.resize(n * m, 0);
 
   for (int i = 0; i < n; i++) {
      pre[i] = i;
      len[i] = 1;
   }
 
   vector<vector<bool>> map(n, vector<bool>(m, false));
   for (int i=0; i<n; ++i){
      for (int j=0; j<m; ++j){
         cin >> c;
         if (c == '.') map[i][j]=true;
      }
   }
 
   for (int i=0; i<n; ++i){
      for (int j=0; j<m; ++j){
         if (map[i][j] && i+1<n && map[i+1][j]) unite((i%n)+j, ((i+1)%n)+j);
         if (map[i][j] && j+1<m && map[i][j+1]) unite((i%n)+j, ((i)%n)+j+1);
      }
   }
 
   set<int> distincts_sets;
 
   for (int i = 0; i <= n; i++){
      distincts_sets.insert(find(i));
   }
 
   cout << distincts_sets.size();
   
   return 0;
}