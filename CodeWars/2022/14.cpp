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
string dict[30] = {
"N:Hey..:Pay attention to me. Right now.",
"N:...:I am annoyed you are not responding faster.",
"Y:we meeting up tonight?:I want to go out.",
"Y:....:I am too busy to respond right now, but I am dating you, so here's some ellipses.",
"N:we meeting up tonight?:I have nothing better to do, you free?",
"Y:have fun.:Do not do that if you want to stay in a relationship with me.",
"Y:oh.:I am not happy about your last message.",
"N:have fun.:I am annoyed you didn't invite me.",
"N:oh.:okay",
"N:Its fine:It's not fine",
"N:k.:That's not okay.",
"N:K.:Very well, but I am annoyed with you.",
"N:yup:Okay, I agree, but I'm not happy",
"N:yup.:yes and I am not happy with you",
"N:good for you:I am partially jealous, and partially annoyed by your bragging.",
"Y:<3u:I love you",
"N:I always love this story:Stop telling me variations of this same story, or I'm shaving your dog and painting him green.",
"N:<3:I approve",
"N:ha.:That was not funny.",
"Y:so,,,:I am about to start an incredibly long/complex story, which you have to listen to, because you love me.",
"Y:ha.:You get a pity laugh, because I <3 u",
"N:so,,,:I broke/lost/forgot something important to you, and I am about to lie about it.",
"Y:can we call instead?:I am angry enough that I want to yell at you.",
"N:Can I let you know?:I have no idea, need to research an answer first.",
"N:can we call instead?:It is going to take me too long to type this out.",
"N:lol jk:I am a jerk who tries to pretend my hurtful jokes aren't hurtful.",
"Y:You okay?:Worried about you.",
"N:sure- i guess.:I am angry now.",
"N:You okay???:You're either late, not responding, or just generally being a jerk Knock it off.",
"N:If you really want to:I am trying to come up with a reason not to, but I've got nothing"
};
  std::vector<string> split(const std::string &s, char delim) {
    std::vector<string> elems;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delim)) {
        elems.push_back(number);
    }
    return elems;
}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  map<string, string> tt, ff;
  for(string s : dict) {
    auto k = split(s, ':');
    if(k[0] == "N") ff[k[1]] = k[2];
    else {
      tt[k[1]] = k[2];
      ff[k[1]] = k[2];
    }
  }
  string name; getline(cin, name);
  string kk; getline(cin, kk);
  map<string, string> use = (kk == "YES" ? tt : ff);

  string ss;
  while(getline(cin, ss)) {
    if(ss == "END") break;
    auto pts = split(ss, ':');

    pts[1] = pts[1].substr(1);
    if(pts[0] != name && use.find(pts[0]) != use.end()) {
      cout << name << ": " << use[pts[0]] << '\n';
    } else {
      cout << ss << '\n';
    }
  }

  

  return 0;
}
