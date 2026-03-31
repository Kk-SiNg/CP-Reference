#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a;
    vector <int> vect;  
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    int target = 0;
    int helper = 1;
    for(int k = 1; k <= n; k++){
        target |= vect[k-1];
        helper &= vect[k-1];
        int l = 0, r = k-1;
        while(r < n){
            int current = target;
            r++;
            if(r == n) break;
            current &= ~(vect[l]);
            cout << "l:- " << l << endl;
            cout << "current_prio:- " << current << endl;
            current |= vect[r];
            cout << "current:- " << current << endl;
            cout << "target:- " << target << endl;
            cout << "k:- " << k << endl;
            l++;
            if(current != target) break;
        }
        if(r == n) {
            cout << k << endl;
            return;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}