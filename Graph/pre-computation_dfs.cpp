#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];
bool vis[n];
int subtree_sum[n];
int even_count_in_subtree[n];

int dfs(int vertex){

    //1. code when entered child/vertex
     
    vis[vertex]=true; //making visited for current node
    int sum=vertex;

    if(vertex % 2 == 0) even_count_in_subtree[vertex] = 1;

    for(pair<int,int> child : graph[vertex]){
        //2.x. code before entring to each child
        
        if(vis[child.first]) continue;

        // visiting child
        sum+=dfs(child.first);
        even_count_in_subtree[vertex] += even_count_in_subtree[child.first];

        //3.x. code after exiting from each child
    }

    subtree_sum[vertex]=sum;

    //4. code while backtracking
    return sum;

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
          
        }
    }
    for(int i=1;i<=v;i++){
        cout<<subtree_sum[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<<even_count_in_subtree[i]<<" ";
    }
    



}