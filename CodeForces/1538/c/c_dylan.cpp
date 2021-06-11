	#include<bits/stdc++.h>
    using namespace std;
    int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
            int N, low, high;
            cin >> N >> low >> high;
            vector<int> arr(N);
            for (int i = 0; i < N; i++) {
                cin >> arr[i];
            }
            sort(arr.begin(), arr.end());
            int l = N, r = N - 1;
            long long res = 0;
            for (int i = 0; i < N; i++) {
                while (r >= 0 && arr[i] + arr[r] > high) {
                    r--;
                }
                while (l > 0 && arr[i] + arr[l - 1] >= low) {
                    l--;
                }
                res += max(r - l + 1, 0);
                if (arr[i] * 2 >= low && arr[i] * 2 <= high) {
                    res--;
                }
            }
            cout << res / 2 << endl;
        }
    }