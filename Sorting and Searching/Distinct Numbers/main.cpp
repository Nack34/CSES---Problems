#include <bits/stdc++.h>

using namespace std;

int main() {
   long long n;
   long long input;
   cin >> n;
   set<long long> s;
   for (long long i = 0; i < n; i++){
      cin >> input;
      s.insert(input);
   }
   cout << s.size();

   return 0;
}