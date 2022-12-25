	// TC: ElogV

//Pq implementation will take a little more space than the set. (v^2) as opposed to (v)
//so, in case of pq, the heap will have atmost v^2 vertices. how? assume 4 nodes. A  B C D
// A relaxes (B,C,D) and B relaxes (A,C,D) and C relaxes (A,B,D) and D relaxes (A,B,C). Then each node is being relaxes (V-1) times. ===> slight exaggeration
//therefore, at max, the size of the heap could be v^2. In the set, it's just V
/*
pseudocode for pq:

while(!pq.empty())                      -> V times
{
	dist, node = pq.top();
	pq.pop();			-> Log(heap_size)
	for(all nodes adjacent){        -> (V-1) at max
		if(cond satisfied)
			pq.push(adj node) -> Log(heap_size)
	}
}

tc: V*(log(v^2) + (V-1)*log(v^2))   where v^2= heapsize
=> V*log(v^2) + V^2*log(v^2) - V*log(v^2)
=> V^2log(v^2)
=> 2*V^2(logv)
=> v^2 * log(v)
=> 2E * log (v) => e*log(v) since 2E = V^2

Similarly, for a set:

while(!s.empty())                      -> V times
{
	dist, node = s.begin();         
	s.erase();			-> Log(setSize)
	for(all nodes adjacent){        -> (V-1) at max
		if(cond satisfied)
			s.insert(adj node) -> Log(setSize)
	}
}
V*(log(setSize) + (V-1)*(log(setSize))
=> V*log(ss) + V^2(log(ss)) - V*(log(ss))
=> V^2(logss)
=> V^2*log(V)
=> 2*E*log(V)
=> E*log(V)
*/


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
