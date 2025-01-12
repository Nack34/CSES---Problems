#include <bits/stdc++.h>
 
using namespace std;
 
 
vector<int> pre;
vector<int> len;
 
int find(int x) { // find representative
   while (x != pre[x]) x = pre[x];
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
   int n, m, a, b;
   cin >> n >> m;
   pre.resize(n, 0);
   len.resize(n, 0);
 
   for (int i = 0; i < n; i++) {
      pre[i] = i;
      len[i] = 1;
   }
 
   for (int _=0; _<m; ++_){
      cin >> a >> b;
      unite(a-1,b-1);
   }
 
   set<int> distincts_sets;
 
   for (int i=0; i<n; ++i){
         distincts_sets.insert(find(i));
   }
 
   cout << distincts_sets.size() - 1;
   cout << "\n";

   auto it = distincts_sets.begin();
   auto prev = it;
   ++it;  

   while (it != distincts_sets.end()) {
      cout << *prev + 1 << ' ' << *it + 1 << "\n";  
      prev = it;
      ++it;
   }
   
   return 0;
}