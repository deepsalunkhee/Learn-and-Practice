# Install and load the igraph package
install.packages("igraph")
library(igraph)

# Step 1: Create a Network (Graph) from an Edge List
# You can replace this with your actual data
edge_list <- c("Alice", "Bob",
               "Bob", "Charlie",
               "Alice", "David",
               "David", "Eve",
               "Eve", "Frank",
               "Charlie", "Frank")

# Create the graph from the edge list
g <- graph(edges = edge_list, directed = FALSE)

# Assign labels to the vertices (optional)
V(g)$label <- V(g)$name

# Step 2: Visualize the Network
# Basic plot
plot(g, vertex.size = 30, vertex.label.cex = 0.8)

# Improved visualization with a layout
plot(g, layout = layout_with_fr, vertex.size = 30, vertex.label.cex = 0.8)

# Step 3: Calculate Centrality Measures
# Degree Centrality
degree_centrality <- degree(g)
print("Degree Centrality:")
print(degree_centrality)

# Betweenness Centrality
betweenness_centrality <- betweenness(g, normalized = TRUE)
print("Betweenness Centrality:")
print(betweenness_centrality)

# Closeness Centrality
closeness_centrality <- closeness(g, normalized = TRUE)
print("Closeness Centrality:")
print(closeness_centrality)

# Step 4: Analyze Network Properties
# Network Density
network_density <- edge_density(g)
print("Network Density:")
print(network_density)

# Network Diameter
network_diameter <- diameter(g)
print("Network Diameter:")
print(network_diameter)

# Clustering Coefficient
avg_clustering_coef <- transitivity(g, type = "average")
print("Average Clustering Coefficient:")
print(avg_clustering_coef)

# Step 5: Detect Communities in the Network
# Apply the edge betweenness community detection algorithm
communities <- cluster_edge_betweenness(g)

# Print community membership for each node
membership <- membership(communities)
print("Community Membership:")
print(membership)

# Plot the communities with different colors
plot(communities, g, vertex.size = 30, vertex.label.cex = 0.8)

# Step 6: Additional Analysis
# Shortest Paths
shortest_path <- shortest_paths(g, from = "Alice", to = "Frank")
print("Shortest Path from Alice to Frank:")
print(shortest_path$vpath)

# Assortativity (Degree Assortativity)
assortativity_degree <- assortativity_degree(g)
print("Degree Assortativity:")
print(assortativity_degree)

# Step 7: Save and Export Results
# Create a data frame of centrality measures and community membership
centrality_measures <- data.frame(
  Node = V(g)$name,
  Degree = degree_centrality,
  Betweenness = betweenness_centrality,
  Closeness = closeness_centrality,
  Community = membership
)

# Save the data frame to a CSV file
write.csv(centrality_measures, "centrality_measures.csv", row.names = FALSE)



