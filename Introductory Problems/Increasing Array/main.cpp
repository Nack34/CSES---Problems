#include <bits/stdc++.h>

using namespace std;

int main() {
   long long n;
   long long input;
   cin >> n;
   long long max = -1;
   long long res = 0;

   for (long long i = 0; i < n; i++){
      cin >> input;
      if (max>input){
         res+=max-input;
      } else {
         max = input;
      }
   }
   cout << res;

   return 0;
}