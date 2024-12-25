#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   string linea;
   char prev;
   int max_cant = 0;
   int current_cant = 0;
   getline(cin, linea);
   linea+="J";
   for (char c : linea){
      if (c == prev){
         current_cant++;
      } else {
         current_cant++;
         max_cant = current_cant>max_cant ? current_cant : max_cant;
         current_cant = 0;
      }
      prev = c;
   }
 
   cout << max_cant;
 
   return 0;
