#include <bits/stdc++.h>

using namespace std;
template <class T>
bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
double vals[1005], prefix[1005], mult[1005];
void set_probs(int n) {
    long double cdf = 0, b = 0, p = 0.5;
    for(int k = 0; k <= n; ++k) {
        if(k > 0) b += +log(n-k+1) - log(k);
        long double log_pmf_k = b + k * log(p) + (n-k) * log(1-p);
        vals[k+1] = exp(log_pmf_k);
    }
}
int cc[1005];
double formula(int K, int N, bool skim) {
    double last = mult[N];
    int lV = N / 2;
    int lastchange = 0;
    int curfromlastchange = 0;
    for(int D = 2; D <= K; ++D) {
        ++curfromlastchange;
        double top = 0;
        top = prefix[lV-1] * last + (mult[N] - mult[lV-1]);
        bool changed = false;
        while(lV < N && cmax(top, prefix[lV] * last + (mult[N] - mult[lV])))  {
            ++lV;
            changed = 1;
        }
        last = top;
        if(changed) {
            lastchange = curfromlastchange;
            if(skim && K > 500000000 && D > K / 10 * 6) lastchange *= 1.25; 
            lastchange--;
            lastchange = min(lastchange, K - D) ;
            curfromlastchange = lastchange;
            D += lastchange;
            
            double a = prefix[lV-1];
            double b = (mult[N] - mult[lV-1]);
            double p = pow(a, lastchange);
            last = p * last + b *( p - 1) / (a-1);
        }
    }
    if(N != 2 && N != 4) return last + 2;
    return last;
}

int main(){
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(18);
    int N, K;
    cin >> N >> K;
    set_probs(N - 1);
    for(int i = 1; i <= N; ++i){
        prefix[i] = prefix[i-1] + vals[i];
        mult[i] = vals[i] * i + mult[i-1];
    }
    cout << formula(K, N, 0) << '\n';
}

