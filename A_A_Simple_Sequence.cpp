#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n; 
        n+=1;
        while (n-- && n > 0){
            cout << n << " ";
        }
        cout << endl;
    }
}