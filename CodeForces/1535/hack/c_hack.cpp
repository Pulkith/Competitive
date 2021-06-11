#include "bits/stdc++.h"
using namespace std;
#define el "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
typedef long double ld;
//   int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
    
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
	cin.ignore();
	while (t--)
	{
	    string s,temp;
	    cin >> s;
	    temp=s;
	    vector<ll> pos,neg;
	    int i=1;
	    ll x=1;
	    int count =0;
	    while(i<s.length())
	    {
	       
	        
	        
	        if((s[i-1]=='0' && s[i]=='0') || (s[i-1]=='1' && s[i]=='1'))
	        {
	            pos.push_back(x);
                x=0;
                if(temp[i-1]=='?')
                {
                    x+=count;
                    neg.push_back(count);
                }
	        }
	        else{
	            if(s[i-1]=='1' && s[i]=='?')
	            s[i]='0';
	            
	            if(s[i-1]=='0' && s[i]=='?')
	            s[i]='1';
	        }
	        
	        if(temp[i]=='?')
	        count++;
	        else
	        count=0;
	        
	        
	        x++;
	        i++;
	        
	        
	    }
	    pos.push_back(x);
	    ll ans=0;
	    for(int j=0;j<pos.size();j++)
	    {
	        ans+=(pos[j]*(pos[j]+1))/2;
	    }
	    for(int j=0;j<neg.size();j++)
	    {
	        ans-=(neg[j]*(neg[j]+1))/2;
	    }
	    cout << ans << el;
	}
	return 0;
}