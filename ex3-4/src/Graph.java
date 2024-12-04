import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;
import java.util.Collection;

public class Graph<V, L> implements AbstractGraph<V, L> {
    private boolean directed; 
    private boolean labelled; 
    private HashMap<V, LinkedList<Edge<V, L>>> adjacentEdge; // Stores adjacency lists for nodes

    public Graph(boolean directed, boolean labelled) {
        this.directed = directed; 
        this.labelled = labelled;
        this.adjacentEdge = new HashMap<>(); // Initializes an empty adjacency list
    }

    @Override
    public boolean isDirected() {
        return directed; 
    }

    @Override
    public boolean isLabelled() {
        return labelled;
    }

    @Override
    public boolean addNode(V a) {
        if (containsNode(a)) return false; // Node already exists
        
        adjacentEdge.put(a, new LinkedList<>()); // Adds a new node with an empty adjacency list
        return true;
    }

    @Override
    public boolean addEdge(V a, V b, L l) {
        if (containsEdge(a, b)) return false; // Edge already exists

        if (!labelled) l = null; // If the graph is not labelled, ignore the provided label

        // Add edge from node `a` to node `b`
        adjacentEdge.get(a).add(new Edge<>(a, b, l));
        if (!directed) {
            // If the graph is undirected, also add the reverse edge
            adjacentEdge.get(b).add(new Edge<>(b, a, l));
        }
        return true;
    }

    @Override
    public boolean containsNode(V a) {
        return adjacentEdge.containsKey(a);
    }

    @Override
    public boolean containsEdge(V a, V b) {
        return findEdge(a, b) != null; 
    }

    @Override
    public boolean removeNode(V a) {
        if (!containsNode(a)) return false; // Node doesn't exist

        // Remove all edges connected to the node
        for (V node : getNodes()) {
            removeEdge(node, a);
        }
        adjacentEdge.remove(a); // Remove the node itself
        return true;
    }

    @Override
    public boolean removeEdge(V a, V b) {
        if (!containsEdge(a, b)) return false; // Edge doesn't exist

        // Remove the edge from node `a` to node `b`
        Edge<V, L> edge = findEdge(a, b);
        adjacentEdge.get(a).remove(edge);

        if (!directed) {
            // If the graph is undirected, also remove the reverse edge
            Edge<V, L> revEdge = findEdge(b, a);
            adjacentEdge.get(b).remove(revEdge);
        }
        return true;
    }

    @Override
    public int numNodes() {
        return adjacentEdge.size();
    }

    @Override
    public int numEdges() {
        int edgeCount = 0;
        for (V neighbourNode : adjacentEdge.keySet()) {
            edgeCount += getNeighbours(neighbourNode).size(); // Count edges for each node
        }
        return directed ? edgeCount : (edgeCount / 2);
    }

    @Override
    public Collection<V> getNodes() {
        return new HashSet<>(adjacentEdge.keySet()); // Return a collection of all nodes in the graph
    }

    @Override
    public HashSet<Edge<V, L>> getEdges() {
        HashSet<Edge<V, L>> edges = new HashSet<>();
        for (V node : adjacentEdge.keySet()) {
            edges.addAll(adjacentEdge.get(node)); // Directly add all edges of the node
        }
        return edges;
    }

    @Override
    public Collection<V> getNeighbours(V a) {
        LinkedList<V> neighbours = new LinkedList<>();
        if (containsNode(a)) {
            for (Edge<V, L> edge : adjacentEdge.get(a)) {
                neighbours.add(edge.getEnd()); // Add the endpoint of each edge
            }
        }
        return neighbours; // Return the list of neighbours for node `a`
    }

    @Override
    public L getLabel(V a, V b) {
        Edge<V, L> edge = findEdge(a, b);
        return (edge != null) ? edge.getLabel() : null;
    }

    // Added helper method to find an edge between two nodes
    private Edge<V, L> findEdge(V a, V b) {
        if (containsNode(a)) {
            for (Edge<V, L> edge : adjacentEdge.get(a)) {
                if (edge.getEnd().equals(b)) {
                    return edge; 
                }
            }
        }
        return null; 
    }
}