import java.util.*;
import java.util.Collection;

public class Graph<V, L> implements AbstractGraph<V, L> {
    private boolean directed;
    private boolean labelled;
    private HashMap<V, LinkedList<Edge<V, L>>> adjacentArch;

    public Graph(boolean directed, boolean labelled) {
        this.directed = directed;
        this.labelled = labelled;
        this.adjacentArch = new HashMap<>();
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
        if (adjacencyList.containsNode(a)) {
            return false;
        }
        else{
            adjacenctArch.put(a, new HashMap<>());
            return true;
        }
    }

    @Override
    public boolean addEdge(V a, V b, L l){
        if(containsEdge(a, b)){
            return false;
        }
        if(!labelled){
            l = null;
        }
        if(directed){
            getNeighbours(a).add(new Edge<>(a, b, l));
        }
        else{
            getNeighbours(a).add(new Edge<>(a, b, l));
            getNeighbours(b).add(new Edge<>(b, a, l));
        }
        return true;
    }

    @Override
    public boolean containsNode(V a){
        return adjacentArch.containsKey(a);
    }

    @Override
    public boolean containsEdge(V a, V b){
        return findEdge(a, b) != null;
    }

    @Override
    public boolean removeNode(V a){

    }

    @Override
    public boolean removeEdge(V a, V b){
        
    }

}