#include <bits/stdc++.h>

using namespace std;

int main() {
   char c;
   long long n, x, p;
   cin >> n >> x;
   long long res = 0;
   
   vector<long long> cant_pesos(200000, 0);
   long long max_peso = 0;
   while (cin >> p){
      max_peso = p>max_peso ? p : max_peso;
      cant_pesos[p]++;
      if (cin.get(c) && c == '\n') break;
   }

   for (long long i=max_peso; i>0; i--){
      if (cant_pesos[i] != 0){
         if (i < x){
            long long j = x-i <= i ? x-i : i;

            if (j == i){
               res+=cant_pesos[i]/2;
               cant_pesos[i]=cant_pesos[i]%2;
            }
            
            while (j>0 && cant_pesos[i] != 0){
               if (cant_pesos[j]>0){
                  if (cant_pesos[j] > cant_pesos[i]){
                     res+=cant_pesos[i];
                     cant_pesos[j]-=cant_pesos[i];
                     cant_pesos[i]=0;
                  } else{
                     res+=cant_pesos[j];
                     cant_pesos[i]-=cant_pesos[j];
                     cant_pesos[j]=0;
                  }
               }
               j--;
            }
         }
         res+=cant_pesos[i];
         cant_pesos[i]=0;
      }
   }

   cout << res;

   return 0;
}