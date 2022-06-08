#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];
bool vis[n];


bool dfs(int vertex, int x){

    //1. code when entered vertex
    
    vis[vertex]=true; //making visited for current node
    bool wapis=false;
    for(pair<int,int> child : graph[vertex]){
        //2.x. code before entring to each child
        if( vis[child.first] && child.first==x) continue;
        if(vis[child.first]) return true;
        
        // visiting child
        wapis |= dfs(child.first,vertex);

        //3.x. code after exiting from each child
    }

    //4. code while backtracking
    return wapis;

}

int main() {
    int v,e;
    cin>>v>>e;

    //filling array of vectors (Adjacency List)
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(make_pair(v2,wt));
        graph[v2].push_back(make_pair(v1,wt));
    }
    int ccwapis=false;
    for(int i=1;i<=v;i++){
        if(vis[i]!=true) {
            ccwapis |= dfs(i,0);// this loop will make sure to enter every connected component
        }

    }
    
    if(ccwapis) cout<<"cycle";
    else cout<<"not cycle";

}