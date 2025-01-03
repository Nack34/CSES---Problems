#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   long long n;
   cin >> n;
   
   // funcion recursiva count(n), retorna la cantidad de sumas posibles de dados de 6 caras
   // caso base -> n == 0 => return 0
   // else: return count(n-6)+count(n-5)+count(n-4)+count(n-3)+count(n-2)+count(n-1)+1

   // funcion iterativa: lista, con posicion en 0 == 0
   // for i= 1 a n+1:
   // for j= 1 a 6+1:
   // if i-j>0:
   //    lista[i]+=lista[i-j]
   // lista[i]++

   vector<long long> cants(n+1);
   cants[0]=1;
   for (long long i=1; i<n+1; ++i){
      for (long long j=1; j<7; ++j){
         if (i-j >= 0){
           cants[i]+=cants[i-j];
         }
      }
      cants[i]=cants[i]% 1000000007;
   }

   cout << cants[n]; 
   return 0;
}