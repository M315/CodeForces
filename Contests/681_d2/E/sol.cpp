#include <bits/stdc++.h>

using namespace std;

int sum(int l, int r, vector<int>& a){
	int sum = 0;

	for(int i = l - 1; i < r; i++)
		sum += a[i];

	return sum;
}

void next_permutation(vector<int>& a){
	int min = 0 > a.size() - 16 ? 0: a.size() - 16;
	int i = a.size() - 1;
	while(i > min && a[i - 1] >= a[i])
		i--;

	if(i == 0)
		return;

	int j = a.size() - 1;
	while(a[j] <= a[i - 1])
		j--;

	int temp = a[i - 1];
	a[i - 1] = a[j];
	a[j] = temp;

	j = a.size() - 1;
	while(i < j){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}

void solve() {
	int n, k, Q;
	cin >> n;

	vector<int> a (n);
	for(k = 0; k < n; k++)
		a[k] = k + 1;

	cin >> Q;

	for(k = 0; k < Q; k++){
		int q, l, r, x;

		cin >> q;
		if(q == 1){
			cin >> l >> r;
			cout << sum(l, r, a) << '\n';
		}else{
			cin >> x;
			for(int c = 0; c < x; c++)
				next_permutation(a);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    /*int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }*/
	solve();
}
