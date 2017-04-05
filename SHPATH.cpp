using namespace std;
#include <bits/stdc++.h>

vector<pair<int,int> > adjList[20000];
map<string,int> keyToCity;

int dijkstra(int source, int destination)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > Q;
    vector<int> dist(20000, INT_MAX);
    Q.push(pair<int,int>(0,source));
    dist[source] = 0;
    while(!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for(int i = 0; i < adjList[u].size(); i ++)
        {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;
            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                Q.push(pair<int,int>(dist[v],v));
            }
        }
    }
    return dist[destination];
}

int main() {
	// your code goes here
	int s;
    std::ios::sync_with_stdio(false);
    cin >> s;
	while(s--)
	{
	    int n, r;
	    cin >> n;
	    for(int i = 1; i <= n; i ++)
	    {
	        string NAME;
    	    cin >> NAME;
    	    keyToCity[NAME] = i;
    	    adjList[i].clear();
    	    int nr, cost, p;
    	    cin >> p;
    	    while(p--)
    	    {
    	        cin >> nr >> cost;
    	        adjList[i].push_back(pair<int,int>(nr,cost));
    	    }
	    }
	    cin >> r;
	    string NAME1, NAME2;
	    while(r--)
	    {
	        cin >> NAME1 >> NAME2;
	        int keyToName1 = keyToCity[NAME1], keyToName2 = keyToCity[NAME2];
	        int dist;
	        if(keyToName1 < keyToName2)
	        {
	            dist = dijkstra(keyToName1, keyToName2);
	        }
	        else
	        {
	            dist = dijkstra(keyToName2, keyToName1);
	        }
	        cout << dist << endl;
	    }
	}
	return 0;
}
