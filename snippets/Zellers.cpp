#include <bits/stdc++.h>

using namespace std;

//Output day of the week given Date

string weekday[7] = {"Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday"};
string zellersAlgorithm(int day, int month, int year){
   int mon;
   if(month > 2)
      mon = month; //for march to december month code is same as month
   else{
      mon = (12+month); //for Jan and Feb, month code will be 13 and 14
      year--; //decrease year for month Jan and Feb
   }
   int y = year % 100; //last two digit
   int c = year / 100; //first two digit
   int w = (day + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
   w = w % 7;
   return weekday[w];
}

int main() {
    for(int i = 0; i < 100; ++i) {
        int N; cin >> N;
    cout << zellersAlgorithm(1, 1, N);
    }
}