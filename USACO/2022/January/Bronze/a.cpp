

#include<bits/stdc++.h>

using namespace std;

string grid[3], guess[3];
int fg[26], fa[26];

int main () {
  for(int i = 0; i < 3; ++i)
    cin >> grid[i];
  for(int i = 0; i < 3; ++i)
    cin >> guess[i];
  int co = 0, ye = 0;
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      if(grid[i][j] == guess[i][j]) ++co;
      else {
        fg[grid[i][j] - 'A']++;
        fa[guess[i][j] - 'A']++;
      }
    }
  }

  for(int i = 0; i < 26; ++i)
    ye += min(fa[i], fg[i]);

  cout << co << '\n' << ye << '\n';



}
