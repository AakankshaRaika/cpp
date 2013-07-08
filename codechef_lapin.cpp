#include<iostream>
using namespace std;

void ini(int L[26],int R[26]){
    for(int i=0;i<26;i++)
        L[i] = R[i] = 0;
}

bool equals(int L[26],int R[26]){
    for(int i=0;i<26;i++){
        if(L[i]!=R[i])
            return false;
    }
    return true;
}

int main(){
    int t,l,L[26],R[26];
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        ini(L,R);
        if(s.size()%2==0){
            l = s.size()>>1;
            l-=1;
            for(int i=0;i<=l;i++)
                L[s[i]-'a']++;
            for(int i=l+1;i<s.size();i++)
                R[s[i]-'a']++;
        }else{
            l = s.size()>>1;
            for(int i=0;i<l;i++)
                L[s[i]-'a']++;
            for(int i=l+1;i<s.size();i++)
                R[s[i]-'a']++;
        }
        if(equals(L,R))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
