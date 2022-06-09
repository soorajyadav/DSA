#include <bits/stdc++.h>
using namespace std;

// Determine if a string is a rotated version of another string
// O(N*M)
bool is_sub_string(string s1,string s2){
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++){
            if (s2[i + j] != s1[j]) break;
        }
        if (j == M) return true;
    }
    return false;
}

int main() {

    string s1 = "triangle";
    string s2 = "angletri";
    if(s1.size()!=s2.size()) cout<<"no";
    else{
        string s=s1+s1;
        if(is_sub_string(s2,s)) cout<<"yes";
        else cout<<"no";
    }
}
