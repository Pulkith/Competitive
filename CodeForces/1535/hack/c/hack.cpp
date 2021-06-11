   


    #include <bits/stdc++.h>

    namespace Hack {
        inline namespace IO {
            void setIn(std::string s)  { (void)!freopen(s.c_str(),"r",stdin); }
            void setOut(std::string s) { (void)!freopen(s.c_str(),"w",stdout); }
        }
        const int N = 100;
        int correct[N];
        
        void read() {
            setIn("/Users/despicablemonkey/Desktop/Competitive/CodeForces/1535/hack/c/output_1.txt");
            for(int i = 0; i < N; ++i)
                std::cin >> correct[i];
        }
        int test_case = 0;
        void verify(int answer) {
            if(answer != correct[test_case++])
                std::cout << "FAILED Test Case #" << (test_case-1) << std::endl;
        }

        void start() {
            read();
            setIn("/Users/despicablemonkey/Desktop/Competitive/CodeForces/1535/hack/c/inc1.input");
        }
    }



    #define    ll                long long
    #define    dn                double
    #define    mp                make_pair
    #define    pb                push_back
    #define    se                second
    #define    fi                first
    #define    mod               1000000007
    #define    sob(v)            v.begin(),v.end()
    #define    sobr(v)           v.rbegin(),v.rend()
    #define    same(v)           v.erase(unique(v.begin(),v.end()),v.end())
    #define    fr(i,a,b)         for(int i=a;i<=b;++i)
    #define    frr(i,a,b)        for(int i=a;i>=b;--i)
    #define    pi                acos(-1.00)
    #define    inf               1e9
    #define    EPS               1e-9
    #define    sf(n)             scanf("%d",&n)
    #define    sfl(n)            scanf("%lld",&n)
    #define    check(n)          cout<<n<<"**CHECK"<<endl
    #define    ffix(x)           cout<<fixed<<setprecision(x)
    #define    fast              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define    ones(mask)        __builtin_popcount(mask)   // count set bit
    #define    onesLL(mask)      __builtin_popcountll(mask) // for long long
    #define    lzeros(mask)      __builtin_clz(mask)        // no of leading zeros
    #define    tzeros(mask)      __builtin_ctz(mask)        // no of trailing zeros
     
     
    #include<bits/stdc++.h>
    #include<string.h>
    using namespace std;
     
    typedef vector<int> vi;
    typedef map<int,int> mii;
    typedef pair<int,int> pii;
    typedef pair<int,vi> pp;
    typedef vector<pii> vpii;
    typedef pair<pair<int,int>,int> pain;
     
    int dr[8]= {-1,0,+1,0,-1,-1,+1,+1};
    int dc[8]= {0,+1,0,-1,-1,+1,-1,+1};
     
    int kx[8]= {-1,+1,+1,-1,+2,+2,-2,-2};
    int ky[8]= {+2,+2,-2,-2,-1,+1,+1,-1};
     
    const int N=100005;
     
    ll rec1(string s)
    {
       int n=s.size();
       s='*'+s;
       ll ans=0;
       ll cnt=1;
       if(s[1]=='?')s[1]='1';
       int ss[n+1];
       ss[0]=0;
       int co=0;
       fr(i,1,n)
       {
           if(s[i]=='?')
           {
               co++;
               ss[i]=co;
           }
           else
           {
               co=0;
               ss[i]=co;
           }
       }
       ll cc=0;
       fr(i,2,n)
       {
           if(s[i]=='?')
           {
               if(s[i-1]=='1')s[i]='0';
               else s[i]='1';
               cnt++;
           }
           else if(s[i]=='1' && s[i-1]=='1')
           {
               ans+=((cnt*(cnt+1))/2LL);
               if(ss[i-1])
               {
                   ll x=ss[i-1];
                   cc+=((x*(x+1))/2);
                   cnt=ss[i-1]+1;
               }
               else cnt=1;
           }
           else if(s[i]=='0' && s[i-1]=='0')
           {
               ans+=((cnt*(cnt+1))/2LL);
               if(ss[i-1])
               {
                   ll x=ss[i-1];
                   cc+=((x*(x+1))/2);
                   cnt=ss[i-1]+1;
               }
               else cnt=1;
           }
           else cnt++;
       }
       ans+=((cnt*(cnt+1))/2LL);
       ans-=cc;
       return ans;
    }
    ll rec2(string s)
    {
       int n=s.size();
       s='*'+s;
       ll ans=0;
       ll cnt=1;
       if(s[1]=='?')s[1]='0';
       int ss[n+1];
       ss[0]=0;
       int co=0;
       fr(i,1,n)
       {
           if(s[i]=='?')
           {
               co++;
               ss[i]=co;
           }
           else
           {
               co=0;
               ss[i]=co;
           }
       }
       ll cc=0;
       fr(i,2,n)
       {
           if(s[i]=='?')
           {
               if(s[i-1]=='1')s[i]='0';
               else s[i]='1';
               cnt++;
           }
           else if(s[i]=='1' && s[i-1]=='1')
           {
               ans+=((cnt*(cnt+1))/2LL);
               if(ss[i-1])
               {
                   ll x=ss[i-1];
                   cc+=((x*(x+1))/2);
                   cnt=ss[i-1]+1;
               }
               else cnt=1;
           }
           else if(s[i]=='0' && s[i-1]=='0')
           {
               ans+=((cnt*(cnt+1))/2LL);
               if(ss[i-1])
               {
                   ll x=ss[i-1];
                   cc+=((x*(x+1))/2);
                   cnt=ss[i-1]+1;
               }
               else cnt=1;
           }
           else cnt++;
       }
       ans+=((cnt*(cnt+1))/2LL);
       ans-=cc;
       return ans;
    }
    void solve()
    {
        string s;
       cin>>s;
       ll ans=max(rec1(s),rec2(s));
       Hack::verify(ans);
    }
    int main()
    {
        Hack::start();
        int t;
        cin>>t;
        while(t--)
        {
            solve();
        }
    }

