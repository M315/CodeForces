#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	bool possible = false;
	
	cin >> n;

	vector<int> a(n);

	for(int& x : a){
		cin >> x;
		x--;
	}

	set<int> used;

	for(int i = 0; i < n; i++){
		if(used.count(a[i])){
			possible = true;
			break;
		}else{
			used.insert(a[i]);
		}
	}

	if(possible){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
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
