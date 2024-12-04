import java.util.HashSet;
import java.util.LinkedList;
import java.util.Comparator;
import java.util.Collection;
import java.util.NoSuchElementException;
import java.text.DecimalFormat;
import java.io.BufferedReader;
import java.io.FileReader;

public class Prim {
    // Adds all unvisited adjacent nodes of a given vertex to the Priority Queue
    private static <V, L extends Number> void addAdjacent(Graph<V, L> graph, PriorityQueue<Edge<V, L>> priorityQueue, V vertex, HashSet<V> visitedNodes) {
        for (V neighbour : graph.getNeighbours(vertex)) { 
            if (!visitedNodes.contains(neighbour)) { 
                priorityQueue.push(new Edge<>(vertex, neighbour, graph.getLabel(vertex, neighbour))); // Add the edge to the priority queue
            }
        }
    }

    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        // Priority queue for edges, sorted by edge weight (label)
        PriorityQueue<Edge<V, L>> priorityQueue = new PriorityQueue<>(Comparator.comparing(edge -> edge.getLabel().doubleValue()));
        
        HashSet<V> visitedNodes = new HashSet<>();
        LinkedList<Edge<V, L>> minimumSpanningForest = new LinkedList<>(); // Stores the resulting edges of the MSF

        for (V startNode : graph.getNodes()) { // Loop over all nodes to handle disconnected graphs
            if (!visitedNodes.contains(startNode)) { // Start a new MSF for an unvisited connected node
                visitedNodes.add(startNode);
                addAdjacent(graph, priorityQueue, startNode, visitedNodes); // Add edges from this node to the Priority Queue

                // Process the Priority Queue to construct the MSF for the nodes
                while (!priorityQueue.empty()) {
                    Edge<V, L> edge = priorityQueue.top(); // Get the smallest edge
                    priorityQueue.pop(); // Remove it from the queue
                    V nextNode = edge.getEnd();

                    if (!visitedNodes.contains(nextNode)) { // Only add edges leading to unvisited nodes
                        visitedNodes.add(nextNode); 
                        minimumSpanningForest.add(edge); // Add the edge to the MSF
                        addAdjacent(graph, priorityQueue, nextNode, visitedNodes); // Add its neighbors to the Priority Queue
                    }
                }
            }
        }

        return minimumSpanningForest; 
    }

    // Prints the minimum spanning forest in sorted order and calculates total weight
    public static void forestToString(LinkedList<Edge<String, Double>> forest) {
        // Sort edges by weight and print them
        forest.stream().sorted(Comparator.comparing(Edge::getLabel))
            .forEach(edge -> {
                String startingEdge = edge.getStart();
                String endingEdge = edge.getEnd();

                // Ensure the edges are printed in correct order
                if (startingEdge.compareTo(endingEdge) > 0) {
                    String tmpEdge = startingEdge;
                    startingEdge = endingEdge;
                    endingEdge = tmpEdge;
                }

                // Print the edge with formatted weight
                System.out.println(startingEdge + "," + endingEdge + "," + String.format("%.6f", edge.getLabel()));
            });

        // Calculate the total weight of the forest and print it
        double totalWeight = forest.stream().mapToDouble(Edge::getLabel).sum();
        System.out.println("Total edges: " + forest.size());
        System.out.println("Total edges' weight: " + new DecimalFormat("#.######").format(totalWeight / 1000) + " km");
    }

    public static void main(String[] args) {
        if (args.length < 1) { 
            System.err.println("Specify the file path as an input argument.");
            System.exit(1);
        }

        Graph<String, Double> graph = new Graph<>(false, true); 
        try (BufferedReader reader = new BufferedReader(new FileReader(args[0]))) {
            String line;
            while ((line = reader.readLine()) != null) { 
                String[] data = line.split(","); // Split the line into components
                String place1 = data[0];
                String place2 = data[1];
                double distance = Double.parseDouble(data[2]);

                // Add nodes and edges to the graph
                graph.addNode(place1);
                graph.addNode(place2);
                graph.addEdge(place1, place2, distance);
            }

            // Compute the minimum spanning forest and print the results
            @SuppressWarnings("unchecked")
            LinkedList<Edge<String, Double>> minimumSpanningForest = 
                (LinkedList<Edge<String, Double>>) minimumSpanningForest(graph);

            forestToString(minimumSpanningForest);
            System.out.println("Nodes number: " + graph.numNodes()); 

        } catch (Exception e) {
            System.err.println("File read error: " + e.getMessage());
        }
    }
}