//tc: e*log(v)
//Using a pq:
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



//Using a set:

public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        set<pair<int,int>> s;
        s.insert({0, S});
        while(!s.empty()){
            auto pair = *(s.begin());
            s.erase(pair);
            int distance = pair.first; int u = pair.second;
            for(auto it: adj[u]){
                int v = it[0]; int wt = it[1];
                if(dist[v] > distance + wt){
                    if(dist[v] != INT_MAX)
                        s.erase({dist[v], v});
                    dist[v] = distance + wt;
                    s.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
