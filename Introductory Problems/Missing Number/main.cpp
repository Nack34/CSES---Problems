#include <bits/stdc++.h>

using namespace std;

int main() {
   long long n;
   cin >> n;

   // Calcular la suma esperada
   long long totalSum = n * (n + 1) / 2;

   long long actualSum = 0;
   for (int i = 0; i < n - 1; ++i) {
      int num;
      cin >> num;
      actualSum += num;
   }

   // El número faltante es la diferencia entre la suma esperada y la suma real
   cout << totalSum - actualSum << endl;

   return 0;
}
