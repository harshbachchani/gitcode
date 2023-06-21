#include <iostream>
using namespace std;

bool chkpalindrome(string &str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    bool ans=chkpalindrome(str,++i,--j);
    return ans;
}
void msg(string str){
    if(chkpalindrome(str,0,str.length()-1)){
        cout<<"Palindromic string"<<endl;
    }else{
        cout<<"Not palindromic string"<<endl;
    }
}

int main(){
    string a="naman";
    string b="ayush";
    string c="abcba";
    cout<<"The string a is ";
    msg(a);
    cout<<"The string a is ";
    msg(b);
    cout<<"The string a is ";
    msg(c);
    return 0;
}