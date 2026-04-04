#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int x, m;
    cin >> x >> m;
    int ctr = 0;
    cout << x << " " << m << "\n";
    for(int i = 1; (i < 2*x && i <= m); i++){
        int num = x^i;
        cout << "e\n";
        if(num = 0) continue;
        if((i%num == 0) || (x%num == 0)) ctr++;
    }
    cout << ctr <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}