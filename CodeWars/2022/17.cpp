/**
 * author: DespicableMonkey
 * created: 3/4/2022
 **/ 

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void put(T output) { cout << output << '\n'; }
#define putr(__output) return void(put(__output))

long double round(double val, int plc) {
  return ceil(val * pow(10, plc)) / pow(10, plc);
}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout << fixed << showpoint;
  int width = 0, height = 0, depth = 0;
  char c; int a, b;
  cin >> c >> a >> b;
  width = a * 12 + b;
  cin >> c >> a >> b;
  height = a * 12 + b;
  cin >> c >> a >> b;
  depth = a * 12 + b;
  long long volume = width * height * depth;
  long double r = volume * 0.8, p = volume * 0.2;
  int rr, pp; 
  cin >> c >> rr;
  cin >> c >> pp;
   cout << setprecision(3);
  cout << "R " << round(r/46656,3) << " cu yd" << '\n';
  cout << "P " << round(p / 46656, 3) << " cu yd" << '\n';

  long double rrr = round(r / 46656, 3);
  long double ppp = round(p / 46656, 3);
   cout << setprecision(2);
  cout << "T " << round(rrr * rr + ppp * pp, 2) << " dollars"<< '\n';


  return 0;
}
