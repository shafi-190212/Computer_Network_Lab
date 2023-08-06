//
// Created by mushf on 11/1/2022.
//
#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

void printDistance(int src,vector<int>dist){
    int i=0;
    for(auto d: dist){
        printf("%c -> %c = %d\n",src+65,i+65,d);
        i++;
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    for(auto e : edges){
        printf("%c -> %c = %d\n",e[0]+65,e[1]+65,e[2]);
    }
    int src;
    //    cin>>src;
    for(int src=0;src<n;src++){
        vector<int>dist(n,INF);
        vector<int>via(n,-1);
        dist[src]= 0 ;
        via[src] = src;
        cout<<endl;
        for(int i=0;i<n-1;i++){
            for(auto e: edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                int new_dist = w+dist[u];
                if(dist[v]>new_dist) {
                    dist[v] = new_dist;
                    via[v] = u;
                }
                dist[v] = min(dist[v], w + dist[u]);
            }
        }
        printDistance(src,dist);
        cout<<"Via: ";
        for(auto d : via){
            if(d!=-1)
                printf("%c ",d+65);
            else
                printf("%d ",d);
        }
        cout<<endl;
    }



}