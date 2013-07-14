#include<iostream>
using namespace std;
string revers(string txt){
    string s1("");
    int len = 0;
    for(int i = txt.size()-1;i>=0;i--){
        len++;
        if(txt[i]==' '){
            s1 = s1 + txt.substr(i+1,len-1) + " ";
            len = 0;
        }else if(i==0){
            s1 = s1 + txt.substr(i,len);
        }
    }
    return s1;
}

int main(){
    string s = "My name is something";
    string rev = revers(s);
    cout<<s<<"\n"<<rev;
}
