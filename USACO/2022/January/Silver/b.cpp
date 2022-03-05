

#include<bits/stdc++.h>

using namespace std;
int a[300047];
int N;
struct n{
  int lindex, rindex;
  int lval, rval;
  n *l = NULL;
  n *r = NULL;
};

int main () {
  cin >> N;
  for(int  i =0 ; i < N; ++i) cin >> a[i];

  long long ans = 0;
  
  vector<n> st;

  for(int i = 0; i < N-1; ++i) {
    n v;
    v.lindex = i;
    v.rindex = i+1;
    v.lval = a[i];
    v.rval = a[i+1];
    ans += 2;
    st.push_back(v);
  } 

  for(int i = 1; i < st.size(); ++i) {
    st[i-1].r = &st[i];
    st[i].l = &st[i-1];
  }

  n *head = &st[0];

  bool changed = 0;
  do {    
    changed = 0;
    n *cur = head;
    while(cur && cur->r) {
      if(cur->lval > cur->rval && cur->rval < cur->r->rval) {
        changed = 1;
        cur->rval = cur->r->rval;
        cur->rindex = cur->r->rindex;
        ans += (cur->rindex - cur->lindex + 1);
        cur->r = cur->r->r;
        if(cur->l)
          cur = cur->l;
      }
      else if(cur->r) cur = cur->r;
      else break;
    }
  } while(changed);
  cout << ans << '\n';

}
  
  
