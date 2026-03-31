#include <iostream>
#include <algorithm>

using namespace std;

bool is_smaller(string ans, string compare){
    if(ans < compare){
        for(int i = 0; i < ans.length(); i++){
            if(ans[i] < compare[i]){
                return false;
            }
        }
        if(ans[0] < compare[ans.length()]){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }
}

int main(){
    int t, n;
    cin >> t;
    string str, ans;
    for (int i = 0; i < t; i++){
        cin >> n;
        ans = "";
        
        cin >> ans;
        for(int j = 0; j < n-1; j++){
            cin >> str;
            if(is_smaller(ans, str)){
                ans = str + ans;
            }
            else{
                ans = ans + str;
            }
        }
        cout << ans << endl;

        
    }
}