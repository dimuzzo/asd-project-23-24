import java.util.*;
import java.text.DecimalFormat;
import java.io.*;

public class Prim{
    private static <V, L extends Number> void addAdjacent(Graph<V, L> graph, PriorityQueue<Edge<V, L>> priorityQueue, V vertex, HashSet<V> visitedNodes){
        for(V neighbour : graph.getNeighbours(vertex)){
            if(!visitedNodes.contains(neighbour)){
                L label = graph.getLabel(vertex, neighbour);
                priorityQueue.push(new Edge<>(vertex, neighbour, label));
            }
        }
    }

    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        // calcola la minima foresta ricoprente con l'algoritmo di Prim
        // restituisce la collezione degli archi che formano la foresta
        PriorityQueue<Edge<V, L>> priorityQueue = new PriorityQueue<>(Comparator.comparing(edge -> edge.getLabel().doubleValue()));
        HashSet<V> visitedNodes = new HashSet<>();
        LinkedList<Edge<V, L>> minimumSpanningForest = new LinkedList<>();

        for(V startNode : graph.getNodes()){
            if(!visitedNodes.contains(startNode)){
                visitedNodes.add(startNode);
                addAdjacent(graph, priorityQueue, startNode, visitedNodes);
                LinkedList<Edge<V, L>> minTree = new LinkedList<>();

            while (!priorityQueue.empty()) {
                Edge<V, L> edge = priorityQueue.top();
                priorityQueue.pop();
                V nextNode = edge.getEnd();
                
                if(!visitedNodes.contains(nextNode)){
                    visitedNodes.add(nextNode);
                    minTree.add(edge);
                    addAdjacent(graph, priorityQueue, nextNode, visitedNodes);
                }
            }

            minimumSpanningForest.addAll(minTree);
          }
      } 

      return minimumSpanningForest;
    }

    public static void forestToString(LinkedList<Edge<String, Double>> forest) {
        forest.stream().sorted(Comparator.comparing(Edge::getLabel)).forEach(edge ->
        {
            String startingEdge = edge.getStart();
            String endingEdge = edge.getEnd();
            
            if(startingEdge.compareTo(endingEdge) > 0){
                String tmpEdge = startingEdge;
                startingEdge = endingEdge;
                endingEdge = tmpEdge;
            }

            System.out.println(startingEdge + "," + endingEdge + "," + String.format("%.6f", edge.getLabel()));
        });
        
        double totalWeight = forest.stream().mapToDouble(Edge::getLabel).sum();

        DecimalFormat formatter = new DecimalFormat("#.######");
        System.out.println("Total edges: " + forest.size());
        System.out.println("Total edges' weight: " + formatter.format(totalWeight / 1000) + " km");
    }
      
    public static void main(String[] args) {
        // leggi i dati CSV del grafo dal percorso in args[1]
        // calcola la minima foresta ricoprente con minimumSpanningForest
        // scrivi su standard output solo la descrizione della foresta calcolata come CSV con formato analogo a quello in input
        // su standard error si possono scrivere ulteriori informazioni, come il numero di nodi e archi nella foresta calcolata,
        // o il peso totale della foresta
        if(args.length < 1){
            System.err.println("Specificare il percorso del file come argomento in input.");
            System.exit(1);
        }

        Graph<String, Double> graph = new Graph<>(false, true);
        try(BufferedReader reader = new BufferedReader(new FileReader(args[0]))){
            String line;
            while((line = reader.readLine()) != null){
                String[] data = line.split(",");
                String place1 = data[0];
                String place2 = data[1];
                double distance = Double.parseDouble(data[2]);
                
                graph.addNode(place1);
                graph.addNode(place2);
                graph.addEdge(place1, place2, distance);
            }

            @SuppressWarnings("unchecked")
            LinkedList<Edge<String, Double>> minimumSpanningForest = (LinkedList<Edge<String, Double>>) minimumSpanningForest(graph);
            forestToString(minimumSpanningForest);
            System.out.println("Nodes number: " + graph.numNodes());
        }
        
        catch(Exception e){
            System.err.println("Errore del file in lettura: " + e.getMessage());
        }
    }  
}