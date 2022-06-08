#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];
bool vis[n];

void dfs(int vertex){

    //1. code when entered child/vertex
    cout<<vertex<<"\n"; // printing node at entry point 
    vis[vertex]=true; //making visited for current node

    for(pair<int,int> child : graph[vertex]){
        //2.x. code before entring to each child
        cout<<"parent "<<vertex<<", child "<<child.first<<"\n";
        if(vis[child.first]) continue;

        // visiting child
        dfs(child.first);

        //3.x. code after exiting from each child
    }

    //4. code while backtracking

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
    for(int i=1;i<=v;i++){
        if(vis[i]!=true) {
            dfs(i);// this loop will make sure to enter every connected component
            cout<<"\n";
        }
    }
    



}