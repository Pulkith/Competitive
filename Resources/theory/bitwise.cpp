#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>

using namespace std;


int main () {
   /**
    * Source: https://www.youtube.com/watch?v=xXKL9YBWgCY
    * 
    * x << k is the same as x * 2^k
    * x >> k is the same as floor(x / (2^k))
    * 
    * 16 == 10000 == 1<<4 == 2^4
    * 
    * (some power of 2) & (some number) can only be 2 numbers. Either (the power of 2) or 0. (since the only bit on in 2^x is the first bit). With this
    * you can check wether a bit in a number is on or off(if number * (1<<(index from right, x)) == (1<<x), then the bit is on)
    * psuedo to print "on" bits
    * for(i, 0, 30)
    *   if(x & (1<<i) != 0)
    *       print(i)
    * 
    * 
    * Parity check(i&1) is the same as (i%2==1 
    * 
    * in c++ you can put LL next to i to cast it to int to prevent overflow from shift. i.e (1LL << i)
    * alternately, to always prevent overflow you can instead check
    * (x >> i)&1
    * 
    * 
    * 
    */ 

   //Subset sum
   //give n numbers(1 <= n <= 20) check if there is a subset that equals a target S(subsets must have distinct numbers i.e. no duplicates)
   // In bitmasks, index 0 is the last(right-most element)
   // number of subsetss = 2^N
   
}