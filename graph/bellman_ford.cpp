#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct edge{
    int source, dest, weight;
};

void bellman_ford(vector<edge>& graph, vector<int>& distance, vector<int>& parent, int start){
    int i, v=distance.size(), new_dist;
    bool updated;
    distance[start]=0;
    for(i=1;i<=v;i++){
        updated=0;
        for(auto e : graph){
            if(distance[e.source]==INT_MAX)
                continue;
            new_dist= distance[e.source] + e.weight;
            if(new_dist< distance[e.dest]){
                updated=1;
                distance[e.dest]= new_dist;
                parent[e.dest]= e.source;
                if(i==v){
                    cout<< "Negative Cycle Exists\n";
                    return;
                }
            }
        }
        if(updated==0)
            return;
    }
}


int main(){
    int v, e, a, b, w, i, start;
    cin>> v>> e;
    vector<edge> graph(e);
    vector<int> parent(v,-1);
    vector<int> distance(v,INT_MAX);
    for(i=0;i<e;i++){
        cin>> a>> b>> w;
        graph.push_back({a,b,w});
    }
    cout<< "Enter start node: ";
    cin>> start;
    bellman_ford(graph, distance, parent, start);
    for(i=0;i<v;i++){
        cout<< i<< " --> "<< distance[i]<< "\tparent: "<< parent[i]<<  endl;
    }
    return 0;
}

/*

4
4
0 1 5
1 2 -2
0 2 10
2 3 -3

*/