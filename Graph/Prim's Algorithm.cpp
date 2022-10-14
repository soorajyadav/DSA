#include <bits/stdc++.h>
using namespace std;

const int n=5,e=7;
vector<pair<int,int>> vt[n];

int par[n];
int key[n]; // nearest processed node weight
bool isDone[n];
int sum;

priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
// pair<key,vertex_no:>

void Prims(int s){
    key[0]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int processing_node = pq.top().second;
        pq.pop();
        isDone[processing_node]=true;
        
        for(auto it:vt[processing_node]){
            int v = it.first;
            int weight = it.second;
            
            if (isDone[v] == false && weight < key[v]) {
                par[v] = processing_node;
		        key[v] = weight; 
                pq.push({key[v], v}); 
                
            }
            
        }
       
    }
}

int main(){

    for(int i=0;i<n;i++){
        //par[i]=-1;
        key[i]=INT_MAX;
        isDone[i]=false;
    }
	
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vt[u].push_back({v,w});
        vt[v].push_back({u,w});
    }
   
    sum=0;
    
    Prims(0);
    
    for (int i = 1; i <n; i++) {
        for(auto x:vt[i])
            if(x.first == par[i]) sum+=x.second;
            
        cout << par[i] << " - " << i <<" \n"; 
    } 
    
    
    cout<<"mst sum: "<<sum;
    
	return 0;
}