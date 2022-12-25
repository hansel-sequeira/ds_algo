public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min-heap
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            auto it= pq.top();
            int distance = it.first; int u = it.second;
            pq.pop();
            for(auto it1: adj[u]){
                int v = it1[0]; int w = it1[1];
                if(dist[v] > distance + w){
                    dist[v] = distance+w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
