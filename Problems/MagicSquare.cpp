#include "std.h"

/*
Magic Square Requirements
  - Middle must always be 5
  - Corners must be even
  - Sum of each row must be 15

  only 8 possible magic squares - hardcoded
*/

using namespace std;

int magic_mat[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, 
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},  
};
int formingMagicSquare(vector<vi> s) {
  int mc = INF;

  for(int i = 0; i < 8; ++i) {
    int cc = 0;
    for(int j = 0; j < 3; ++j) {
      for(int k = 0; k < 3; ++k) {
        cc += abs(magic_mat[i][j][k] - s[j][k]);
      }
    }

    mc = fmin(mc, cc);

  }

  return mc;

}

int main() {
    
}