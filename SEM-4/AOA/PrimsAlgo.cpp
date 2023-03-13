#include<iostream>
#include<vector>
using namespace std;

const int INF = INT32_MAX; // Set a constant to represent infinity

// Adds an undirected edge between nodes u and v with weight w to the adjacency list
void addEdge(vector<vector<pair<int,int>>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

// Finds the minimum weight edge to connect a node to the MST so far
int findMinKey(int n, vector<int>& key, vector<bool>& Visited) {
    int minKey = INF, minNode = -1;
    for (int i = 0; i < n; i++) {
        if (!Visited[i] && key[i] < minKey) {
            minKey = key[i];
            minNode = i;
        }
    }
    return minNode;
}

// Builds the MST and returns a vector containing the parent of each node in the MST
vector<int> primMST(vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> key(n, INF), parent(n, -1);
    vector<bool> Visited(n, false);

    int src = 0;
    key[src] = 0;

    for (int i = 0; i < n-1; i++) {
        int u = findMinKey(n, key, Visited);
        Visited[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!Visited[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    return parent;
}

// Prints the MST as a series of edges
void printMST(vector<int>& parent) {
    for (int i = 1; i < parent.size(); i++) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    vector<int> parent = primMST(adj);

    printMST(parent);

    return 0;
}
