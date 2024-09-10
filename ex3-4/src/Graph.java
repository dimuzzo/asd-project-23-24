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
        if (containsNode(a)) {
            return false;
        }
        else{
            adjacentArch.put(a, new HashMap<>());
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
            this.adjacentArch.get(a).add(new Edge<>(a, b, l));
        }
        else{
            this.adjacentArch.get(a).add(new Edge<>(a, b, l));
            this.adjacentArch.get(b).add(new Edge<>(b, a, l));
        }
        return true;
    }

    @Override
    public boolean containsNode(V a){
        return this.adjacentArch.containsKey(a);
    }

    @Override
    public boolean containsEdge(V a, V b){
        return findEdge(a, b) != null;
    }

    @Override
    public boolean removeNode(V a){
        if(!contains(a)){
            return false;
        }
        else{
            for(V node : getNodes()){
                removeEdge(node, a);
            }
            this.adjacentArch.remove(a);
            return true;
        }
    }

    @Override
    public boolean removeEdge(V a, V b){
        if(!containsEdge(a, b)){
            return false;
        }
        else{
            Edge<V, L> edge = findEdge(a, b);
            Edge<V, L> revEdge = findEdge(b, a);
            if(directed){
                this.adjacentArch.get(a).remove(edge);
            }
            else{
                this.adjacentArch.get(a).remove(edge);
                this.adjacentArch.get(b).remove(revEdge);
            }
            return true;
        }
    }

    @Override
    public int numNodes(){
        return this.adjacentArch.size();
    }

    @Override
    public int numEdges(){
        int edgeCount = 0;
        for(V key : this.adjacentArch.keySet()){
            edgeCount += getNeighbours(key).size();
        }
        if(!directed){
            edgeCount /= 2;
        }
        return edgeCount;
    }

    @Override
    public Collection<V> getNodes(){
        return this.adjacentArch.keySet();
    }

    @Override
    public Collection<? extends AbstractEdge<V, L>> getEdges(){
        HashSet<Edge<V, L>> edges = new HashSet<>();
        for(List<Edge<V, L>> edgeList : this.adjacentArch.values()){
            edges.add(edgeList);
        }
        return edges;
    }

    @Override
    public Collection<V> getNeighbours(V a){
        if(!containsNode(a)){
            return new LinkedList<>();
        }
        LinkedList<V> neighbours = new LinkedList<>();
        for(Edge<V, L> edge : this.adjacentArch.get(a)){
            neighbours.add(edge.getEnd());
        }
        return neighbours;
    }

    @Override
    public L getLabel(V a, V b){
        Edge<V, L> edge = findEdge(a, b);
        if(edge = null){
            return null;
        }
        return edge.getLabel();
    }

    private Edge<V, L> findEdge(V a, V b){
        if(containsNode(a) && containsNode(b)){
            for(Edge<V, L> edge : this.adjacentArch.get(a)){
                if(edge.getEnd().equals(b)){
                    return edge;
                }
            }
        }
        return null;
    }

}