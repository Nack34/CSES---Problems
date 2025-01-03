#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   char c;
   long long n, x, v;
   cin >> n >> x;
   
   // algoritmo recursivo cant(n,list): retorna la cantidad minima de monedas en list para llegar a sumar "n" 
   // caso base -> n=0 => return 0
   // caso no base -> values = pop(list); return min(cant(n-values)+1, cant(n,list))

   // algoritmo iterativo:
   // matriz de n por x
   // matriz[i][0]=0
   // matriz[i][x]=min(matriz[i-1][x-values[i]]+1, matriz[i-1][x])
   // 
   // 
   // 

   vector<vector<int>> matriz(n+1, vector<int>(x+1, -1));
   vector<int> values;

   values.push_back(0);
   while (cin >> v){
      values.push_back(v);
      if (cin.get(c) && c == '\n') break;
   }
   
   //matriz[i][0]=0 // ya hecho al crear la matriz
   for (long long i=1; i<n; i++){
      for (long long j=1; j<x; j++){
         if (j-values[i] ==0){
            matriz[i][j]=1;
         }
         else if (j-values[i] >0){
            long long valor_poniendola = matriz[i-1][j-values[i]];
            long long valor_sin_ponerla = matriz[i-1][j];

            if (valor_poniendola == -1 || valor_sin_ponerla == -1){
               matriz[i][j]=valor_poniendola == -1 ? valor_sin_ponerla : valor_poniendola;
            } else{
               matriz[i][j]=min(valor_poniendola+1, valor_sin_ponerla);
            }

         }else{
            matriz[i][j]=matriz[i-1][j];
         }
      }
   }
 
   cout << matriz[n-1][x-1];
   cout << "\n";

   for (long long i=0; i<n; i++){
      for (long long j=0; j<x; j++){
         cout << matriz[i][j] << ' ';
      }
      cout << "\n";
   }
 
   return 0;
}