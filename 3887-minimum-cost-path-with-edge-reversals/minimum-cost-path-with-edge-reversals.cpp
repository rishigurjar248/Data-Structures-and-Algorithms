class Solution {
public:
    vector<list<pair<int,int>>>graph;
    int f(int src,int dest,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        pq.push({0,src});
        dist[src] = 0;
        unordered_set<int>vis;
        while(!pq.empty()){
            auto curr = pq.top();
            int d = curr.first;
            int node = curr.second;
            pq.pop();
            if(node==dest) return d;
            if(vis.count(node)) continue;
            vis.insert(node);
            for(auto ngh:graph[node]){
                if(dist[ngh.first]>d+ngh.second){
                    pq.push({d+ngh.second,ngh.first});
                    dist[ngh.first] = d+ngh.second;
                }
            }
        }
        return -1;
    }
    int minCost(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        int x = f(0,n-1,n);
        return x;
        
    }
};
