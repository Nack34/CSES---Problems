#include <bits/stdc++.h>

using namespace std;

int main() {
   long long n;
   string numeros;
   cin >> n;
   cin.ignore();
   getline(cin, numeros);
   for (int i=1; i<n+1; i++) {
      if (numeros.find(to_string(i)) == string::npos){
         cout << i;
         break;
      }
   }
}
