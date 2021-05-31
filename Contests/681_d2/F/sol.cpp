#include <bits/stdc++.h>

using namespace std;

int MOD = 998244353;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b_used(n, 0);
	vector<int> b(k);
	for(int& x : a){
		cin >> x;
		x--;
	}
	for(int& x : b){
		cin >> x;
		x--;
	}
	vector<int> a_where(n);
	for(int i = 0; i < n; i++){
		a_where[a[i]] = i;
	}
	for(int x : b) b_used[a_where[x]] = 1;
	set<int> exists;
	for(int i = 0; i < n; i++) exists.insert(i);
	exists.insert(-1);
	exists.insert(n);
	int ans = 1;
	for(int x : b){
		int idx = a_where[x];
		assert(b_used[idx]);
		b_used[idx] = 0;
		int l = *prev(exists.find(idx));
		int r = *next(exists.find(idx));
		int cur = 0;
		if(l >= 0 && l < n && b_used[l] == 0) cur++;
		if(r >= 0 && r < n && b_used[r] == 0) cur++;
		ans *= cur;
		ans = ((ans % MOD) + MOD) % MOD;
		exists.erase(idx);
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
