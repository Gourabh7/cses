#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    char prev  = str[0];
    int cnt = 1;
    int ans  = 1;
    int n = str.size();
    for(int i = 1;i<n;i++){
        if(prev==str[i]){
            cnt++;
            ans = max(ans,cnt);
        }else{
            cnt = 1;
        }
        prev = str[i];
    }
    cout<<ans<<endl;
}