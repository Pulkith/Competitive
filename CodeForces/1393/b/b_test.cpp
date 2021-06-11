#include<bits/stdc++.h>

using namespace std;

int main() {
    multiset<int, greater<int>> ms;

    for(int i = 0; i < 100; ++i)
        ms.insert(1);
   cout << ms.size() << '\n';
   ms.erase(ms.lower_bound(1));
   cout << ms.size() << '\n';

}