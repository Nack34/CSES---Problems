#include <bits/stdc++.h>

using namespace std;

int main() {
   char c;
   long long n, x, p;
   cin >> n >> x;
   long long res = 0;
   
   map<long long, long long, greater<long long>> cant_pesos;

   while (cin >> p) {
      cant_pesos[p]++;
      if (cin.get(c) && c == '\n') break;
   }

   for (auto it = cant_pesos.begin(); it != cant_pesos.end(); ++it) {
      long long peso = it->first;

      if (it->second > 0) {
         if (peso < x) {
            long long complement = x - peso < peso ? x - peso : peso;
            auto jt = cant_pesos.find(complement);
            if (jt == cant_pesos.end()) {
               cant_pesos[complement]=0;
               jt = cant_pesos.find(complement);
            }
            
            if (jt->first == peso && jt->first+peso<=x){
               res+=it->second/2;
               it->second=it->second%2;
               jt++;
            }

            while (jt != cant_pesos.end() && it->second !=0) {
               if (jt->second>0){
                  long long cant_pares_logrados = min(it->second, jt->second);
                  res += cant_pares_logrados;
                  it->second -= cant_pares_logrados;
                  jt->second -= cant_pares_logrados;
               }
               jt++;
            }
         }

         res += it->second;
         it->second = 0;
      }
   }

   cout << res;

   return 0;
}
