#include <bits/stdc++.h>
using namespace std;

bool usingsecond(const pair<int,int> &a, const pair<int,int> &b){
    return (a.first < b.first);
}

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back(make_pair(x,y));
    }

    sort(vec.begin(),vec.end(),usingsecond);
    for(int i=0;i<n;i++){
        cout<<vec[i].first<<" "<<vec[i].second<<"\n";
    }
    cout<<"\n";


}
