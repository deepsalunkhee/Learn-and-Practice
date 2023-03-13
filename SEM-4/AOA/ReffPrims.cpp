#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = INT64_MAX; // Set a constant to represent infinity

int main() {
    int n, m;
    cin >> n >> m; // Read in number of nodes and edges
    vector<vector<pair<int,int>>> adj(n); // Create an adjacency list to represent the graph

    for (int i = 0; i < m; i++) { // Loop over each edge and add it to the adjacency list
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, INF), parent(n, -1); // Initialize key and parent vectors
    vector<bool> isvisited(n, false); // Initialize a vector to keep track of whether each node is in the MST or not
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Create a priority queue to store nodes ordered by their keys

    int src = 0; // Choose a source node (we can start from any node)
    key[src] = 0; // Set the key of the source node to 0
    pq.push({0, src}); // Add the source node to the priority queue

    while (!pq.empty()) { // Loop while the priority queue is not empty
        int u = pq.top().second; // Pop the node with the smallest key from the priority queue
        pq.pop();
        isvisited[u] = true; // Add the node to the MST

        for (auto it : adj[u]) { // Loop over all of its neighbors
            int v = it.first;
            int weight = it.second;
            if (!isvisited[v] && key[v] > weight) { // If the neighbor is not already in the MST and its key can be updated
                key[v] = weight; // Update the key of the neighbor
                pq.push({key[v], v}); // Add the neighbor to the priority queue with its updated key
                parent[v] = u; // Set the parent of the neighbor to be the current node
            }
        }
    }

    for (int i = 1; i < n; i++) { // Print out the edges of the MST
        cout << parent[i] << " - " << i << "\n";
    }

    return 0;
}
