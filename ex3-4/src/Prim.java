import java.util.*;
import java.text.*;
import java.io.*;

public class Prim{
    private static <V, L extends Number> void addAdjacent(Graph<V, L> graph, PriorityQueue<Edge<V, L>> priorityQueue, V vertix, HashSet<V> visitedNodes){
        for(V next : graph.getNeighbours(vertix)){
            if(!visitedNodes.contains(next)){
                L label = graph.getLabel(vertix, next);
                priorityQueue.push(new Edge<>(vertix, next, label));
            }
        }
    }

    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        // calcola la minima foresta ricoprente con l'algoritmo di Prim
        // restituisce la collezione degli archi che formano la foresta
        PriorityQueue<Edge<V, L>> priorityQueue = new PriorityQueue<>(Comparator.comparing(edge -> edge.getLabel().doubleValue()));
        HashSet<V> visitedNodes = new HashSet<>();
        HashSet<V> everyNode = new HashSet<>(graph.getNodes());
        LinkedList<Edge<V, L>> minimumSpanningForest = new LinkedList<>();

        while(visitedNodes.size() != everyNode.size()){
            LinkedList<Edge<V, L>> minForest = new LinkedList<>();
            V begin = everyNode.stream().filter(v -> !everyNode.contains(v)).findFirst().orElse(null);

            if(begin == null) break;

            visitedNodes.add(begin);
            addAdjacent(graph, priorityQueue, begin, visitedNodes);

            while (!priorityQueue.empty()) {
                Edge<V, L> currentEdge = priorityQueue.top();
                priorityQueue.pop();
                V node = currentEdge.getEnd();
                
                if(!visitedNodes.contains(node)){
                    minForest.add(currentEdge);
                    visitedNodes.add(node);
                    everyNode.remove(node);
                    addAdjacent(graph, priorityQueue, node, visitedNodes);
                }
            }

            minimumSpanningForest.addAll(minForest);
        }

        return minimumSpanningForest;
    }

    public static void forestToString(LinkedList<Edge<String, Double>> forest) {
        forest.sort(Comparator.comparing(Edge::getLabel));
        Double weightEdges = 0.0;
        for(Edge<String, Double> edge : forest){
            String start = edge.getStart();
            String end = edge.getEnd();
            if(start.compareTo(end) > 0){
                // Si effettua l'ordine alfabetico tra start ed end
                String tmp = start;
                start = end;
                end = tmp;
            }

        System.out.println(start + " ," + end + " ," + String.format("%.6f", edge.getLabel()));
        weightEdges += edge.getLabel();
        }

        DecimalFormat formatD = new DecimalFormat("#.######");
        formatD.setGroupingUsed(true);
        formatD.setGroupingSize(3);
        System.out.println("Archi totali: " + forest.size());
        System.out.println("Peso totale archi: " + formatD.format(weightEdges / 1000) + " km");
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
        String line;
        try{
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));
            while((line = reader.readLine()) != null){
                String[] row = line.split(",");
                graph.addNode(row[0]);
                graph.addNode(row[1]);
                graph.addEdge(row[0], row[1], Double.parseDouble(row[2]));
            }

            reader.close();
            @SuppressWarnings("unchecked")
            LinkedList<Edge<String, Double>> minimumSpanningForest = (LinkedList<Edge<String, Double>>) minimumSpanningForest(graph);
            forestToString(minimumSpanningForest);
            System.out.println("Numero di nodi: " + graph.numNodes());
        }
        
        catch(Exception e){
            System.err.println("Errore del file in lettura: " + e.getMessage());
        }
    }  
}