#include<iostream>
using namespace std;

string revers(string txt, int length){
    cout<<txt[length-1];
    if(length==1)
        return;
    revers(txt,length-1);
}

int main(){
    string s = "My name is something";
    revers(s,s.size());
    return 0;
}
