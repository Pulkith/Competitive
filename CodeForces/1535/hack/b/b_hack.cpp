   


    #include <bits/stdc++.h>
    #define _hs Hack::start();
    #define _hv(n) Hack::verify(n);
    namespace Hack {
        inline namespace IO {
            void setIn(std::string s)  { (void)!freopen(s.c_str(),"r",stdin); }
            void setOut(std::string s) { (void)!freopen(s.c_str(),"w",stdout); }
        }
        const int N = 10;
        int correct[N];
        
        void read() {
            setIn("/Users/despicablemonkey/Desktop/Competitive/CodeForces/1535/hack/b/b_hack_output.txt");
            for(int i = 0; i < N; ++i)
                std::cin >> correct[i];
        }
        int test_case = 0;
        void verify(int answer) {
            if(answer != correct[test_case++])
                std::cout << "[FAILED] Test Case #" << (test_case-1) << std::endl;
        }

        void start() {
            read();
            setIn("/Users/despicablemonkey/Desktop/Competitive/CodeForces/1535/hack/b/b_hack_input.txt");
        }
    }

    #include <iostream>
    #include <bits/stdc++.h>
    #include<vector>
    #define ll long long int
    using namespace std;
    ll gcd2(ll a,ll b)
    {
        if (a == 0)
           return b;
        if (b == 0)
           return a;
      
        if (a == b)
            return a;
      
        if (a > b)
            return gcd2(a-b, b);
        return gcd2(a, b-a);
    }
    int main()
    {
        //_hs;
        ll T;
        cin>>T;

        while(T--)
        {
            int x, y;
            cin >> x >> y;
            cout << gcd2(x, y) << endl;
            continue;

            ll N;
            cin>>N;
            ll a[N];
            vector<ll> v;
            for(ll i=0;i<N;i++)
            {
                cin>>a[i];
            }
            for(ll i=0;i<N;i++)
            {
                if(a[i]%2==0)
                {
                    v.push_back(a[i]);
                }
            }
            for(ll i=0;i<N;i++)
            {
                if(a[i]%2!=0)
                {
                    v.push_back(a[i]);
                } 
            }
            ll c=0;
            for(ll i=0;i<N-1;i++)
            {
                for(ll j=i+1;j<N;j++)
                {
                    ll m,n,k;
                    m=v[i];
                    n=2*v[j];
                    k=gcd(m,n);
                    if(k>1)
                    {
                        c++;
                    }
                }
            }
            cout << c << endl;
            
        }
    }